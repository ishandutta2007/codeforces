#include<iostream>
#include<cstring>

using namespace std;

int n, a, b;
int dp[10] [10] [1005];

int f (int x, int y, int ost) {
	if (x==0 && y==0) return 0;
	if (dp[x] [y] [ost]!=-1) return dp[x] [y] [ost];
	int res=10000;
	if (x && ost>=a) res=min(res, f(x-1, y, ost-a));
	if (y && ost>=b) res=min(res, f(x, y-1, ost-b));
	if (ost!=n) res=min(res, 1+f(x, y, n));
	dp[x] [y] [ost]=res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n >> a >> b;
	cout << f(4, 2, 0);
	return 0;
}