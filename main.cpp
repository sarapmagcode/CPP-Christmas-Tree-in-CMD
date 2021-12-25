#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <iomanip>

using namespace std;

void Red(HANDLE h) {
	SetConsoleTextAttribute(h, 12);
}

void Green(HANDLE h) {
	SetConsoleTextAttribute(h, 10);
}

void Blue(HANDLE h) {
	SetConsoleTextAttribute(h, 11);
}

void White(HANDLE h) {
	SetConsoleTextAttribute(h, 15);
}

void Yellow(HANDLE h) {
	SetConsoleTextAttribute(h, 14);
}

int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int index = 0;
	while (true) {
		int width = 7;
		int height = 4;
		int temp = 1;
		int copy_width = width;
		int spaces = width * height;
		// tree structure
		for (int row = 1; row <= height; row++) {
			for (int col = temp; col <= width; col++) {
				for (int sp = spaces; sp >= col; sp--) {
					cout << " ";
				}
				for (int star = 1; star <= col; star++) {
					// different lights
					if (star % 2 == 0) {
						if (index % 3 == 0) {
							Red(h);
						} else if (index % 3 == 1) {
							Green(h);
						} else {
							Blue(h);
						}
					} else {
						White(h);
					}
					cout << "* ";
				}
				cout << endl;
			}
			temp += 3;
			width += 2;
		}
		// trunk of the tree
		for (int i = 1; i <= height; i++) {
			for (int j = spaces - 3; j >= 0; j--) {
				cout << " ";
			}
			for (int j = 1; j <= height - 1; j++) {
				cout << "* ";
			}
			cout << endl;
		}
		// greetings
		Yellow(h);
		cout << endl;
		cout << setw(height * (copy_width + 3)) << "Merry Christmas Guys!!" << endl;
		index++;
		sleep(1);
		system("cls");
	}
	return 0;
}
