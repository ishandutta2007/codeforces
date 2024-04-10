//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 8e4 + 100;
const ll mod = 777777777;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, a[maxn], dp[4][4][maxn], seg[4 * maxn];

set<ll> s;

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = x;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = (seg[id * 2] * seg[id * 2 + 1]) % mod;
	return;
}

int main(){
	ll v, u, l, r;
	fast_io;
	fill(seg, seg + 4 * maxn, 1);
	
	cin >> n >> q;
	
	for(ll i = 1; i <= 3; i++){
		dp[0][i][1] = 1;
		dp[i][0][1] = 1;
		for(ll j = 1; j <= 3; j++){
			cin >> dp[i][j][1];
		}
	}
	
	for(ll i = 2; i < maxn; i++){
		for(ll j = 0; j < 4; j++){
			for(ll k = 0; k < 4; k++){
				for(ll o = 1; o < 4; o++){
					dp[j][k][i] = (dp[j][k][i] + dp[o][k][i - 1] * dp[j][o][1]) % mod;
				}
			}
		}
	}
	s.insert(0);
	s.insert(n + 1);
	n += 2;
	upd(1, 0, n, n - 1, n, dp[0][0][n + 1]);
	
	for(ll i = 0; i < q; i++){
		cin >> v >> u;
		if(u){
			a[v] = u;
			r = *s.upper_bound(v);
			l = *(--s.lower_bound(v));
			upd(1, 0, n, v, v + 1, dp[a[l]][a[v]][v - l]);
			upd(1, 0, n, r, r + 1, dp[a[v]][a[r]][r - v]);
			s.insert(v);
		}
		else{
			a[v] = u;
			r = *s.upper_bound(v);
			l = *(--s.lower_bound(v));
			upd(1, 0, n, v, v + 1, 1);
			upd(1, 0, n, r, r + 1, dp[a[l]][a[r]][r - l]);
			if(s.find(v) != s.end()) s.erase(v);
		}
		cout << seg[1] << '\n';
	}
	
	return 0;
}