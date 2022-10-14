#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pb push_back
using namespace std;using ll = long long;
using vi = vector<ll>;
const int maxn = 505, mlg = 17, mod = 998244353;
ll dp[maxn][maxn][11], bp[maxn][maxn][12], tp[maxn][maxn][12];
int to[maxn][11], freq[maxn], h[maxn], sz = 1;
int n, k;
void add(string s, int x) {
	int cur = 0;
	for(auto i : s) {
		i -= '0';
		if(!to[cur][i]) h[sz] = h[cur] + 1, to[cur][i] = sz++;
		cur = to[cur][i];
	}
	freq[cur] += x;
}
ll dfs(int v, int d, int k);
void calcbp(int v, int d) {
	if(bp[v][d][0] < 4557430888798830399) return;
	memset(bp[v][d], 0, sizeof bp[v][d]);
	for(int c = 0; k && c < 10; c++) {
		if(!to[v][c]) continue;
		memset(tp[v][d], 0x3f, sizeof tp[v][d]);
		int i = to[v][c];
		for(int x = 0; x < 11; x++)
			for(int y = 0; x+y < 11; y++) {
				tp[v][d][x+y] = min(tp[v][d][x+y], bp[v][d][x] + dfs(i, d, y));
			}
		for(int i = 0; i < 11; i++)
			bp[v][d][i] = tp[v][d][i];
	}
}
ll dfs(int v, int d, int k) {
	if(dp[v][d][k] < 4557430888798830399) return dp[v][d][k];
	calcbp(v, d);
	dp[v][d][k] = freq[v]*1ll*(h[v]-d+(d!=0)) + bp[v][d][0];
	//cout << v << " " << d << ": \n";
	//for(int i = 0; i < 11; i++) cout << bp[v][d][i] << " "; cout << '\n';
	if(k) dp[v][d][k] = dfs(v, h[v], k-1);
	dp[v][d][k] = min(dp[v][d][k], bp[v][d][k] + freq[v]*1ll*(h[v]-d));
	//cout << v << " " << d << " " << k << " " << dp[v][d][k] << '\n';
	return dp[v][d][k];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(dp, 0x3f, sizeof dp);
	memset(bp, 0x3f, sizeof bp);
	cin >> n >> k;
	string s;
	int x;
	while(n--) {
		cin >> s >> x;
		add(s, x);
	}
	cout << dfs(0, 0, k);
}