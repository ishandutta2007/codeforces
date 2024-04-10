#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0) 
#define sz(a) (ll)(a).size()
#define triple pair<pill, ll>
#define pinode pair<node*, node*>
#define quadra pair<pill, pill>
using namespace std;
 
const ll N = 1e5 + 10;
const ll M = 1e6 + 11;
const ll big = 1e17;
const ll hsh2 = 1964325029 ;
const long long mod = 1e9 + 7;
const double EPS = 1e-9;
const ll block = 1e14;
const ll shift = 2e3;
const double pi = acos(-1.0);


ll p[6][N];
ll n;
pair<pill, pill> x[N];
bool was[N];

struct seg {
	ll t[4 * N];
	void build(ll v = 1, ll l = 1, ll r = 50000) {
		if(l == r) {
			t[v] = 50001;
			return;
		}
		ll m = (l + r) >> 1ll;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		t[v] = 50001;
	}
	void upd(ll pos, ll z, ll v = 1, ll l = 1, ll r = 50000) {
		if(l == r) {
			t[v] = z;
			return;
		}
		ll m = (l + r) >> 1ll;
		if(pos <= m)
			upd(pos, z, v * 2, l, m);
		else
			upd(pos, z, v * 2 + 1, m + 1, r);
		t[v] = min(t[v * 2], t[v * 2 + 1]);	
   }
   ll get(ll l, ll r, ll v = 1, ll tl = 1, ll tr = 50000) {
		if(l > tr || tl > r || l > r)
			return 50001;   
		if(l <= tl && tr <= r)
			return t[v];
		ll m = (tl + tr) >> 1ll;
		return min(get(l, r, v * 2, tl, m), get(l, r, v * 2 + 1, m + 1, tr));
   }
} rt;


int main() {                                                       
	speed;
	ll t;
	rt.build();
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			was[i] = 0;
	    for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 5; j++) {
				cin >> p[j][i];
			}
		}
		for(int k1 = 1; k1 <= 5; k1++) {
			for(int k2 = k1 + 1; k2 <= 5; k2++) {
				for(int k3 = k2 + 1; k3 <= 5; k3++) {
					for(int i = 1; i <= n; i++) {   	
						x[i].f.f = p[k1][i];
						x[i].f.s = p[k2][i];
						x[i].s.f = p[k3][i];
						x[i].s.s = i;
					}
					sort(x + 1, x + n + 1);
					for(int i = 1; i <= n; i++) {
						ll q1 = x[i].f.s;
						ll q2 = x[i].s.f;
						ll z = rt.get(1, q1 - 1);
						rt.upd(q1, min(rt.get(q1, q1), q2));
						if(z < q2) {
							was[x[i].s.s] = 1;
						
						}
					}
					for(int i = 1; i <= n; i++)
						rt.upd(x[i].f.s, 50001);
				}
			}
		}
		ll ans = -1;
		for(int i = 1; i <= n; i++)
			if(!was[i])
				ans = i;
		cout << ans << '\n';
	}
}   	
/*                  
4
4 6 1 9
2 5 3 2 
*/