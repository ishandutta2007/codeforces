#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 5e3 + 10, maxs = maxn*maxn/2, mlg = 20, mod = 1e9 + 7;
int sz = 1, cur = 0;
int tin[maxs], bk[maxn];
int occ[maxn][maxn];
int n, a, b, dp[2][maxn];
string s;
void calc() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			occ[i][j] = j;
	for(int st = 0; st < n; st++) {
		bk[st] = st-1;
		int i = st, j = st-1;
		while(i < s.size()) {
			while(j!=st-1&&s[j]!=s[i]) j = bk[j];
			i++, j++;
			bk[i] = j;
		}
		i = st;
		j = st-1;
		while(i < s.size()) {
			while(j!=st-1&&s[j]!=s[i]) j = bk[j];
			int len = j-st+1;
			if(len>0)
			occ[i-len+1][i] = min(occ[i-len+1][i], j);
			i++, j++;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = n; j-->i;) {
			if(i)
			occ[i][j] = min(occ[i][j], occ[i-1][j]);
			if(j+1<n)
			occ[i][j] = min(occ[i][j+1]-1, occ[i][j]);
			occ[i][j] = min(occ[i][j], occ[occ[i][j]-j+i][occ[i][j]]);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, 0x3f, sizeof dp);
	memset(tin, 0x3f, sizeof tin);
	cin >> n >> a >> b >> s;
	calc();
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		int it = i&1;
		memset(dp[it^1], 0x3f,sizeof dp[it^1]);
		dp[it^1][i+1] = dp[it][i]+a;
		for(int j = 0; j <= i; j++) {
			dp[it^1][j] = min(dp[it^1][j], dp[it][j]);
			if(occ[j][i]<j)
			dp[it^1][i+1] = min(dp[it^1][i+1], dp[it][j]+b);
		}
	}
	cout << dp[n&1][n];
	return 0;
}