// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;
	map<char, int> m;

	for (char x : s)
		m[x]++;

	s = "";

	vector<char> odd;

	for (auto [x, y] : m) {
		if (y % 2) {
			odd.push_back(x);
		}
	}

	int l = odd.size();
	for (int i=0; i<l/2; i++) {
		m[odd[i]]++;
		m[odd[l-1-i]]--;
	}

	// pola
	for (auto [x, y] : m) {
		s += string(y/2, x);
	}

	string s2;
	// odd
	for (auto [x, y] : m) {
		s2 += string(y%2, x);
	}

	string w = s;
	reverse(begin(w), end(w));

	cout << s << s2 << w << '\n';
}