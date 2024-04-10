#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dp[1 << 20];
int n, m;
string s[20];
int a[20][20];

void mn(int& x, int y) {
	x = min(x, y);
}

void add(int mask, int val) {
	for (int t=0; t<(1<<n); t++)
		mn(dp[t | mask], dp[t] + val);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	memset(dp, 63, sizeof dp);
	dp[0] = 0;

	for (int j=0; j<m; j++) {
		vector<int> u(26);
		vector<vector<int>> c(26);
		for (int i=0; i<n; i++)
			add(1<<i, a[i][j]);
		for (int i=0; i<n; i++) {
			int x = s[i][j]-'a';
			u[x] |= 1 << i;
			c[x].push_back(a[i][j]);
		}
		for (int i=0; i<26; i++) {
			if (!u[i])
				continue;
			sort(c[i].begin(), c[i].end());
			int w = accumulate(c[i].begin(), --c[i].end(), 0);
			add(u[i], w);
		}
	}
	cout << dp[(1<<n)-1] << '\n';
}