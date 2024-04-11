#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 55;
const int mod = 1e9 + 7;
#define has(msk, v) (((msk) >> (v)) & 1)

int n, m, a[MAXN][MAXN];
char str[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

bool empty(int sx, int ex, int sy, int ey){
	return a[ex][ey] - a[sx-1][ey] - a[ex][sy-1] + a[sx-1][sy-1] == 0;
}

int f(int sx, int ex, int sy, int ey){
	if(sx > ex || sy > ey) return 0;
	if(~dp[sx][ex][sy][ey]) return dp[sx][ex][sy][ey];
	int ret = max(ex - sx + 1, ey - sy + 1);
	if(empty(ex, ex, sy, ey)) ret = min(ret, f(sx, ex - 1, sy, ey));
	if(empty(sx, sx, sy, ey)) ret = min(ret, f(sx + 1, ex, sy, ey));
	if(empty(sx, ex, sy, sy)) ret = min(ret, f(sx, ex, sy + 1, ey));
	if(empty(sx, ex, ey, ey)) ret = min(ret, f(sx, ex, sy, ey - 1));
	for(int i=sx; i<ex; i++){
		ret = min(ret, f(sx, i, sy, ey) + f(i + 1, ex, sy, ey));
	}
	for(int i=sy; i<ey; i++){
		ret = min(ret, f(sx, ex, sy, i) + f(sx, ex, i + 1, ey));
	}
	return dp[sx][ex][sy][ey] = ret;
}

int main(){
	cin >> n;
	m = n;
	for(int i=1; i<=n; i++){
		scanf("%s", str[i] + 1);
		for(int j=1; j<=m; j++){
			if(str[i][j] == '#'){
				a[i][j] = 1;
			}
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << f(1, n, 1, m) << endl;
}