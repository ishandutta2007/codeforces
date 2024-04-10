// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	map<char, int> m;
	m['A'] = m['B'] = m['C'] = 0;

	for (int i=0; i<3; i++) {
		string s;
		cin >> s;
		m[s[1] == '<' ? s[2] : s[0]]++;
	}

	map<int, char> f;
	for (auto [x, y] : m) {
		f[y] = x;
	}

	if (f.size() != 3) {
		cout << "Impossible\n";
	} else {
		for (auto [x, y] : f) cout << y;
		cout << '\n';
	}
}