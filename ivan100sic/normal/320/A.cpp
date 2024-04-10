#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool m(string s) {
	if (s == "")
		return true;
	if (size(s) >= 1 && s.substr(0, 1) == "1" && m(s.substr(1)))
		return true;
	if (size(s) >= 2 && s.substr(0, 2) == "14" && m(s.substr(2)))
		return true;
	if (size(s) >= 3 && s.substr(0, 3) == "144" && m(s.substr(3)))
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;

	cin >> s;
	cout << (m(s) ? "YES" : "NO");
}