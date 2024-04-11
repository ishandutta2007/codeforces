#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

vector<ll> collide;
ll nww, gdd;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int pov(int base, int exp, int mod){
	int ret = 1;
	while(exp){
		if(exp & 1) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod;
		exp >>= 1;
	}
	return ret;
}

ll ile(ll kiedy){
	if(SZ(collide) == 0) return kiedy;
	ll niet = kiedy / nww * SZ(collide);
	niet += lower_bound(collide.begin(), collide.end(), kiedy % nww) - collide.begin();
	return kiedy - niet;
}

void solve(){
	int n, m;
	ll k;
	cin >> n >> m >> k;
	gdd = gcd(n, m);
	nww = 1ll * n * m / gdd;
	vi czas(2*max(n, m)+2, -1);
	int n1 = n / gdd;
	int m1 = m / gdd;
	int inv_m1 = pov(m1, phi(n1)-1, n1);
	FOR(i, 0, n){
		int a; cin >> a;
		czas[a] = i;
	}
	FOR(j, 0, m){
		int a; cin >> a;
		if(czas[a] == -1) continue;
		int i = czas[a];
		if((i-j) % gdd != 0) continue;
		int lewa = (i-j) / gdd;
		int k2 = 1ll * lewa * inv_m1 % n1;
		k2 *= -1;
		ll col = j - 1ll * k2 * m;
		col = (col % nww + nww) % nww;
		collide.PB(col);
	}
	sort(collide.begin(), collide.end());
	ll l = 0, r = 1e18, mid;
	while(l+1 < r){
		mid = (l+r) / 2;
		if(ile(mid) < k) l = mid;
		else r = mid;
	}
	cout << r << '\n';
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