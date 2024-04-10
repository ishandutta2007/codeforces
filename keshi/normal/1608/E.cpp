//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 200;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, c[3], ans, fen[2][maxn];
pair<pll, ll> a[maxn];
vector<ll> vec;

void upd(ll f, ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		fen[f][x] += y;
	}
	return;
}
ll get(ll f, ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[f][x];
	}
	return y;
}

void solve(){
	fill(fen[0], fen[0] + n + 100, 0);
	fill(fen[1], fen[1] + n + 100, 0);
	sort(a, a + n);
	ll x0 = 0, x1 = 0;
	for(ll i = 0; i < n; i++){
		if(a[i].S == c[0]) x0++;
	}
	for(ll i = 0; i < n; i++){
		if(i == 0 || a[i].F.F != a[i - 1].F.F){
			ll l = -1, r = n, mid;
			while(r - l > 1){
				mid = (l + r) >> 1;
				ll p1 = get(1, mid), p2 = x1 - get(0, mid);
				if(p1 <= p2) l = mid;
				else r = mid;
			}
			ans = max(ans, min({x0, get(1, l), x1 - get(0, l)}));
			ans = max(ans, min({x0, get(1, r), x1 - get(0, r)}));
		}
			if(a[i].S == c[0]){
				x0--;
			}
			if(a[i].S == c[1]){
				upd(0, a[i].F.S, 1);
				x1++;
			}
			if(a[i].S == c[2]){
				upd(1, a[i].F.S, 1);
			}
	}
	fill(fen[0], fen[0] + n + 100, 0);
	fill(fen[1], fen[1] + n + 100, 0);
	x0 = 0, x1 = 0;
	for(ll i = 0; i < n; i++){
		if(a[i].S == c[0]) x0++;
	}
	for(ll i = 0; i < n; i++){
		if(i == 0 || a[i].F.F != a[i - 1].F.F){
			ll l = -1, r = n, mid;
			while(r - l > 1){
				mid = (l + r) >> 1;
				ll p1 = get(1, mid), p2 = x1 - get(0, mid);
				if(p1 <= p2) l = mid;
				else r = mid;
			}
			ans = max(ans, min({x0, get(1, l), x1 - get(0, l)}));
			ans = max(ans, min({x0, get(1, r), x1 - get(0, r)}));
		}
			if(a[i].S == c[0]){
				x0--;
			}
			if(a[i].S == c[1]){
				upd(0, a[i].F.F, 1);
				x1++;
			}
			if(a[i].S == c[2]){
				upd(1, a[i].F.F, 1);
			}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F.F >> a[i].F.S >> a[i].S;
		vec.pb(a[i].F.F);
	}
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for(ll i = 0; i < n; i++){
		a[i].F.F = lower_bound(all(vec), a[i].F.F) - vec.begin();
	}
	vec.clear();
	for(ll i = 0; i < n; i++){
		vec.pb(a[i].F.S);
	}
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for(ll i = 0; i < n; i++){
		a[i].F.S = lower_bound(all(vec), a[i].F.S) - vec.begin();
	}
	c[0] = 1;
	c[1] = 2;
	c[2] = 3;
	do{
		for(ll t = 0; t < 2; t++){
			for(ll o = 0; o < 2; o++){
				solve();
				for(ll i = 0; i < n; i++){
					a[i].F.F = n - 1 - a[i].F.F;
				}
			}
			for(ll i = 0; i < n; i++){
				swap(a[i].F.F, a[i].F.S);
			}
		}
	}while(next_permutation(c, c + 3));
	cout << ans * 3;
	
	return 0;
}