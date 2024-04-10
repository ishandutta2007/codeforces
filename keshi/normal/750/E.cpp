//In the name of God
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
typedef pair<ll, ll> pll;
 
const ll maxn = 2e5 + 100;
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
#define lc (id << 1)
#define rc (lc | 1)
 
struct node{
	ll dp[5][5];
	node(){
		for(ll i = 0; i < 5; i++){
			for(ll j = 0; j < 5; j++){
				dp[i][j] = inf;
			}
		}
	}
};

ll n, m;
node seg[maxn << 2];
string st, f = "2017 ", f2 = "20166";

node merge(node l, node r){
	node c;
	for(ll i = 0; i < 5; i++){
		for(ll j = i; j < 5; j++){
			for(ll k = j; k < 5; k++){ 
				c.dp[i][k] = min(c.dp[i][k], l.dp[i][j] + r.dp[j][k]);
			}
		}
	}
	return c;
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		for(ll i = 0; i < 5; i++){
			if(st[s] == f[i]){
				seg[id].dp[i][i + 1] = 0;
				seg[id].dp[i][i] = 1;
			}
			else if(st[s] == f2[i]){
				seg[id].dp[i][i] = 1;
			}
			else{
				seg[id].dp[i][i] = 0;
			}
		}
		return;
	}
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	seg[id] = merge(seg[lc], seg[rc]);
	return;
}

node get(ll id, ll s, ll e, ll l, ll r){
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) >> 1;
	if(r <= mid) return get(lc, s, mid, l, r);
	if(l >= mid) return get(rc, mid, e, l, r);
	return merge(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}
 
int main(){
    fast_io;
 
	cin >> n >> m >> st;
	bld(1, 0, n);
	for(ll i = 0; i < m; i++){
		ll l, r;
		cin >> l >> r;
		ll x = get(1, 0, n, l - 1, r).dp[0][4];
		if(x == inf) x = -1;
		cout << x << "\n";
	}
 
    return 0;
}