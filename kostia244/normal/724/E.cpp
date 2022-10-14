#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
ll n, c, a[11000], s[11000], dp[2][11000], cut = LLONG_MAX;
#define minq(x, y) (x = (((x)<(y))?(x):(y)))
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> c;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> s[i];
	memset(dp, 0, sizeof dp);
	for(ll it = 1; it <= n; it++) {
		int i = it&1;
		for(int j = 0; j <= it; j++) {
			dp[i][j] =j!=it ? dp[i^1][j] + a[it] + j*c : LLONG_MAX;
			if(j) minq(dp[i][j], dp[i^1][j-1] + s[it]);
			if(it == n) minq(cut, dp[i][j]);
		}
	}
	cout << cut;
}