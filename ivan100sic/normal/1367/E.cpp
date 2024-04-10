// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string s;
		cin >> n >> k >> s;

		int c[26] = {0};
		for (char x : s)
			c[x-'a']++;

		int sol = 0;

		for (int l=1; l<=(int)s.size(); l++) {
			int g = l / gcd(l, k);
			int av = 0;
			for (int i=0; i<26; i++)
				av += c[i] / g;

			if (av >= gcd(l, k)) {
				sol = l;
			}
		}

		cout << sol << '\n';
	}
}