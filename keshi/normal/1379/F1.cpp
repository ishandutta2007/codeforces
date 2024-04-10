//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, q, mn[maxn], mx[maxn];
set<ll> st[2][maxn];
bool ok[maxn];

void upd(ll id, ll s, ll e, ll i){
	if(i < s || e <= i) return;
	if(e - s == 1){
		mn[id] = *st[0][s].begin();
		mx[id] = *st[1][s].rbegin();
		ok[id] = (mx[id] < mn[id]);
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, i);
	upd(id * 2 + 1, mid, e, i);
	mn[id] = min(mn[id * 2], mn[id * 2 + 1]);
	mx[id] = max(mx[id * 2], mx[id * 2 + 1]);
	ok[id] = (ok[id * 2] && ok[id * 2 + 1] && (mx[id * 2 + 1] < mn[id * 2]));
	return;
}

int main(){
	fast_io;
	ll x, y;
	fill(mn, mn + maxn, inf);
	fill(mx, mx + maxn, -inf);
	fill(ok, ok + maxn, 1);
	cin >> n >> m >> q;
	for(ll i = 0; i < n; i++){
		st[0][i].insert(inf);
		st[1][i].insert(-inf);
	}
	for(ll i = 0; i < q; i++){
		cin >> x >> y;
		x--;
		y--;
		if(st[x % 2][x / 2].find(y / 2) == st[x % 2][x / 2].end()) st[x % 2][x / 2].insert(y / 2);
		else st[x % 2][x / 2].erase(y / 2);
		upd(1, 0, n, x / 2);
		cout << (ok[1] ? "YES\n" : "NO\n");
	}
	
	return 0;
}