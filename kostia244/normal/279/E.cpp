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
const int maxn = 1e6 + 5;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
string s;
int dp[maxn][2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	reverse(all(s));
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < s.size(); i++) {
		for(int co = 0; co < 2; co++) {
			int cur = (s[i]-'0')+co;
			int t = cur&1;
			dp[i+1][cur>>1] = min(dp[i+1][cur>>1], dp[i][co] + t);
			if(cur<2&&t) {
				dp[i+1][1] = min(dp[i+1][1], dp[i][co] + 1);
			}
		}
	}
	cout << min(dp[s.size()][0], dp[s.size()][1]+1);
}