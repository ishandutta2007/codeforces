//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull od(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
FastMod M(mod);

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, l, r, x, a[maxn], c[maxn], fl[maxn], fr[maxn], ans, ps[maxn], sp[maxn], p[maxn], pp[maxn];
vector<pll> g[maxn];


int main(){
	fast_io;
	p[0] = 1;
	pp[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = M.od(p[i - 1] * 2);
		pp[i] = M.od(pp[i - 1] * 499122177);
		
	}
	
	cin >> n >> t >> m;
	for(ll i = 0; i < m; i++){
		cin >> l >> r >> x;
		g[r].pb(Mp(l, x));
	}
	for(ll i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end());
	}
	ans = 1;
	fl[n + 1] = fr[n + 1] = n + 1;
	for(ll k = 0; k < t; k++){
		fill(c, c + n + 1, 0);
		for(ll i = 1; i <= n; i++){
			for(ll j = 0; j < g[i].size(); j++){
				if((g[i][j].S >> k) & 1) c[g[i][j].F]++, c[i + 1]--;
			}
		}
		m = 0;
		for(ll i = 1; i <= n; i++){
			c[i] += c[i - 1];
			if(c[i] == 0) m++;
			fr[i] = m;
		}
		for(ll i = n; i > 0; i--){
			fl[i] = (c[i] ? fl[i + 1] : fr[i]);
		}
		fill(a, a + n + 1, -1);
		for(ll i = 1; i <= n; i++){
			for(ll j = 0; j < g[i].size(); j++){
				if(((g[i][j].S >> k) & 1) == 0){
					if(fl[g[i][j].F] > fr[i]) ans = 0;
					else a[fr[i]] = max(a[fr[i]], fl[g[i][j].F]);
				}
			}
		}
		x = -1;
		for(ll i = 1; i <= n; i++){
			if(a[i] == -1) continue;
			if(x >= a[i]) a[i] = -1;
			else x = a[i];
		}
		ps[0] = 1;
		sp[0] = 1;
		l = 1;
		for(ll i = 1; i <= n; i++){
			if(a[i] == -1){
				ps[i] = ps[i - 1];
				sp[i] = M.od(sp[i - 1] * 499122177);
				continue;
			}
			sp[i] = M.od(sp[i - 1] * 499122177);
			x = M.od(sp[a[i] - 1] * pp[i - a[i] + 1]) - M.od(ps[a[i] - 1] * pp[i - a[i] + 1] + sp[i]);
			if(x < 0) x += mod;
			ps[i] = M.od(ps[i - 1] + x);
			sp[i] = M.od(sp[i - 1] * 499122177 + x);
			l = M.od(l + x);
		}
		l = M.od(l * p[m]);
		ans = M.od(ans * l);
	}
	cout << ans;
	
	return 0;
}