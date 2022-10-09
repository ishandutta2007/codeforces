#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int n = s.size();
		if (s[0] == '1' && count(s.begin() + 1, s.end() - 1, '0') == n - 2
			&& s.back() <= '1')
		{
			cout << string(n-2, '9') << '\n';
			continue;
		}

		int mask = 0;
		for (char c : s)
			mask ^= 1 << (c - '0');

		for (int l=1; l<=min(12, n); l++) {
			int lmask = mask;
			for (int i=0; i<l; i++)
				lmask ^= 1 << (s[n-1-i] - '0');
			if ((int)__builtin_popcount(lmask) <= l) {
				// prva cifra je strogo manja nego u s[n-1-l]
				int f = -1;
				int arb = l - __builtin_popcount(lmask);
				for (int j=s[n-l]-'0'-1; j>=0; j--) {
					if ((lmask & (1 << j)) || (arb > 0)) {
						f = j;
						lmask ^= 1 << j;
						break;
					}
				}
				arb = l - 1 - __builtin_popcount(lmask);
				if (f != -1) {
					string q = s.substr(0, n-l);
					q += char(f + '0');
					for (int j=0; j<arb; j++)
						q += '9';
					for (int j=9; j>=0; j--)
						if (lmask & (1 << j))
							q += char(j + '0');
					cout << q << '\n';
					break;
				}
			}
		}
	}

}