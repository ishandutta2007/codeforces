//#pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
//#pragma GCC target("avx,avx2,sse,sse2,tune=native,fma")
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
const int maxn = 2e5 + 30;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, k;
using ld = long double;
ld p[23], dp[1<<20], sum[1<<20], ans[23];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	int l = 0;
	memset(sum, 0, sizeof sum);
	for(int i = 0; i <n ; i++) {
		cin >> p[i], sum[1<<i] = p[i];
		if(p[i]>1e-9) l++;
	}
	k = min(k, l);
	memset(dp, 0, sizeof dp);
	memset(ans, 0, sizeof ans);
	dp[0] = 1;
	for(int j = 0; j < n; j++)
	for(int i = 1; i < 1<<n; i++)
		if(i&(1<<j)) sum[i] += sum[i^(1<<j)];
	for(int i = 1; i < 1<<n; i++) {
		for(int j = 0; j < n; j++) {
			if((i&(1<<j))&&p[j]>1e-9) {
				dp[i] += dp[i^(1<<j)]*(p[j]/(1.-sum[i^(1<<j)]));
			}
		}
//		cout <<
	}
	for(int i = 0; i < 1<<n; i++) {
//		cout << i << " " <<dp[i] << "\n";
		if(__builtin_popcount(i)!=k) continue;
		for(int j = 0; j < n; j++) {
			if(i&(1<<j)) {
				ans[j] += dp[i];
			}
		}
	}
	cout << fixed<<setprecision(15);
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";

}