//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<vector<char>> a;
vector<vector<ll>> dp, rdp;
vector<ll> cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a.resize(n, vector<char>(m));
	dp.resize(n, vector<ll>(m));
	rdp.resize(n, vector<ll>(m));
	cnt.resize(n+m);
	for(auto &i : a)
		for(auto &j : i)
			cin >> j;
	dp[0][0] = 1;
	rdp[n-1][m-1] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j]=='#') continue;
			if(i) dp[i][j] |= dp[i-1][j];
			if(j) dp[i][j] |= dp[i][j-1];
		}
	}
	for(int i = n; i--;) {
		for(int j = m; j--;) {
			if(a[i][j]=='#') continue;
			if(i+1<n) rdp[i][j] |= rdp[i+1][j];
			if(j+1<m) rdp[i][j] |= rdp[i][j+1];
			cnt[i+j]+=dp[i][j]&&rdp[i][j];
		}
	}
	if(dp[n-1][m-1]==0) return cout << 0, 0;
	for(int i = 1; i < n+m-2; i++) {
		if(cnt[i]==0) return cout << 0, 0;
	}
	for(int i = 1; i < n+m-2; i++) {
		if(cnt[i]==1) return cout << 1, 0;
	}
	cout << 2;
}