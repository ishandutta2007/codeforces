#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

int h, w, k, res;
ll f[1000005], vf[1000005];
ll g[1005][1005];

ll pw(ll i, ll j) {
	ll r = 1;
	while (j) {
		if (j&1) r  = r*i%MOD;
		i = i*i%MOD;
		j/=2;
	}
	return r;
}

ll l(int i) { return f[i] * g[h-i][i] % MOD; }

ll sl[1005];

ll c(int i, int j) {
	if (j > i) return 0;
	return f[i]*vf[i-j]%MOD*vf[j]%MOD;
}

int main() {
	f[0] = vf[0] = 1;
	FO(i,1,1000005) vf[i] = pw(f[i] = f[i-1]*i%MOD,MOD-2);
	FO(i,0,1005) g[i][1] = g[0][i] = 1;
	FO(i,1,1005) FO(j,2,1005) g[i][j] = (g[i][j-1] + j*g[i-1][j])%MOD;
	scanf("%d%d%d", &h, &w, &k);
	FO(i,1,h+1) FO(j,1,i+1) sl[i] = (sl[i] + c(i,j) * l(j)) % MOD;
	if (w == 1) {
		FO(i,1,h+1) res = (res+c(k,i)*l(i))%MOD;
	} else {
		FO(i,1,h+1) {
			FO(j,0,i+1) {
				ll ca = c(k,i)*c(i,j)%MOD*c(k-i,i-j)%MOD;
				ll vl = pw(l(i),2)*pw(sl[j],w-2)%MOD;
				res = (res+ca*vl)%MOD;
			}
		}
	}
	printf("%d\n", res);
}