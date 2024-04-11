#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 60;
const int maxb = 111;
void minq(ll &a, ll b) {
	if (b < a)
		a = b;
}
int main() {
//	ios::sync_with_stdio(0);
//	cout.tie(0);
//	cin.tie(0);
	int n;
	vpi a;
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i.first;
	for (auto &i : a)
		cin >> i.second;
	map<int, vi, greater<int>> x;
	for (auto i : a)
		x[i.first].pb(i.second);
	int i = 0;
	vector<vector<vector<ll>>> dp(maxn, vvi(maxn, vi(maxn*maxb, 1e13)));
	dp[0][0][0] = 0;
	for (auto a : x) {
		ll prefb = 0, prefa = 0, skip = a.second.size(), add = 0;
		sort(all(a.second));
		while(true) {
			assert(i<=n);
			assert(skip<=n);
			assert(add<=n);
			for(int j = skip; j <= n; j++)
				if(j-skip+add>=0&&j-skip+add<=n)
				for(int k = 0; k+prefb <= n*maxb; k++) {
					minq(dp[i+1][j-skip+add][k+prefb], dp[i][j][k] + prefa);
				}
			if(!a.second.empty()) {
				prefa += a.first;
				prefb += a.second.back();
				a.second.pop_back();
				add++;
				skip--;
			} else
				break;
		}
//		cout << i << "\n";
		i++;
	}
	ll ans = LLONG_MAX;
	for(int j = 0; j <= n; j++)
		for(int k = 1; k <= n*maxb; k++)
			ans = min(ans, (1000ll*dp[i][j][k] + k - 1)/k);
	cout << ans;
}