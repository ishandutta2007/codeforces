#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007

using namespace std;

vector<int> u[200005];
int n,p;
long long x[200005],y[200005],t[200005],s[200005];

int main() {
	scanf("%d", &n);
	FO(i,2,n+1) {
		scanf("%d",&p);
		u[p].push_back(i);
	}
	for (int i=n; i; i--) {
		x[i] = 1;
		for (int j : u[i]) (x[i] *= x[j]+1) %= MOD;
	}
	FO(i,1,n+1) {
		y[i]++;
		int l = sz(u[i]);

		t[0] = 1; s[l] = 1;
		FO(j,1,l+1) t[j] = t[j-1] * (1+x[u[i][j-1]]) % MOD;
		for (int j=l;j--;) s[j] = s[j+1] * (1+x[u[i][j]]) % MOD;
		FO(j,0,l) y[u[i][j]] = t[j] * s[j+1] % MOD * y[i] % MOD;
	}
	FO(i,1,n+1) printf("%lld%c", x[i]*y[i]%MOD, " \n"[i==n]);
}