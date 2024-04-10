//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll lg = 20;
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

ll n, rnk[lg][maxn], dp[maxn], seg[maxn << 2];
string s;

pair<pll, ll> p[maxn];

ll check(ll i, ll j, ll t){
	for(ll k = 0; k < lg; k++){
		if((t >> k) & 1){
			if(rnk[k][i] == rnk[k][j]){
				i += (1 << k);
				if(i >= n) i -= n;
				j += (1 << k);
				if(j >= n) j -= n;
			}
			else return rnk[k][i] < rnk[k][j];
		}
	}
	return 2;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = x;
		return;
	}
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = max(seg[lc], seg[rc]);
	return;
}
ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) >> 1;
	return max(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}
ll get(ll i, ll t){
	ll l = 0, r = n, mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(check(i, p[mid].S, t)) r = mid;
		else l = mid;
	}
	ll L = r;
	l = 0, r = n;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(check(i, p[mid].S, t) == 1) r = mid;
		else l = mid;
	}
	ll R = r;
	return get(1, 0, n, L, R);
}

int main(){
    fast_io;
    
    cin >> n >> s;
    s += ' ';
    n++;
    for(ll i = 0; i < n; i++){
    	p[i] = {{0, 0}, i};
    	rnk[0][i] = s[i];
	}
	for(ll j = 1; j < lg; j++){
		ll k = (1 << (j - 1)) % n;
		for(ll i = 0; i < n; i++){
			p[i] = {{rnk[j - 1][i], rnk[j - 1][k]}, i};
			k++;
			if(k == n) k = 0;
		}
		sort(p, p + n);
		ll c = 0;
		for(ll i = 0; i < n; i++){
			if(i && p[i - 1].F < p[i].F) c++;
			rnk[j][p[i].S] = c;
		}
	}
	ll ptr = n - 1;
	ll ans = 0;
	for(ll i = n; i--;){
		dp[i] = dp[i + 1] + 1;
		while(dp[i] > 1 && max(get(i + 1, dp[i] - 1), get(i, dp[i] - 1)) < dp[i] - 1){
			dp[i]--;
			ptr = i + dp[i];
			upd(1, 0, n, rnk[lg - 1][ptr], rnk[lg - 1][ptr] + 1, dp[ptr]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
 
    return 0;
}