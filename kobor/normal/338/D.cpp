#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define PR pair
#define X first
#define Y second

const int N = 1e4+5;

ll t[N];
vector<ll> primePows;
vector<pair<ll, ll>> chinol;

void fact(ll x){
	for(int i = 2; 1ll*i*i <= x; i++){
		if(x % i == 0){
			ll co = 1;
			while(x % i == 0){
				co *= i;
				x /= i;
			}
			primePows.PB(co);
		}
	}
	if(x > 1) primePows.PB(x);
}

ll xgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = xgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll rozwal(){
	ll M = 1, ret = 0;
	TRAV(x, chinol) M *= x.X;
	TRAV(x, chinol){
		ll n = x.X;
		ll Mi = M/n;
		ll f, g;
		xgcd(n, Mi, f, g);
		ll e = (g*Mi % M + M) % M;
		ret = (ret + e * x.Y) % M;
	}
	return ret;
}

void solve(){
	long long n2, m2;
	ll n, m, okI = 1;
	int k;
	cin >> n2 >> m2 >> k;
	n = n2, m = m2;
	FOR(i, 0, k){
		long long aa;
		cin >> aa;
		t[i] = aa;
	}
	ll ech1, ech2;
	FOR(i, 0, k){
		okI = okI * t[i] / xgcd(okI, t[i], ech1, ech2);
		if(okI > n){
			cout << "NO\n";
			return;
		}
	}
	fact(okI);
	TRAV(x, primePows){
		FOR(i, 0, k){
			if(t[i] % x == 0){
				chinol.PB({x, ((-i)%x + x)%x});
				break;
			}
		}
	}
	ll okJ = rozwal();
	if(okJ == 0) okJ += okI;
	if(okI > n || okJ+k-1 > m){
		cout << "NO\n";
		return;
	}
	FOR(i, 0, k){
		if(xgcd(okI, okJ+i, ech1, ech2) != t[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt){
	// 	// cout << "Case #" << te+1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}