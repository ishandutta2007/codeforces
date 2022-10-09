/*
XX.XX.....
.....OOOO.
..........
..........
..........
..........
..........
..........
..........
..........
*/

#include <iostream>
#include <algorithm>
using namespace std;

string s[10];

bool check(int x, int y) {
	s[x][y] = 'X';

	for (int i=0; i<10; i++) {
		for (int j=0; j<6; j++) {
			int br = 0;
			for (int k=0; k<5; k++) {
				if (s[i][j+k] == 'X') {
					br++;
				}
			}
			if (br == 5) return true;
		}
	}

	for (int i=0; i<6; i++) {
		for (int j=0; j<10; j++) {
			int br = 0;
			for (int k=0; k<5; k++) {
				if (s[i+k][j] == 'X') {
					br++;
				}
			}
			if (br == 5) return true;
		}
	}

	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			int br = 0;
			for (int k=0; k<5; k++) {
				if (s[i+k][j+k] == 'X') {
					br++;
				}
			}
			if (br == 5) return true;

			br = 0;
			for (int k=0; k<5; k++) {
				if (s[i+k][j+4-k] == 'X') {
					br++;
				}
			}
			if (br == 5) return true;
		}
	}

	return false;
}

int main() {
	for (int i=0; i<10; i++) {
		cin >> s[i];
	}
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			if (s[i][j] == '.') {
				if (check(i, j)) {
					cout << "YES";
					return 0;
				} else {
					s[i][j] = '.';
				}
			}
		}
	}
	cout << "NO";
}