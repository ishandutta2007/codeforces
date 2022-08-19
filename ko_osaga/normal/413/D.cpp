#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, k, a[2005], ppow[2005];
int dp[2005][2050];

int f(int x, int y){
	if(y == (1 << k)) return ppow[x];
	if(x == n) return 0;
	if(~dp[x][y]) return dp[x][y];
	int ret = 0;
	if(a[x] != 4) ret += f(x+1, y+2);
	if(a[x] != 2){
		if(y % 4 == 2) ret += f(x+1, 4);
		else ret += f(x+1, y+4);
	}
	ret %= mod;
	return dp[x][y] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> a[i];
	ppow[n] = 1;
	for(int i=n-1; i>=0; i--){
		ppow[i] = ppow[i+1];
		if(a[i] == 0) ppow[i] = (ppow[i] << 1) % mod;
	}
	cout << f(0, 0);
}