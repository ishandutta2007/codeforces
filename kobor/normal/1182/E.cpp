#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF=0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define MP make_pair
#define X first
#define Y second

typedef int K;
typedef vector<vector<K>> mat;

const int mod = 1e9+7;
const int modp = 1e9+6;

mat mul(const mat &a, const mat &b){
	mat ret(SZ(a), vector<K>(SZ(b[0])));
	FOR(k, 0, SZ(b)){
		FOR(i, 0, SZ(a)){
			FOR(j, 0, SZ(b[0])) ret[i][j] = (ret[i][j]+1ll*a[i][k]*b[k][j])%modp;
		}
	}
	return ret;
}

mat exp(mat base, ll exp){
	int nx = SZ(base);
	mat ret(nx, vector<K>(nx));
	FOR(i, 0, nx) ret[i][i] = 1;
	while(exp){
		if(exp & 1) ret = mul(ret, base);
		base = mul(base, base);
		exp >>= 1;
	}
	return ret;
}

int pov(ll oldb, int exp){
	int base = oldb % mod, ret = 1;
	while(exp){
		if(exp&1) ret = 1ll*ret*base % mod;
		base = 1ll*base*base % mod;
		exp >>= 1;
	}
	return ret;
}

void solve(){
	ll n, f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	mat xd(14, vector<K>(14));
	FOR(j, 0, 4) xd[j][j] = xd[j][j+4] = xd[j][j+8] = 1;
	xd[3][12] = 1;
	FOR(j, 4, 12) xd[j][j-4] = 1;
	xd[12][12] = xd[12][13] = xd[13][13] = 1;
	xd = exp(xd, n-3);
	mat vec(14, vector<K>(1));
	vec[0][0] = vec[5][0] = vec[10][0] = 1;
	vec[12][0] = vec[13][0] = 2;
	vec = mul(xd, vec);
	int ans = 1ll * pov(f3, vec[0][0]) * pov(f2, vec[1][0]) % mod * pov(f1, vec[2][0]) % mod * pov(c, vec[3][0]) % mod;
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}