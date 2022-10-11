//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, f[maxn];
pll a[maxn];

pll Do(ll x, ll t){
	if(t > 0){
		ll i = lower_bound(a, a + n + 2, Mp(a[x].F + t, inf)) - a - 1;
		if(i == x) return Mp(i, -t);
		return Mp(i, (a[i].F - a[x].F) - t);
	}
	ll i = lower_bound(a, a + n + 2, Mp(a[x].F + t, -inf)) - a;
	if(i == x) return Mp(i, -t);
	return Mp(i, (a[i].F - a[x].F) - t);
}
ll cnt = 0;

ll solve(ll x, ll t, ll o = 0){
	if(o == 2) return x;
	if(t > 0){
		ll i = lower_bound(a, a + n + 2, Mp(a[x].F + t, inf)) - a - 1;
		if(i == x) return solve(x, -t, o + 1);
		ll c = t / (a[i].F - a[x].F);
		ll r = t % (a[i].F - a[x].F);
		if(c & 1) return solve(i, -r);
		return solve(x, r);
	}
	t *= -1;
	ll i = lower_bound(a, a + n + 2, Mp(a[x].F - t, -inf)) - a;
	if(i == x) return solve(x, t, o + 1);
	ll c = t / (a[x].F - a[i].F);
	ll r = t % (a[x].F - a[i].F);
	if(c & 1) return solve(i, r);
	return solve(x, -r);
}

int main(){
    fast_io;
    
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	a[0] = Mp(-inf, 0ll);
	a[n + 1] = Mp(inf, n + 1);
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++){
		f[a[i].S] = i;
	}
	for(ll i = 0; i < m; i++){
		ll x, t;
		cin >> x >> t;
		x = f[x];
		for(ll j = 0; j < 4; j++){
			pll p = Do(x, t);
			x = p.F;
			t = p.S;
		}
		cout << a[solve(x, t)].S << "\n";
	}
 
    return 0;
}