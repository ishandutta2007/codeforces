#include<iostream>

using namespace std;

typedef long long llint;

const int MAXN = 405;
const int MOD = 1000000007;

int n;
llint dp[MAXN] [MAXN];
llint nck[MAXN];

inline llint mul (llint a, llint b) {
	return a*b%MOD;
}

void calc () {
	for (int i=0; i<=n; i++) {
		dp[i] [0] = 1;
		nck[i] = mul(i, i-1);
	}
	dp[0] [1] = 1;
	for (int x=1; x<=n; x++) {
		for (int y=1; y<=n; y++) {
			llint res = 0;
			for (int k=0; k<=y; k++) {
				res += mul(mul(dp[x-1] [k], dp[x-1] [y-k]), 2*y+1 );
			}
			for (int k=0; k<=y-1; k++) {
				res += mul(dp[x-1] [k], dp[x-1] [y-1-k]);
			}
			for (int k=0; k<=y+1; k++) {
				res += mul(mul(dp[x-1] [k], dp[x-1] [y+1-k]), nck[y+1] );
			}
			while (res>=MOD) res-=MOD;
			dp[x] [y] = res;
		}
	}
}

int main () {
	cin >> n;
	calc();
	cout << dp[n-1] [1];
	return 0;
}