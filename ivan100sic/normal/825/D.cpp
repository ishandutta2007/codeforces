#include <iostream>
#include <algorithm>
using namespace std;

int sx[256], tx[256];
int dx[256];

int main() {
	string s, t;
	cin >> s >> t;
	for (char x : s) {
		sx[x]++;
	}
	for (char x : t) {
		tx[x]++;
	}
	int broj = 0;
	while (1) {
		int fali = 0;
		for (char x='a'; x<='z'; x++) {
			int f = tx[x]*broj - sx[x];
			if (f < 0) f = 0;
			fali += f;
		}
		if (fali <= sx['?']) {
			// ok
			broj++;
		} else {
			broj--;
			break;
		}
	}

	for (char& c : s) {
		if (c == '?') {
			for (char x='a'; x<='z'; x++) {
				if (tx[x]*broj > sx[x]) {
					sx[x]++;
					c = x;
					break;
				}
			}
		}
		if (c == '?') {
			c = 'a';
		}
	}

	cout << s;
}