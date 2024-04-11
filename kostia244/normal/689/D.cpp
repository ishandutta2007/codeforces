#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = (1 << 20);
const int MAXLOG = 20;

struct sparse_table
{
	int dp[MAXN][MAXLOG];
	int prec_lg2[MAXN], n;

	sparse_table() { memset(dp, 0, sizeof(dp)); memset(prec_lg2, 0, sizeof(prec_lg2)); n = 0; }

	void init(vector<int> &a)
	{
		n = a.size();
		for(int i = 2; i < 2 * n; i++) prec_lg2[i] = prec_lg2[i >> 1] + 1;
		for(int i = 0; i < n; i++) dp[i][0] = a[i];
		for(int j = 1; (1 << j) <= n; j++)
			for(int i = 0; i < n; i++)
				dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	}

	int query(int l, int r)
	{
		int k = prec_lg2[r - l + 1];
		return min(dp[l][k], dp[r - (1 << k) + 1][k]);
	}
};
struct sparse_table2
{
	int dp[MAXN][MAXLOG];
	int prec_lg2[MAXN], n;

	sparse_table2() { memset(dp, 0, sizeof(dp)); memset(prec_lg2, 0, sizeof(prec_lg2)); n = 0; }

	void init(vector<int> &a)
	{
		n = a.size();
		for(int i = 2; i < 2 * n; i++) prec_lg2[i] = prec_lg2[i >> 1] + 1;
		for(int i = 0; i < n; i++) dp[i][0] = a[i];
		for(int j = 1; (1 << j) <= n; j++)
			for(int i = 0; i < n; i++)
				dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	}

	int query(int l, int r)
	{
		int k = prec_lg2[r - l + 1];
		return max(dp[l][k], dp[r - (1 << k) + 1][k]);
	}
};

int n;
vi a, b;
sparse_table2 x;
sparse_table y;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	b.resize(n);
	for(auto &i : b) cin >> i;
	x.init(a);
	y.init(b);
	ll res = 0;
	for(int i = 0; i < n; i++) {
		if(x.query(i, n-1)<y.query(i, n-1)) continue;
		if(a[i]>b[i]) continue;
		int ans = i;
		for(int j = 1<<17;j;j>>=1)
			if(ans+j<n&&x.query(i, ans+j)<y.query(i, ans+j)) {
				ans+=j;
			}
		if(x.query(i, ans)<y.query(i, ans)) ans++;
		if(ans>=n||x.query(i, ans)!=y.query(i, ans))continue;
		int ans2 = ans;
		for(int j = 1<<17;j;j>>=1)
			if(ans2+j<n&&x.query(i, ans2+j)<=y.query(i, ans2+j)) {
				ans2+=j;
			}
		res += ans2-ans+1;
	}
	cout << res;
}