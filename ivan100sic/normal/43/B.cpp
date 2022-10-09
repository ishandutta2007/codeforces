// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s, a="YES\n";
	getline(cin, s);
	map<char, int> m;
	for (char c : s) {
		m[c]++;
	}

	getline(cin, s);
	for (char c : s) {
		if (c == ' ') continue;
		if (m[c]-- == 0) a = "NO\n";
	}

	cout << a;
}