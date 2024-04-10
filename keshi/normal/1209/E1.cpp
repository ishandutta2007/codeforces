//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5;
const ll maxm = 105;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define val first
#define x second.first
#define y second.second

ll q;

bool ch(ll t, ll k, ll n){
	if((t + 1) % n == k || (k + 1) % n == t){
		return 1;
	}
	return 0;
}

int solve(){
	ll n, m, a[maxn][maxm], ans = 0;

	vector< pair<ll, pll> > v;
	
	map<ll, ll> ma;
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cin >> a[i][j];
			v.pb({a[i][j], {i, j}});
		}
	}
	
	sort(v.begin(), v.end(), greater< pair<ll, pll> >());
	
	for(ll i = 0; i < n; i++){
		ans += v[i].val;
		ma[v[i].y]++;
	}
		
	if(n < 4){
		cout << ans;
		return 0;
	}
	
	for(map<ll, ll>::iterator i = ma.begin(); i != ma.end(); i++){
		if(i -> second != 2){
			cout << ans;
			return 0;
		}
	}
	
	vector<pair<ll, pll> > c, d;
	
	for(ll i = 0; i < n; i++){
		if(v[i].y == v[0].y){
			c.pb(v[i]);
		}
		else{
			d.pb(v[i]);
		}
	}
	if(ch(c[0].x, c[1].x, n) == ch(d[0].x, d[1].x, n)){
		cout << ans;
		return 0;
	}
	
	if(ch(c[0].x, c[1].x, n)){
		swap(c, d);
	}
	ll s = 0;
	
	for(ll j = 4; j < n * m; j++){
		if(v[j].y == d[0].y){
			if(ch(v[j].x, d[0].x, n)){
				s = max(s, ans + v[j].val - d[0].val);
			}
			else{
				s = max(s, ans + v[j].val - d[1].val);
			}
			s = max(s, ans + v[j].val - min(c[0].val, c[1].val));
		}
		else{
			s = max(s, ans + v[j].val - min(min(d[0].val, d[1].val), min(c[0].val, c[1].val)));
		}
	}
	cout << s;
	return 0;
}

int main(){
	fast_io;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}