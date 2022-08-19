#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int dp[1005][1005][11][2];
char s[1005], t[1005];
int n, m, k;

int f(int x, int y, int k, int p){
	if(k < 0) return -1e9;
	if(x == n && y == m) return 0;
	if(~dp[x][y][k][p]) return dp[x][y][k][p];
	int ret = -1e9;
	if(x < n) ret = max(ret, f(x+1, y, k, 0));
	if(y < m) ret = max(ret, f(x, y+1, k, 0));
	if(x<n && y<m && s[x] == t[y]){
		ret = max(ret, f(x+1, y+1, k-1, 1) + 1);
		if(p) ret = max(ret, f(x+1, y+1, k, 1) + 1);
	}
	return dp[x][y][k][p] = ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k >> s >> t;
	cout << f(0, 0, k, 0);
}