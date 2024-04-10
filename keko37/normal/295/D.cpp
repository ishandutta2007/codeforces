#include<iostream>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 2005;
int n, m, sol;
int dp[MAXN] [MAXN];
int jen[MAXN] [MAXN];
int dva[MAXN] [MAXN];
int isk[MAXN] [MAXN];
int sum[MAXN] [MAXN];
int pre[MAXN] [MAXN];

int add (int a, int b) {
	if (a+b>=MOD) return a+b-MOD;
	return a+b;
}

int sub (int a, int b) {
	if (a-b<0) return a-b+MOD;
	return a-b;
}

int mul (int a, int b) {
	return ((long long) a)*((long long) b)%MOD;
}

int main () {
	cin >> n >> m;
	if (m==1) {
		cout << 0;
		return 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=2; j<=m; j++) {
			if (i==1) dp[i] [j]=1; else dp[i] [j]=dva[i-1] [j];
			jen[i] [j]=add(jen[i] [j-1], dp[i] [j]);
			dva[i] [j]=add(dva[i] [j-1], jen[i] [j]);
			sum[i] [j]=add(sum[i-1] [j], dp[i] [j]);
			isk[i] [j]=sub(dp[i] [j], dp[i-1] [j]);
			pre[i] [j]=add(pre[i-1] [j], isk[i] [j]);
		}
	}
    for (int i=1; i<=n; i++) {
	    for (int j=2; j<=m; j++) {
		    sol=add(sol, mul(m-j+1, mul(sum[i] [j], pre[n-i+1] [j])));
	    }
    }
    cout << sol;
	return 0;
}