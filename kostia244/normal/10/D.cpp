//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e2 + 4;
int n, m, u = 0, a[maxn], b[maxn], res[maxn], res2[maxn], dp[2][maxn][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	for(int it = 1; it <= n; it++) {
		int i = it&1;
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= n; k++) {
				dp[i][j][k] = max(dp[i][j-1][k], dp[i^1][j][k]);
			}
			if(a[it]==b[j]) {
				dp[i][j][it] = max(dp[i][j][it], 1);
				for(int k = 1; k <= n; k++) {
					if(a[k]<a[it])
					dp[i][j][it] = max(dp[i][j][it], dp[i^1][j-1][k]+1);
				}
			}
			res[it] = max(res[it], dp[i][j][it]);
			u = max(u, res[it]);
		}
	}
	swap(n, m);
	for(int i = 1; i <= max(n, m); i++)
		swap(a[i], b[i]);
	memset(dp, 0, sizeof dp);
	for(int it = 1; it <= n; it++) {
		int i = it&1;
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= n; k++) {
				dp[i][j][k] = max(dp[i][j-1][k], dp[i^1][j][k]);
			}
			if(a[it]==b[j]) {
				dp[i][j][it] = max(dp[i][j][it], 1);
				for(int k = 1; k <= n; k++) {
					if(a[k]<a[it])
					dp[i][j][it] = max(dp[i][j][it], dp[i^1][j-1][k]+1);
				}
			}
			res2[it] = max(res2[it], dp[i][j][it]);
		}
	}
	int lsti = n+1, lstj = m+1;
	vi x;
	a[lsti] = b[lstj] = 1<<30;
	for(int i = n; u&&i;i--) {
		if(res2[i]<u||(a[i]>=a[lsti])) continue;
		int tj = lstj-1;
		while(tj>=0&&b[tj]!=a[i]) tj--;
		int ok = (tj>=0&&b[tj]==a[i]&&res[tj]>=u);
		if(ok) {
			lstj = tj;
			lsti = i;
			x.pb(a[i]);
			u--;
		}
	}
	cout << x.size() << "\n";
	reverse(all(x));
	for(auto i : x)
		cout << i << " ";
}