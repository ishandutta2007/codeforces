#include<iostream>

using namespace std;

typedef long long llint;

const int MOD = 1000000007;
const int MAXN = 1005;

llint k, pa, pb;
llint x, y, z, w, cost;
llint dp[MAXN] [MAXN], p[MAXN];

llint pot (llint b, llint e) {
	if (e==0) return 1;
	if (e&1) {
		return pot(b, e-1)*b%MOD;
	} else {
		llint t=pot(b, e/2);
		return t*t%MOD;
	}
}

void precompute () {
	x=pa*pot(pa+pb, MOD-2)%MOD;
	y=(1-x+MOD)%MOD;
	z=pot(y, MOD-2);
	cost=x*z%MOD;
	w=pot(cost, MOD-2);
	for (int i=0; i<MAXN; i++) {
		p[i]=pot(x, i);
	}
}

int main () {
	cin >> k >> pa >> pb;
	precompute();
	for (int i=1; i<=k; i++) {
		for (int h=1; h<i; h++) {
			dp[i] [0]=(dp[i] [0]+dp[i-h] [h]*p[h])%MOD;
		}
		dp[i] [0]=(z+w*dp[i] [0])%MOD;
		for (int j=1; j<=k; j++) {
			int lim=i-j;
			for (int h=0; h<lim; h++) {
				dp[i] [j]=(dp[i] [j]+dp[lim-h] [j+h]*p[h])%MOD;
			}
			dp[i] [j]=(y*dp[i] [j]+cost+j)%MOD;
		}
	}
	cout << dp[k] [0];
	return 0;
}