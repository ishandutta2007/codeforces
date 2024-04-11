//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 1e9 + 7;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	ll n;
	vi a, dp, p;
	cin >> n;
	a.resize(n+1);
	dp.resize(n+1,0);
	p.resize(n+1,0);
	map<int, vi> x;
	for(int i = 1; i <= n; i++) cin >> a[i], x[a[i]].pb(i);
	sort(all(a));
	ll ans = (dp[0]=-a[1]);
	int pp = 0;
	for(int i = 1; i <= n; i++) {
		if(i-3>=3)
		if(ans > dp[i-3])ans=dp[i-3], pp = i-3;
		dp[i] = (i!=n?-a[i+1]:0)+a[i]+ans;
		p[i]= pp;
	}
	vi res(n+1, 0);
	pp=n;
	int z = 1;
	while(pp) {
		for(int i = p[pp]+1; i <= pp; i++)
			res[x[a[i]].back()]=z, x[a[i]].pop_back();
		++z;
		pp = p[pp];
	}
	cout << dp[n] << " " << z-1 << "\n";
	for(int i = 1; i <= n; i++) cout << res[i] << " ";

}