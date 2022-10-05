#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll M = ll(1e9) + 7;

int n, mt, mu, mtu;
ll a[22], as[22], b[2][22], bs[2][22], d[2][22], e[2][22][2];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x = i;
		int t = 0; while(x % 2 == 0){ x /= 2; t++; }
		int u = 0; if(x % 3 == 0){ x /= 3; u++; }
		a[t]++;
		b[u][t]++;
		mt = max(mt, t);
		mu = max(mu, u);
		if(u) mtu = max(mtu, t + u);
	}
	for(int i = 20; i >= 0; i--){
		as[i] = (as[i + 1] + a[i]) % M;
		bs[0][i] = (bs[0][i + 1] + b[0][i]) % M;
		bs[1][i] = (bs[1][i + 1] + b[1][i]) % M;
	}
	d[1][mt] = 1;
	if(mtu == mt) e[1][mt-1][mu] = 1;
	for(int i = 1; i < n; i++){
		memset(d[~i&1], 0, sizeof(d[~i&1]));
		memset(e[~i&1], 0, sizeof(e[~i&1]));
		for(int j = 0; j <= 20; j++){
			(d[~i&1][j] += d[i&1][j] * (as[j] + M - i)) %= M;
			if(j) (d[~i&1][j-1] += d[i&1][j] * a[j-1]) %= M;
			
			(e[~i&1][j][0] += e[i&1][j][0] * (bs[0][j] + bs[1][j] + M - i)) %= M;
			(e[~i&1][j][1] += e[i&1][j][1] * (bs[1][j] + M - i)) %= M;
			(e[~i&1][j][0] += e[i&1][j][1] * bs[0][j]) %= M;
			if(j){
				(e[~i&1][j-1][1] += e[i&1][j][1] * b[1][j-1]) %= M;
				(e[~i&1][j-1][0] += e[i&1][j][0] * (b[0][j-1] + b[1][j-1])) %= M;	
			}
		}
	}
	if(mtu != mt) printf("%lld\n", d[n&1][0]);
	else printf("%lld\n", (d[n&1][0] + e[n&1][0][0]) % M);
}