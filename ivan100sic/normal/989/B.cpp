#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[11111][222];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, p;
	string s;
	cin >> n >> p >> s;

	bool ok = false;
	if (p == n) {
		cout << "No\n";
		return 0;
	}

	for (int i=p; i<n; i++) {
		if (s[i] != s[i-p] || s[i] == '.' || s[i-p] == '.')
			ok = true;
	}

	if (!ok) {
		cout << "No\n";
		return 0;
	}

	for (int i=0; i<p; i++)
		if (s[i] == '.') {
			if (i+p < n) {
				if (s[i+p] != '.')
					s[i] = s[i+p] ^ 1;
				else
					s[i] = '1';
			} else {
				s[i] = '1';
			}
		}

	for (int i=p; i<n; i++) {
		if (s[i] == '.')
			s[i] = s[i-p] ^ 1;
	}

	cout << s << '\n';
}