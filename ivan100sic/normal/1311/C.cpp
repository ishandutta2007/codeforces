#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int p[200005];
int z[26][200005];
int w[26];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> s;
		for (int i=1; i<=n; i++)
			for (int j=0; j<26; j++)
				z[j][i] = 0;
		for (int i=1; i<=n; i++)
			z[s[i-1]-'a'][i]++;
		for (int i=1; i<=n; i++)
			for (int j=0; j<26; j++)
				z[j][i] += z[j][i-1];
		memset(w, 0, sizeof w);
		for (int i=0; i<m; i++) {
			int x;
			cin >> x;
			for (int j=0; j<26; j++)
				w[j] += z[j][x];
		}
		for (int j=0; j<26; j++)
			w[j] += z[j][n];
		for (int j=0; j<26; j++)
			cout << w[j] << " \n"[j == 25];
	}
}