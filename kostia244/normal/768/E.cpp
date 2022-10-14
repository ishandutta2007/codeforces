//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1e2 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, dp[66][66];
int go(int v, int m) {
	if(v==0) return 0;
	if(dp[v][m]!=-1) return dp[v][m];
	int &ans = dp[v][m];
	ans = 0;
	set<int> s;
	for(int i = 1; i < m; i++) {
		if(v-i>=0)
		s.insert(go(v-i, i));
	}
	while(s.count(ans)) ans++;
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof dp);
	int n,t,ans =0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		ans^=go(t, 61);
	}
	cout << (ans?"NO":"YES");
}