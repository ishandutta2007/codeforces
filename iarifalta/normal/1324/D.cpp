#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 4e5 + 10;
const ll big = 1e18;
const ll block = 100;
const ll mod = 1e6;

ll ans;
ll n;
ll a[N];
ll b[N];
ll c[N];

pill szh[N];

struct seg {
	ll t[4 * N];
	void init(){
		for(int i = 0 ; i < 4 * N ; i++)
			t[i] = 0;
		return ;
	}
	ll sum(ll l ,ll r, ll v = 1, ll tl = 0 , ll tr = N - 1) {
		if(l > r)
			return 	0;
		if(l == tl && tr == r)
			return t[v];
		ll m = (tl + tr) / 2;
		return sum(l , min(m , r) , v * 2 , tl , m) +
		       sum(max(l , m + 1) , r , v * 2 + 1 , m + 1, tr);
	}
	void upd(ll pos , ll v = 1, ll tl = 0 , ll tr = N - 1) {
		if(pos > tr || pos < tl)
			return;
		if(tl == tr) {
			t[v]++;
			return;
		}
		ll m = (tl + tr) / 2;
		upd(pos ,  v * 2 , tl , m);
		upd(pos , v * 2 + 1 , m + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
} r;

int main() {
	speed;
	r.init();
	cin >> n;
	ll d[n];
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(int j = 0 ; j < n ; j++)
		cin >> b[j];
	for(int j = 0 ; j < n ; j++) {
		szh[j] = {a[j] - b[j] , j};
		szh[j + n] = {b[j] - a[j] , j + n};
	}
	sort(szh,szh + 2 * n);
	ll x = 1;

	if(szh[0].s >= n)
		d[szh[0].s - n] = x;
	else
		c[szh[0].s] = x;
	
	for(int i = 1 ; i < 2 * n ; i++) {
		if(szh[i - 1].f != szh[i].f)
			x++;
		if(szh[i].s >= n)
			d[szh[i].s - n] = x;
		else
			c[szh[i].s] = x;
	}
	
	for(int i = 0 ; i < n ; i++){
		ans += r.sum(0 , c[i] - 1);
		r.upd(d[i]);	
	}
	cout << ans;
}
/*
	3
	3 2 1
	1 2 3

	2 0 -2
	-2 -2 0 2
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/