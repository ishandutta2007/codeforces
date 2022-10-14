#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e3 + 55, mlg = 20, mod = 1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, dp[maxn], a[maxn];
int trie[maxn*maxn/2][2], sz = 1;
bool add(int &v, char c) {
	c-='0';
	if(!trie[v][c]) {
		trie[v][c] = sz++;
		v = trie[v][c];
		return true;
	}
	v = trie[v][c];
	return false;
}
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	char t;
	for(int i = 0; i < n; i++) cin >> t, s+=t;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		memset(dp, 0, sizeof dp);
		dp[i] = 1;
		for(int j = i; j < n; j++) {
			(dp[j+1]+=dp[j])%=mod;
			(dp[j+2]+=dp[j])%=mod;
			(dp[j+3]+=dp[j])%=mod;
			if(s.substr(j, 4)!="0011"&&s.substr(j, 4)!="0101"&&s.substr(j, 4)!="1110"&&s.substr(j, 4)!="1111")
			(dp[j+4]+=dp[j])%=mod;
//			cout << s.substr(j, 4) << "\n";
		}
		int cur = 0;
		for(int j = i+1; j <= n; j++) {
			if(add(cur, s[j-1]))
				a[j] += dp[j];
//			cout << s.substr(i, j-i) << " " << dp[j] << "\n";
			if(a[j]>=mod) a[j]-=mod;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << ((a[i]+=a[i-1])%=mod) << "\n";
	}
	return 0;
}