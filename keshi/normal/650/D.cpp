//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll n, m, a[maxn], ans[maxn], f1[maxn], f2[maxn], c[maxn], d[maxn], cnt[maxn], lis;
pll q[maxn];
vector<ll> vec, g[maxn];

void upd1(ll x, ll y){
	for(x += 5; x < maxn; x += x & -x){
		f1[x] = max(f1[x], y);
	}
	return;
}
ll get1(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y = max(y, f1[x]);
	}
	return y;
}
void upd2(ll x, ll y){
	x = Sz(vec) - x - 1;
	for(x += 5; x < maxn; x += x & -x){
		f2[x] = max(f2[x], y);
	}
	return;
}
ll get2(ll x){
	ll y = 0;
	x = Sz(vec) - x - 1;
	for(x += 5; x > 0; x -= x & -x){
		y = max(y, f2[x]);
	}
	return y;
}


int main(){
    fast_io;

	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		vec.pb(a[i]);
	}
	for(ll i = 0; i < m; i++){
		cin >> q[i].F >> q[i].S;
		q[i].F--;
		vec.pb(q[i].S);
	}
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for(ll i = 0; i < n; i++){
		a[i] = lower_bound(all(vec), a[i]) - vec.begin();
	}
	for(ll i = 0; i < m; i++){
		q[i].S = lower_bound(all(vec), q[i].S) - vec.begin();
		g[q[i].F].pb(i);
	}
	for(ll i = 0; i < n; i++){
		for(ll j : g[i]){
			ans[j] += get1(q[j].S - 1);
		}
		c[i] = get1(a[i] - 1);
		upd1(a[i], c[i] + 1);
	}
	lis = get1(Sz(vec));
	for(ll i = n; i--;){
		for(ll j : g[i]){
			ans[j] += get2(q[j].S + 1);
		}
		d[i] = get2(a[i] + 1);
		if(c[i] + d[i] == lis - 1) cnt[c[i]]++;
		upd2(a[i], d[i] + 1);
	}
	for(ll i = 0; i < m; i++){
		ans[i]++;
		ll j = q[i].F;
		if(c[j] + d[j] == lis - 1){
			if(cnt[c[j]] == 1) ans[i] = max(ans[i], lis - 1);
			else ans[i] = max(ans[i], lis);
		}
		else ans[i] = max(ans[i], lis);
		cout << ans[i] << "\n";
	}


    return 0;
}