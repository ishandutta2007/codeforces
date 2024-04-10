#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long llint;

const int MAXN = 2005;
const llint INF = 10000000000000000LL;

int n, k, p;
llint a[MAXN], b[MAXN];
llint dp[MAXN] [MAXN];

llint dist (llint x, llint y) {
	if (x-y>0) return x-y; return y-x;
}

llint f (int x, int y) {
	if (x+1>y+1) return INF;
	if (x<0) return 0;
	if (dp[x] [y]!=-1) return dp[x] [y];
	llint res=INF;
	
	//nisi uzeo
	res=min(res, f(x, y-1));
	
	//uzeo
	res=min(res, max(dist(a[x], b[y])+dist(b[y], p), f(x-1, y-1)));

	dp[x] [y]=res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n >> k >> p;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<k; i++) {
		cin >> b[i];
	}
	sort(a, a+n);
	sort(b, b+k);
	cout << f(n-1, k-1);
	return 0;
}