//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 4e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll lg = 20;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

bool cmp(const pll a, const pll b){
	return (a.F * b.S < b.F * a.S);
}

ll q, n, m, a[maxn], ps[maxn], s[maxn], f[maxn];
int mn[maxn][lg];
vector<ll> b[maxn];
vector<pll> vec, v2;

ll get(ll l, ll r){
	if(l > r) return 10;
	ll t = f[r - l + 1];
	return min(mn[l][t], mn[r + 1 - (1 << t)][t]);
}

int main(){
	fast_io;
	
	f[1] = 0;
	for(ll i = 2; i < maxn; i++){
		f[i] = f[i / 2] + 1;
	}
	
	cin >> q;
	while(q--){
		cin >> n >> m;
		get(n, m);
		vec.clear();
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			vec.pb(Mp(a[i], 1));
		}
		for(ll i = 0; i < m; i++){
			ll k;
			cin >> k;
			b[i].resize(k);
			s[i] = 0;
			for(ll j = 0; j < k; j++){
				cin >> b[i][j];
				s[i] += b[i][j];
			}
			vec.pb(Mp(s[i], k));
			for(ll j = 0; j < k; j++){
				vec.pb(Mp(s[i] - b[i][j], k - 1));
			}
		}
		sort(all(vec), cmp);
		v2.clear();
		for(pll i : vec){
			if(v2.empty() || cmp(v2.back(), i)) v2.pb(i);
		}
		vec = v2;
		fill(ps, ps + Sz(vec) + 10, 0);
		for(ll i = 0; i < n; i++){
			ll j = lower_bound(all(vec), Mp(a[i], 1), cmp) - vec.begin();
			ps[j]++;
		}
		for(ll i = 0; i < m; i++){
			ll j = lower_bound(all(vec), Mp(s[i], Sz(b[i])), cmp) - vec.begin();
			ps[j]--;
		}
		for(int i = Sz(vec); i--;){
			ps[i] += ps[i + 1];
			mn[i][0] = ps[i];
			for(int j = 1; j < lg; j++){
				if(i + (1 << j) > Sz(vec)) break;
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			}
		}
		for(ll i = 0; i < m; i++){
			ll o = lower_bound(all(vec), Mp(s[i], Sz(b[i])), cmp) - vec.begin();
			for(ll j : b[i]){
				ll p = lower_bound(all(vec), Mp(s[i] - j, Sz(b[i]) - 1), cmp) - vec.begin();
				if(o < p){
					if(get(0, o) >= 0 && get(p + 1, Sz(vec) - 1) >= 0 && get(o + 1, p) >= 1){
						cout << "1";
					}
					else cout << "0";
				}
				else{
					if(get(0, p) >= 0 && get(o + 1, Sz(vec) - 1) >= 0 && get(p + 1, o) >= -1){
						cout << "1";
					}
					else cout << "0";
				}
			}
		}
		cout << "\n";
	}
	
	return 0;
}