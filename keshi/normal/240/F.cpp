//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, cnt[26][maxn], lz[26][maxn], t[26];

string s;

void upd(ll c, ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		cnt[c][id] = x * (e - s);
		lz[c][id] = x;
		return;
	}
	ll mid = (s + e) / 2;
	if(lz[c][id] != -1){
		cnt[c][id * 2] = lz[c][id] * (mid - s);
		cnt[c][id * 2 + 1] = lz[c][id] * (e - mid);
		lz[c][id * 2] = lz[c][id];
		lz[c][id * 2 + 1] = lz[c][id];
		lz[c][id] = -1;
	}
	upd(c, id * 2, s, mid, l, r, x);
	upd(c, id * 2 + 1, mid, e, l, r, x);
	cnt[c][id] = cnt[c][id * 2] + cnt[c][id * 2 + 1];
	return;
}
ll get(ll c, ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return cnt[c][id];
	ll mid = (s + e) / 2;
	if(lz[c][id] != -1){
		cnt[c][id * 2] = lz[c][id] * (mid - s);
		cnt[c][id * 2 + 1] = lz[c][id] * (e - mid);
		lz[c][id * 2] = lz[c][id];
		lz[c][id * 2 + 1] = lz[c][id];
		lz[c][id] = -1;
	}
	return get(c, id * 2, s, mid, l, r) + get(c, id * 2 + 1, mid, e, l, r);
}

int main(){
	ll x, l, r, c;
	fast_io;
	file_io;
	for(ll i = 0; i < 26; i++){
		fill(lz[i], lz[i] + maxn, -1);
	}
	
	cin >> n >> m >> s;
	
	for(ll i = 0; i < n; i++){
		x = s[i] - 'a';
		upd(x, 1, 0, n, i, i + 1, 1);
	}
	
	for(ll i = 0; i < m; i++){
    	cin >> l >> r;
		l--;
		c = 0;
		for(ll j = 0; j < 26; j++){
			t[j] = get(j, 1, 0, n, l, r);
			if((t[j] & 1) && c++) break;
		}
		if(c > 1) continue;
		x = 0;
		for(ll j = 0; j < 26; j++){
			c = t[j] / 2;
			upd(j, 1, 0, n, l, r, 0);
			if(c) upd(j, 1, 0, n, l + x, l + x + c, 1);
			if(c) upd(j, 1, 0, n, r - x - c, r - x, 1);
			if(t[j] & 1) upd(j, 1, 0, n, (l + r) / 2, (l + r) / 2 + 1, 1);
			x += c;
		}
	}
	
	for(ll i = 0; i < n; i++){
		x = 0;
		for(ll j = 0; j < 26; j++){
			if(get(j, 1, 0, n, i, i + 1)) x = j;
		}
		cout << char('a' + x);
	}
	
	return 0;
}