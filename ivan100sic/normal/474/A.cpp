#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

string r[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

char levo(char x) {
	for (int i=0; i<3; i++) {
		for (int j=0; j<r[i].size(); j++) {
			if (r[i][j] == x) {
				return r[i][j-1];
			}
		}
	}
}

char desno(char x) {
	for (int i=0; i<3; i++) {
		for (int j=0; j<r[i].size(); j++) {
			if (r[i][j] == x) {
				return r[i][j+1];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string d, s;

	cin >> d >> s;

	auto f = d == "R" ? levo : desno;

	for (char x : s) {
		cout << f(x);
	}
}