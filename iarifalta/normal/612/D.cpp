#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 181;
const ll big = 1e9;
const ll block = 100;
const ll mod = 1e6;

ll n;
ll k;

int main() {
	speed;
	cin >> n >> k;
	vector<pill> a , b;
	for(int i = 0 ; i < n ; i++){
		ll l,r;
		cin >> l >> r;
		a.pb({l,1});
		a.pb({r,-1});
	}
	sort(a.begin(),a.end());
	ll v = a[0].f , j = max(0ll , a[0].s) , x = min(0ll, a[0].s);
	for(int i = 1 ; i < n * 2 ; i++){
		if(a[i].f == a[i - 1].f){
			if(a[i].s == 1)
				j++;
			else
				x--;
		}
		else{
			if(j != 0)b.pb({v, j});
			if(x != 0)b.pb({v, x});
			v = a[i].f;
			j = max(0ll , a[i].s) , x = min(0ll, a[i].s);
		}
	}
	if(j != 0)b.pb({v, j});
	if(x != 0)b.pb({v, x});
	a = b;
	ll xx = 0;
	ll s = big;
	vector<pill> ans;
	for(int i = 0 ; i < a.size() ; i++){
		xx += a[i].s ;
		if(xx >= k && s == big)
			s = a[i].f;
		if(s != big && xx < k){
			ans.pb({s , a[i].f}),s = big;
		}
	}

	cout << ans.size() << '\n';
	for(auto u : ans)
		cout << u.f << " " << u.s << '\n';
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/