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

const int N = 1e6+5;

int n, m;
int t[3][N];
int dp[8][N];

bool check(int m1, int m2){
	if(n > 1 && ((__builtin_popcount(m1& 3) + __builtin_popcount(m2& 3)) & 1) == 0) return 0;
	if(n > 2 && ((__builtin_popcount(m1>>1) + __builtin_popcount(m2>>1)) & 1) == 0) return 0;
	return 1;
}

int get(int k){
	return t[0][k] + (t[1][k] << 1) + (t[2][k] << 2);
}

void solve(){
	memset(dp, INF, sizeof(dp));
	cin >> n >> m;
	if(min(n, m) > 3){
		cout << -1 << '\n';
		return;
	}
	FOR(i, 0, n) FOR(j, 0, m){
		char c;
		cin >> c;
		(n > m ? t[j][i] : t[i][j]) = (c == '1');
	}
	if(n > m) swap(n, m);
	memset(dp, INF, sizeof(dp));
	FOR(i, 0, 1<<n) dp[i][0] = __builtin_popcount(i^get(0));
	FOR(i, 1, m) FOR(m1, 0, 1<<n) FOR(m2, 0, 1<<n)
		if(check(m1, m2)) dp[m1][i] = min(dp[m1][i], dp[m2][i-1] + __builtin_popcount(m1^get(i)));
	int ans = INF;
	FOR(i, 0, 1<<n) ans = min(ans, dp[i][m-1]);
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