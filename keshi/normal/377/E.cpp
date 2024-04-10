//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ld eps = 1e-5;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

struct line{
	mutable ll a, b, c, d;
	bool operator<(ll x) const {return d < x; }
};

ll n, p;
pll a[maxn], dp[maxn];
vector<line> vec;
vector<pll> v2;

ll cal(line x, line y){
	return (x.c * y.c * (x.a - y.a) + y.b * x.c - x.b * y.c) / (x.c - y.c);
}
void add(line x){
	if(vec.empty()){
		vec.pb(x);
		return;
	}
	while(Sz(vec) > 1){
		vec[Sz(vec) - 1].d = cal(vec[Sz(vec) - 1], x);
		if(vec[Sz(vec) - 2].d >= vec[Sz(vec) - 1].d) vec.pop_back();
		else break;
	}
	vec[Sz(vec) - 1].d = cal(vec[Sz(vec) - 1], x);
	vec.pb(x);
	return;
}
ll get(ll x){
	line l = *lower_bound(all(vec), x);
	return l.a + (x - l.b + l.c - 1) / l.c;
}

int main(){
    fast_io;

	cin >> n >> p;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
	}
	sort(a, a + n);
	ll e = inf;
	for(ll i = n; i--;){
		if(a[i].S < e && (i == 0 || a[i].F != a[i - 1].F)){
			v2.pb(a[i]);
			e = a[i].S;
		}
	}
	reverse(all(v2));
	for(pll i : v2){
		if(i.S == 0){
			add({0, 0, i.F, inf});
			continue;
		}
		ll x = get(i.S);
		ll l = 0, r = mod, mid;
		while(r - l > 1){
			mid = (l + r) >> 1;
			if(get(i.S + mid) == x) l = mid;
			else r = mid;
		}
		add({x, l, i.F, inf});
	}
	cout << get(p);


    return 0;
}