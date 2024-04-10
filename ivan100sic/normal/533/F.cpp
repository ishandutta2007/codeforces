#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 998244353;
const int B = 333;

int vals[26];
int hs[26][200005];
int hg[26];
int ht[26];
int p[200005];
int n, m;
string s, t;
int v[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	basic_string<int> sol;

	cin >> n >> m >> s >> t;
	fill(vals, vals+26, 1);
	p[0] = 1;
	for (int i=0; i<n; i++) {
		vals[s[i] - 'a'] = 2;
		for (int j=0; j<26; j++)
			hs[j][i+1] = (hs[j][i] * 1ll * B + vals[j]) % M;
		vals[s[i] - 'a'] = 1;
		p[i+1] = p[i] * 1ll * B % M;
	}

	for (int i=0; i<m; i++) {
		vals[t[i] - 'a'] = 2;
		for (int j=0; j<26; j++)
			ht[j] = (ht[j] * 1ll * B + vals[j]) % M;
		vals[t[i] - 'a'] = 1;
	}

	for (int i=0; i<=n-m; i++) {
		for (int j=0; j<26; j++) {
			hg[j] = hs[j][i+m] - hs[j][i] * 1ll * p[m] % M;
			if (hg[j] < 0)
				hg[j] += M;
		}
		// spari
		fill(v, v+26, -1);
		bool ok = 1;
		for (int j=0; j<26; j++) {
			if (v[j] != -1) {
				if (hg[j] != ht[v[j]]) {
					ok = 0;
					break;
				}
			} else {
				bool found = 0;
				for (int k=0; k<26; k++) {
					if (v[k] == -1 && hg[j] == ht[k] && hg[k] == ht[j]) {
						v[k] = j;
						v[j] = k;
						found = 1;
						break;
					}
				}
				if (!found) {
					ok = 0;
					break;
				}
			}
		}

		if (ok)
			sol += i+1;
	}

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}