//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll sq = 320;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, a[maxn], b[maxn], lastans;
vector<ll> g[maxn];
vector<pll> vec, q;
bool used[maxn];

ll find(ll x){
	for(ll i = 0; i < q.size(); i++){
		if(q[q.size() - i - 1].F <= x && x <= q[q.size() - i - 1].S){
			if(q[q.size() - i - 1].F == x) x = q[q.size() - i - 1].S;
			else x--;
		}
	}
	return x;
}

int main(){
	fast_io;
	ll t, l, r, k;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	for(ll ii = 0; ii < m; ii++){
		if(ii % sq == 0){
			fill(b, b + n, 0);
			for(ll j = 0; j < vec.size(); j++){
				swap(a[vec[j].F], b[vec[j].S]);
			}
			vec.clear();
			q.clear();
			ll ptr = 0;
			for(ll j = 0; j < n; j++){
				while(ptr < n && a[ptr] == 0) ptr++;
				if(b[j] == 0) b[j] = a[ptr++];
			}
			for(ll j = 0; j < n; j++){
				a[j] = b[j];
			}
			for(ll j = 1; j <= n; j++){
				g[j].clear();
			}
			for(ll j = 0; j < n; j++){
				g[a[j]].pb(j);
			}
		}
		cin >> t >> l >> r;
		l = (l + lastans - 1) % n + 1;
		r = (r + lastans - 1) % n + 1;
		if(l > r) swap(l, r);
		if(t == 1){
			l--;
			r--;
			ll c = -1;
			for(ll i = 0; i < vec.size(); i++){
				if(vec[i].S == r) c = i;
			}
			if(c == -1){
				c = find(r);
				for(ll i = 0; i < vec.size(); i++){
					if(l <= vec[i].S && vec[i].S <= r) vec[i].S++;
				}
				vec.pb(Mp(c, l));
			}
			else{
				for(ll i = 0; i < vec.size(); i++){
					if(l <= vec[i].S && vec[i].S <= r) vec[i].S++;
				}
				vec[c].S = l;
			}
			q.pb(Mp(l, r));
		}
		else{
			l--;
			cin >> k;
			k = (k + lastans - 1) % n + 1;
			for(ll i = 0; i < vec.size(); i++){
				used[vec[i].S] = 1;
			}
			ll s = inf;
			ll e = inf;
			for(ll i = l; i < n; i++){
				if(!used[i]){
					s = find(i);
					break;
				}
			}
			for(ll i = r; i < n; i++){
				if(!used[i]){
					e = find(i);
					break;
				}
			}
			ll x = lower_bound(g[k].begin(), g[k].end(), e) - lower_bound(g[k].begin(), g[k].end(), s);
			for(ll i = 0; i < vec.size(); i++){
				used[vec[i].S] = 0;
				if(a[vec[i].F] == k){
					if(s <= vec[i].F && vec[i].F < e) x--;
					if(l <= vec[i].S && vec[i].S < r) x++;
				}
			}
			cout << x << '\n';
			lastans = x;
		}
	}
	
	return 0;
}