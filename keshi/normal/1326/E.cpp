//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
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
#define lc (id << 1)
#define rc (lc | 1)

ll n, seg[maxn << 2], mn[maxn << 2], q[maxn];
pll a[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		mn[id] += x;
		return;
	}
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	mn[id] = min(mn[lc], mn[rc]) + seg[id];
	return;
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i].F;
    	a[i].S = i + 1;
	}
	sort(a, a + n, greater<pll>());
	ll ptr = 0;
	for(ll i = 0; i < n; i++){
		do{
			upd(1, 0, n, 0, a[ptr++].S, -1);
		}while(mn[1] >= 0);
		upd(1, 0, n, 0, a[--ptr].S, 1);
		cout << a[ptr].F << " ";
		cin >> q[i];
		upd(1, 0, n, 0, q[i], 1);
	}
    
 
    return 0;
}