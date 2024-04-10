#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	map<char, int> m;

	for (char x : s) {
		m[x]++;
	}

	// Bulbasaur
	// Baabuulrs

	int f = 1e9;
	f = min(f, m['B']);
	f = min(f, m['b']);
	f = min(f, m['l']);
	f = min(f, m['r']);
	f = min(f, m['s']);
	f = min(f, m['a'] / 2);
	f = min(f, m['u'] / 2);

	cout << f;
}