#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, kk;
int a[505], b[505];
int pc[505][1005], dp[505][505];
int px[505][505], py[505][505];
map<int, int> mp, inv;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	cin >> m;
	for (int i=1; i<=m; i++)
		cin >> b[i];

	for (int i=1; i<=n; i++)
		mp[a[i]] = 0;
	for (int i=1; i<=m; i++)
		mp[b[i]] = 0;

	for (auto& p : mp) {
		p.second = ++kk;
		inv[kk] = p.first;
	}

	for (int i=1; i<=n; i++)
		a[i] = mp[a[i]];
	for (int i=1; i<=m; i++)
		b[i] = mp[b[i]];

	for (int i=1; i<=n; i++) {
		copy(pc[i-1], pc[i-1] + 1000, pc[i]);
		pc[i][a[i]] = i;
	}

	int bi=0, bj=0;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i] != b[j])
				continue;
			dp[i][j] = 1;
			for (int l=1; l<j; l++) {
				if (b[l] < b[j]) {
					int k = pc[i-1][b[l]];
					if (k != 0) {
						int v = 1 + dp[k][l];
						if (v > dp[i][j]) {
							dp[i][j] = v;
							px[i][j] = k;
							py[i][j] = l;
						}				
					}
				}
			}
			if (dp[i][j] > dp[bi][bj]) {
				bi = i;
				bj = j;
			}
		}
	}

	basic_string<int> sol;
	while (bi) {
		sol += inv[a[bi]];
		int x = px[bi][bj];
		int y = py[bi][bj];
		bi = x;
		bj = y;
	}

	reverse(sol.begin(), sol.end());
	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}