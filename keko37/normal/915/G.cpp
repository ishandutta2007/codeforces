#include<iostream>

using namespace std;

typedef long long llint;

const int MAXN = 5000005;
const int MOD = 1000000007;

llint n, k, sol;
llint dp[MAXN], sum[MAXN];

llint add (llint a, llint b) {
	a+=b;
	if (a>=MOD) return a-MOD; return a;
}

llint sub (llint a, llint b) {
	a-=b;
	if (a<0) return a+MOD; return a;
}

llint mul (llint a, llint b) {
	return a*b%MOD;
}

llint pot (llint b, llint e) {
	if (e==0) return 1;
	if (e&1) {
		return mul(pot(b, e-1), b);
	} else {
		llint t=pot(b, e/2);
		return mul(t, t);
	}
}

int main () {
	cin >> n >> k;
	for (int i=1; i<=k; i++) {
		sum[i]=add(sum[i], sum[i-1]);
		dp[i]=add(dp[i], pot(i, n));
		dp[i]=sub(dp[i], sum[i]);
		llint p=((llint) i)*(i+1);
		for (int j=2*i; j<=k; j+=i) {
			int val=j/p;
			sum[j]=add(sum[j], mul(val, dp[i]));
			sum[j+i]=sub(sum[j+i], mul(val, dp[i]));
			int r=j%p/i;
			sum[j]=add(sum[j], dp[i]);
			sum[j+r]=sub(sum[j+r], dp[i]);
		}
		sol=add(sol, (dp[i]^i)%MOD);
	}
	cout << sol;
	return 0;
}