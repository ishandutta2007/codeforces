#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s;
int z[26][200005], n;
int v[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=0; i<n; i++) {
		for (int j=0; j<26; j++)
			z[j][i+1] = z[j][i];
		z[s[i]-'a'][i+1]++;
	}
	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		memset(v, 0, sizeof(v));
		for (char x : t)
			v[x-'a']++;
		int l = 0, r = n, o = -1;
		while (l <= r) {
			int m = (l+r) >> 1;
			bool ok = true;
			for (int i=0; i<26; i++) {
				if (z[i][m] < v[i]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << o << '\n';
	}
}