//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c[maxn], s, t, cnt[maxn], ps[maxn], mp[maxn], ans;
pll a[maxn], b[maxn];
vector<pll> g[maxn];

void uc(ll x, ll y){
	for(; x < maxn; x += x & -x){
		cnt[x] += y;
	}
	return;
}
ll gc(ll x){
	ll y = 0;
	for(; x > 0; x -= x & -x){
		y += cnt[x];
	}
	return y;
}
void us(ll x, ll y){
	for(; x < maxn; x += x & -x){
		ps[x] += y;
	}
	return;
}
ll gs(ll x){
	ll y = 0;
	for(; x > 0; x -= x & -x){
		y += ps[x];
	}
	return y;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
		g[a[i].F].pb(Mp(a[i].S, i));
		b[i] = Mp(a[i].S, i);
	}
	sort(b, b + n);
	for(ll i = 0; i < n; i++){
		if(a[b[i].S].F == 1) continue;
		uc(i + 1, 1);
		us(i + 1, b[i].F);
		mp[b[i].S] = i + 1;
	}
	for(ll i = 1; i <= m; i++){
		sort(g[i].begin(), g[i].end(), greater<pll>());
	}
	ans = inf;
	t = g[1].size();
	for(ll i = n; i > 0; i--){
		for(ll j = 2; j <= m; j++){
			if(g[j].size() == i){
				s += g[j].back().F;
				uc(mp[g[j].back().S], -1);
				us(mp[g[j].back().S], -g[j].back().F);
				t++;
				g[j].pop_back();
			}
		}
		if(t >= i){
			ans = min(ans, s);
			continue;
		}
		ll l = 0, r = n, mid;
		while(r - l > 1){
			mid = (l + r) / 2;
			if(gc(mid) + t >= i) r = mid;
			else l = mid;
		}
		ans = min(ans, s + gs(r));
	}
	cout << ans;
	
	return 0;
}