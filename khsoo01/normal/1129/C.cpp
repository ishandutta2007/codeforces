#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;

const ll fbd[4][4] = {{0, 0, 1, 1,}, {0, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};
const ll mod = 1e9+7, M1 = 179426447, M2 = 1e9+9;

typedef long long ll;
typedef pair<int, int> pii;

ll n, a[3002], ans, dt[2][3002][4];

ll p1[3002] = {1}, p2[3002] = {1}, m1[3002] = {1}, m2[3002] = {1};
pii h[3002];

set<pii> s;

ll calc (ll X, ll Y, ll P) {
	if(!Y) return 1;
	ll R = calc(X, Y/2, P);
	R = R * R % P;
	if(Y % 2) R = R * X % P;
	return R;
}

pii operator + (pii A, ll B) {
	pii R;
	R.X = (A.X * 3ll + B + 1) % M1;
	R.Y = (A.Y * 3ll + B + 1) % M2;
	return R;
}

pii subs (pii A, pii B, int L1, int L2) {
	pii R;
	R.X = ((A.X - B.X * p1[L1-L2]) % M1 + M1) % M1;
	R.Y = ((A.Y - B.Y * p2[L1-L2]) % M2 + M2) % M2;
	return R;
}

pii Hash (ll S, ll E) {
	return subs(h[E], h[S-1], E, S-1);
}

int main()
{
	scanf("%lld",&n);
	p1[1] = 3;
	p2[1] = 3;
	m1[1] = calc(3, M1-2, M1);
	m2[1] = calc(3, M2-2, M2);
	for(ll i=1;i<=n;i++) {
		p1[i] = p1[i-1] * p1[1] % M1;
		p2[i] = p2[i-1] * p2[1] % M2;
		m1[i] = m1[i-1] * m1[1] % M1;
		m2[i] = m2[i-1] * m2[1] % M2;
	}
	for(ll i=1;i<=n;i++) {
		char T[5];
		scanf("%s",T);
		a[i] = (T[0] - '0');
	}
	dt[0][0][0] = 1;
	for(ll i=1;i<=n;i++) {
		ll CB = (i&1);
		dt[CB][0][0] = 1;
		h[i] = h[i-1] + a[i];
		ll MAT = 0;
		for(ll j=i-1;j>=1;j--) {
			if(MAT+1 > j) break;
			if(Hash(j - MAT, j) == Hash(i - MAT, i)) {
				MAT++;
				j++;
			}
		}
		bool F = false;
		if(i >= 4) {
			for(ll x = 0; x < 4; x++) {
				bool T = false;
				for(ll y = 0; y < 4; y++) {
					if(a[i-3+y] != fbd[x][y]) {
						T = true;
						break;
					}
				}
				if(!T) {
					F = true;
					break;
				}
			}
		}
		for(ll k=1;k<=i;k++) {
			for(ll j=0;j<4;j++) dt[CB][k][j] = 0;
			for(ll j=0;j<4;j++) {
				if(j < 3) {
					dt[CB][k][j+1] = (dt[CB][k][j+1] + dt[CB^1][k-1][j]) % mod;
					dt[CB][k][0] = (dt[CB][k][0] + dt[CB^1][k-1][j]) % mod;
				}
				else if(!F) {
					dt[CB][k][0] = (dt[CB][k][0] + dt[CB^1][k-1][j]) % mod;
				}
			}
			if(k > MAT) ans = (ans + dt[CB][k][0]) % mod;
		}
		printf("%lld\n",ans);
	}
}