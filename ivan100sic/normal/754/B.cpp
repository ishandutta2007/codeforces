#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

string s[4];

bool tri(char a, char b, char c) {
	return a == 'x' && b == 'x' && c == 'x';
}

bool probaj() {

	for (int i=0; i<4; i++) {
		if (tri(s[i][0], s[i][1], s[i][2])) {
			return true;
		}
		if (tri(s[i][3], s[i][1], s[i][2])) {
			return true;
		}
	}

	for (int i=0; i<4; i++) {
		if (tri(s[0][i], s[1][i], s[2][i])) {
			return true;
		}
		if (tri(s[3][i], s[1][i], s[2][i])) {
			return true;
		}
	}

	if (tri(s[0][0], s[1][1], s[2][2])) {
		return true;
	}
	if (tri(s[1][0], s[2][1], s[3][2])) {
		return true;
	}
	if (tri(s[0][1], s[1][2], s[2][3])) {
		return true;
	}
	if (tri(s[1][1], s[2][2], s[3][3])) {
		return true;
	}


	if (tri(s[2][0], s[1][1], s[0][2])) {
		return true;
	}
	if (tri(s[3][0], s[2][1], s[1][2])) {
		return true;
	}
	if (tri(s[2][1], s[1][2], s[0][3])) {
		return true;
	}
	if (tri(s[3][1], s[2][2], s[1][3])) {
		return true;
	}

	return false;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	
	cin >> s[0] >> s[1] >> s[2] >> s[3];

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			char tmp = s[i][j];
			if (tmp != '.') {
				continue;
			}
			s[i][j] = 'x';
			if (probaj()) {
				cout << "YES";
				return 0;
			}
			s[i][j] = tmp;
		}
	}

	cout << "NO";

}