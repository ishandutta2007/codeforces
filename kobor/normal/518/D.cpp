#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

double dp[2020];

void solve(){
	int n, t;
	double p, ans = 0;
	cin >> n >> p >> t;
	dp[0] = 1;
	FOR(i, 0, t){
		for(int j = n; j >= 0; j--){
			dp[j] = (j == n ? 1 : (1-p))*dp[j] + (j>0 ? p*dp[j-1] : 0);
		}
	}
	FOR(i, 0, n+1) ans += i*dp[i];
	cout << fixed << setprecision(9);
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}