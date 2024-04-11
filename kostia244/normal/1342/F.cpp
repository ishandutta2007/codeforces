#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, a[20], s[1<<15], low[1<<15], dp[1<<15][16][16];
array<int, 2> p[1<<15][16][16];//{mask, pos}
int get_pos(bitset<15> f, int p) {
	int ans =0;
	for(int i = 0; i <= p; i++) ans += !f[i];
	return ans;
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < 1<<n; i++) s[i] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 1<<i; j++)
			s[(1<<i) + j] = s[j] + a[i];
	}
	for(int i = 0; i < 1<<n; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k < n; k++)
				dp[i][j][k] = 1<<30, p[i][j][k] = {-1, -1};
	for(int i = 1; i < 1<<n; i++) dp[i][1][low[i]] = s[i], p[i][1][low[i]] = {i, 0};
	for(int msk = 0; msk < 1<<n; msk++)
		for(int len = 0; len < n; len++)
			for(int pos = 0; pos < n; pos++) {
				if((msk>>pos)%2 == 0 || dp[msk][len][pos] == 1<<30) continue;
				
				/*if(len)
				cout << msk << " " << len << " " << pos << " " << dp[msk][len][pos] << " " << 
				dp[msk^p[msk][len][pos][0]]
				[len-1]
				[p[msk][len][pos][1]] << endl;*/
				
				int inv = (1<<n) - msk - 1;
				for(int sub = inv; sub; sub = (sub-1)&inv) {
					if(s[sub] <= dp[msk][len][pos]) continue;
					int t = sub>>(pos+1);
					if(!t) continue;
					t = pos+1+low[t];
					if(dp[msk|sub][len+1][t] > s[sub]) {
						dp[msk|sub][len+1][t] = s[sub];
						p[msk|sub][len+1][t] = {sub, pos};
					}
				}
			}
		
	for(int i = 0; i < 1<<n; i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k < n; k++) assert(p[i][j][k][0]);
	array<int, 2> res;
	for(int len = 0; len <= n; len++)
		for(int pos = 0; pos < n; pos++) {
			if(dp[(1<<n)-1][len][pos] < 1<<30) {
				res = {len, pos};
				//cout << len << " " << pos << " " << p[(1<<n)-1][res[0]][res[1]][0] << endl;
			}//, cout << len << " " << pos << " " << p[(1<<n)-1][len][pos][0] << '\n';
		}
	cout << n-res[0] << '\n';
	vector<array<int, 2>> ops;
	int pos = res[1], len = res[0], M = (1<<n)-1;
	bitset<15> fr;
	while(len) {
		int sub = p[M][len][pos][0];
		if(sub == -1) break;
		int rpos = 0;
		for(int j = 0, i = 0; i < n; i++) {
			if(((sub>>i)&1) && i != pos) {
				ops.push_back({get_pos(fr, i), get_pos(fr, pos)});
				fr[i] = 1;
			}
		}
		pos = p[M][len][pos][1];
		len--;
		M ^= sub;
	}
	for(auto [x, y] : ops) cout << x << " " << y << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i = 1; i < 1<<15; i++)
		low[i] = (i&1) ? 0 : 1 + low[i/2];
    int t;
    cin >> t;
    while(t--) solve();
}