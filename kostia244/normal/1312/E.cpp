//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e2 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll go[maxn][1150];
int n, a[maxn], dp[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	memset(go, -1, sizeof go);
	for(int i = 1; i <= n; i++) {
		go[i][a[i]] = i-1;
		for(int lst = a[i]+1; lst <= 1050; lst++) {
			if(go[i][lst-1]==-1) break;
			go[i][lst] = go[go[i][lst-1]][lst-1];
		}
	}
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = 1<<30;
		for(int j = 1; j <= 1050; j++) {
			if(go[i][j]==-1) continue;
			dp[i] = min(dp[i], 1+dp[go[i][j]]);
		}
	}
	cout << dp[n];
}