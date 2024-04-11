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
const int maxn = 1e5 + 30, mod = 1e9 + 9;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename X, typename Y>
void maxq(X &a, const Y &b) {
	if(a<b) a = b;
}
int n, m, x,dp[maxn][32], pw[maxn], ah[maxn], bh[maxn], base = 300 + rng()%1000;
string s, t;
int get(int i, int j, int t) {
	t^=1;
	int res = (t?ah:bh)[j] - (i?(t?ah:bh)[i-1]:0);
	if(res < 0) res += mod;
	return res*1ll*pw[max(n, m)-i-1]%mod;
}
int lcp(int i, int j) {
	if(j==t.size()) return 0;
	if(i==s.size()) return 0;
	int ans = 1;
	if(s[i]!=t[j]) return 0;
	for(int z = 1<<17;z>>=1;)
		if(i+ans+z-1<s.size()&&j+ans+z-1<t.size()&&get(i,i+ans+z-1,0)==get(j,j+ans+z-1,1))ans+=z;
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s >> m >> t >> x;
	ah[0] = s[0];
	bh[0] = t[0];
	pw[0] = 1;
	for(int i = 1; i < n; i++) {
		pw[i] = (pw[i-1]*1ll*base)%mod;
		ah[i] = (ah[i-1] + s[i]*1ll*pw[i])%mod;
	}
	for(int i = 1; i < m; i++) {
		pw[i] = (pw[i-1]*1ll*base)%mod;
		bh[i] = (bh[i-1] + t[i]*1ll*pw[i])%mod;
	}
	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j <= x; j++) {
			int t = lcp(i, dp[i][j]);
			maxq(dp[i+1][j], dp[i][j]);
//			cout << t << "\n";
			maxq(dp[i+t][j+1], dp[i][j]+t);
		}
	}
	for(int i =0; i<=x;i++)
		if(dp[s.size()][i]==t.size())
			return cout << "YES", 0;
	cout << "NO";
}