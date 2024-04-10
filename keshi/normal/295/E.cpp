//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

struct dat{
	ll cnt, sum, dis;
};

ll n, m, k, a[maxn], b[maxn];
dat seg[maxn];
vector<ll> p;
vector<pair<ll, pll> > q;
vector<dat> vec;

dat mrg(dat p1, dat p2){
	dat p3;
	p3.cnt = p1.cnt + p2.cnt;
	p3.sum = p1.sum + p2.sum;
	p3.dis = p1.dis + p2.dis + p1.cnt * p2.sum - p1.sum * p2.cnt;
	return p3;
}

void upd(ll id, ll s, ll e, ll l, ll x, ll y){
	if(l < s || e <= l) return;
	if(e - s == 1){
		seg[id].cnt += x;
		seg[id].sum += y;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, x, y);
	upd(id * 2 + 1, mid, e, l, x, y);
	seg[id] = mrg(seg[id * 2], seg[id * 2 + 1]);
	return;
}
void get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		vec.pb(seg[id]);
		return;
	}
	ll mid = (s + e) / 2;
	get(id * 2, s, mid, l, r);
	get(id * 2 + 1, mid, e, l, r);
	return;
}
ll solve(ll l, ll r){
	vec.clear();
	get(1, 0, k, l, r);
	for(ll i = 1; i < vec.size(); i++){
		vec[i] = mrg(vec[i - 1], vec[i]);
	}
	if(vec.empty()) return 0;
	return vec[vec.size() - 1].dis;
}

int main(){
	fast_io;
	ll t, l, r;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		p.pb(b[i]);
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		cin >> t >> l >> r;
		q.pb(Mp(t, Mp(l, r)));
		if(t == 1){
			b[l - 1] += r;
			p.pb(b[l - 1]);
		}
	}
	sort(p.begin(), p.end());
	k = p.size();
	for(ll i = 0; i < n; i++){
		upd(1, 0, k, lower_bound(p.begin(), p.end(), a[i]) - p.begin(), 1, a[i]);
	}
	for(ll i = 0; i < m; i++){
		t = q[i].F;
		l = q[i].S.F;
		r = q[i].S.S;
		if(t == 1){
			upd(1, 0, k, lower_bound(p.begin(), p.end(), a[l - 1]) - p.begin(), -1, -a[l - 1]);
			a[l - 1] += r;
			upd(1, 0, k, lower_bound(p.begin(), p.end(), a[l - 1]) - p.begin(), 1, a[l - 1]);
		}
		else{
			cout << solve(lower_bound(p.begin(), p.end(), l) - p.begin(), upper_bound(p.begin(), p.end(), r) - p.begin()) << '\n';
		}
	}
	
	return 0;
}