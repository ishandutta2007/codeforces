#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pos1[20][20], pos2[20][20];
ll a[20][20];
template<typename T>
void print(vector<T> v) {
	for (T x : v) {
		cout << x << " ";
	}
	cout << "\n";
}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n, m, i, j;
	ll k;
	cin >> n >> m >> k;
	for (i = 0; i < n; i++)for (j = 0; j < m; j++)cin >> a[i][j];
	if (n == 1 && m == 1) {
		printf("%d", (a[0][0] == k));
		return 0;
	}
	pos1[0][0].push_back(a[0][0] ^ k);
	pos2[n - 1][m - 1].push_back(a[n - 1][m - 1]);
	for (i = 1; i <= (m + n) / 2 - 1; i++) {
		for (j = 0; j < m; j++) {
			if (i - j < 0 || i - j >= n)continue;
			int k = i - j;
			if (j) {
				for (ll x : pos1[k][j - 1])pos1[k][j].push_back(x);
				pos1[k][j - 1].clear();
			}
			if (k)for (ll x : pos1[k - 1][j])pos1[k][j].push_back(x);
			for (int l = 0; l < pos1[k][j].size(); l++)pos1[k][j][l] ^= a[k][j];
		}
	}

	for (i = m + n - 3; i >= (m + n) / 2 - 1; i--) {
		for (j = 0; j < m; j++) {
			if (i - j < 0 || i - j >= n)continue;
			int k = i - j;
			if (j + 1 < m)for (ll x : pos2[k][j + 1])pos2[k][j].push_back(x);
			if (k + 1 < n) {
				for (ll x : pos2[k + 1][j])pos2[k][j].push_back(x);
				pos2[k + 1][j].clear();
			}
			if (i != (m + n) / 2 - 1)for (int l = 0; l < pos2[k][j].size(); l++)pos2[k][j][l] ^= a[k][j];
		}
	}
	ll ans = 0;
	for (i = 0; i < n; i++) {
		j = (m + n) / 2 - 1 - i;
		if (j < 0)continue;
		sort(pos1[i][j].begin(), pos1[i][j].end());
		sort(pos2[i][j].begin(), pos2[i][j].end());
		int a, b;
		ll cnta = 0, cntb = 0;
		//printf("%lld %lld\n",pos1[i][j][0],pos2[i][j][0]);
		for (a = 0, b = 0; a < pos1[i][j].size(); a++) {
			cnta++;
			if (a + 1 < pos1[i][j].size() && pos1[i][j][a] == pos1[i][j][a + 1])continue;
			while (b < pos2[i][j].size() && pos2[i][j][b] <= pos1[i][j][a]) {
				if (pos2[i][j][b] == pos1[i][j][a])cntb++;
				b++;
			}
			ans += cnta * cntb;
			cnta = cntb = 0;
		}
	}
	printf("%lld", ans);
}