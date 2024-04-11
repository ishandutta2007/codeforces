#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 1005;

int n, k, p, a[MAXN], b[MAXN * 2];
lint dp[MAXN][2*MAXN];

lint f(int x, int y){
	if(x == n) return 0;
	if(y == k) return 1e18;
	if(~dp[x][y]) return dp[x][y];
	lint ans = max(f(x+1, y+1), 1ll * abs(a[x] - b[y]) + abs(b[y] - p));
	ans = min(ans, f(x, y+1));
	return dp[x][y] = ans;
}

int main(){
	cin >> n >> k >> p;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<k; i++) cin >> b[i];
	sort(a, a+n);
	sort(b, b+k);
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0);
}