#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 1000005;

int n;
int dp[MAXN], sum[MAXN] [15];

int f (int x) {
	int res=1;
	while (x) {
		if (x%10!=0) res*=x%10;
		x/=10;
	}
	return res;
}

int g (int x) {
	if (x<10) return x;
	if (dp[x]!=-1) return dp[x];
	dp[x]=g(f(x));
	return dp[x];
}

int main () {
	memset(dp, -1, sizeof dp);
	for (int i=1; i<MAXN; i++) {
		for (int j=0; j<10; j++) {
			sum[i] [j]=sum[i-1] [j];
		}
		sum[i] [g(i)]++;
	}
	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		printf("%d\n", sum[y] [k]-sum[x-1] [k]);
	}
	return 0;
}