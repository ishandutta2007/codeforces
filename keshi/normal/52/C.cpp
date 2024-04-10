//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, seg[maxn], lz[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		lz[id] += x;
		return;
	}
	seg[id * 2] += lz[id];
	lz[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return inf;
	if(l <= s && e <= r) return seg[id];
	seg[id * 2] += lz[id];
	lz[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	ll mid = (s + e) / 2;
	return min(get(id * 2, s, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}

int main(){
	ll t, l, r, x;
	string s;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		upd(1, 0, n, i, i + 1, x);
	}
	
	cin >> q;
	getline(cin, s);
	
	while(q--){
		getline(cin, s);
		t = 2;
		if(s.find(" ") != s.rfind(" ")) t = 1;
		if(t == 1){
			l = stoi(s.substr(0, s.find(" ")));
			r = stoi(s.substr(s.find(" ") + 1, s.rfind(" ") - s.find(" ") - 1));
			x = stoi(s.substr(s.rfind(" ") + 1, s.size() - s.rfind(" ")));
			if(l <= r) upd(1, 0, n, l, r + 1, x);
			else{
				upd(1, 0, n, 0, r + 1, x);
				upd(1, 0, n, l, n, x);
			}
		}
		else{
			l = stoi(s.substr(0, s.find(" ")));
			r = stoi(s.substr(s.find(" ") + 1, s.size()));
			if(l <= r) cout << get(1, 0, n, l, r + 1) << '\n';
			else{
				cout << min(get(1, 0, n, 0, r + 1), get(1, 0, n, l, n)) << '\n';
			}
		}
	}
	
	return 0;
}