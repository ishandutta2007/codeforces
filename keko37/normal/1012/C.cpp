#include<iostream>
#include<cstring>

using namespace std;

typedef long long llint;

const int MAXN = 5005;
const llint INF = 1000000000000000007LL;

int n;
llint l[MAXN], dp[MAXN] [MAXN/2] [2];

llint f (int x, int y, int flg) {
	if (y == 0) return 0;
	if (x < 0) return INF;
	if (dp[x] [y] [flg] != -1) return dp[x] [y] [flg];
	llint res = INF, cost = 0, rig;
	res = min(res, f(x-1, y, 0));
	if (x > 0) cost = max(0LL, l[x-1] - l[x] + 1);
	if (x < n-1) {
		if (flg == 0) rig = max(0LL, l[x+1] - l[x] + 1); else rig = max(0LL, min(l[x+2]-1, l[x+1]) - l[x] + 1);
		cost += rig;
	}
	res = min(res, f(x-2, y-1, 1) + cost);
	dp[x] [y] [flg] = res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	for (int i=1; i<=(n+1)/2; i++) {
		cout << f(n-1, i, 0) << " ";
	}
	return 0;
}