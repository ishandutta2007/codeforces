#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e2 + 5, bias = maxn*maxn*10;
int n, k, a[maxn], b[maxn], dp[maxn][2*bias];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i], b[i]*=k;
	memset(dp, -1, sizeof dp);
	dp[0][bias] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2*bias; j++) {
			if(dp[i][j]!=-1){
			dp[i+1][j-a[i]+b[i]] = max(dp[i+1][j-a[i]+b[i]], dp[i][j]+a[i]);
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			}
		}
	}
	if(dp[n][bias]==0)dp[n][bias]=-1;
	cout << dp[n][bias];
}