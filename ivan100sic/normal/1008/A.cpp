#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool v(char x) {
	if (x == 'a') return 1;
	if (x == 'e') return 1;
	if (x == 'i') return 1;
	if (x == 'o') return 1;
	if (x == 'u') return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	bool bad = false;
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] != 'n' && !v(s[i])) {
			if (i == (int)s.size()-1)
				bad = true;
			else if (!v(s[i+1]))
				bad = true;
		}
	}
	cout << (bad ? "NO" : "YES");
}