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
#define lc (id << 1)
#define rc (lc | 1)

struct clown{
	ll a, b, c, ans1, ans2, ba, bc;
	clown(){
		a = b = c = 0;
		ans2 = inf;
		ans1 = ba = bc = inf;
	}
};

ll n, m;
clown seg[maxn << 2];
string st;

clown mrg(clown l, clown r){
	clown m;
	m.a = l.a + r.a;
	m.b = l.b + r.b;
	m.c = l.c + r.c;
	m.ba = min(l.ba, r.ba + l.a - l.b);
	m.bc = min(l.bc + r.c, r.bc + l.b);
	m.ans1 = min(l.ans1 + r.c, r.ans1 + l.a);
	m.ans1 = min(m.ans1, l.ba + r.bc + l.b);
	m.ans2 = min(l.ans2 + r.c, r.ans2 + l.a);
	m.ans2 = min(m.ans2, l.a + r.c);
	return m;
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		if(st[s] == 'a'){
			seg[id].a = 1;
			seg[id].ba = 0;
		}
		if(st[s] == 'b'){
			seg[id].b = 1;
		}
		if(st[s] == 'c'){
			seg[id].c = 1;
			seg[id].bc = 0;
		}
		return;
	}
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	seg[id] = mrg(seg[lc], seg[rc]);
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = clown();
		if(st[s] == 'a'){
			seg[id].a = 1;
			seg[id].ba = 0;
		}
		if(st[s] == 'b'){
			seg[id].b = 1;
		}
		if(st[s] == 'c'){
			seg[id].c = 1;
			seg[id].bc = 0;
		}
		return;
	}
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r);
	upd(rc, mid, e, l, r);
	seg[id] = mrg(seg[lc], seg[rc]);
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	cin >> st;
	bld(1, 0, n);
	for(ll i = 0; i < m; i++){
		ll x;
		char c;
		cin >> x >> c;
		x--;
		st[x] = c;
		upd(1, 0, n, x, x + 1);
		cout << min({seg[1].a, seg[1].b, seg[1].c, seg[1].ans2, seg[1].ans1}) << "\n";
	}
	
	return 0;
}