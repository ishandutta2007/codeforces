//In the name of GOD
//Hello 2020
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll level = 18;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, mn[maxn][level], mx[maxn][level], p[maxn];

pair<pll, pll> a[maxn];

vector<ll> v;

ll Mn(ll l, ll r){
	ll t = p[r - l];
	return min(mn[l][t], mn[r - (1 << t)][t]);
}
ll Mx(ll l, ll r){
	ll t = p[r - l];
	return max(mx[l][t], mx[r - (1 << t)][t]);
}

int main(){
	ll l, r;
	fast_io;
	
	p[1] = 0;
	
	for(ll i = 2; i < maxn; i++){
		p[i] = p[i / 2] + 1;
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F.F >> a[i].F.S >> a[i].S.F >> a[i].S.S;
	}
	
	sort(a, a + n);
	
	for(ll i = 0; i < n; i++){
		mn[i][0] = a[i].S.S;
		mx[i][0] = a[i].S.F;
	}
	
	for(ll i = 1; i < level; i++){
		for(ll j = 0; j + (1 << i) <= n; j++){
			mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
			mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
		}
	}
	
	for(ll i = 0; i < n; i++){
		v.pb(a[i].F.F);
	}
	
	for(ll i = 0; i < n; i++){
		if(v.back() <= a[i].F.S) r = n;
		else (r = upper_bound(v.begin(), v.end(), a[i].F.S) - v.begin());
		if(r > i + 1 && Mn(i + 1, r) < a[i].S.F){
			cout << "NO";
			return 0;
		}
		if(r > i + 1 && Mx(i + 1, r) > a[i].S.S){
			cout << "NO";
			return 0;
		}
	}
	
	v.clear();
	
	for(ll i = 0; i < n; i++){
		swap(a[i].F, a[i].S);
	}
	
	sort(a, a + n);
	
	for(ll i = 0; i < n; i++){
		mn[i][0] = a[i].S.S;
		mx[i][0] = a[i].S.F;
	}
	
	for(ll i = 1; i < level; i++){
		for(ll j = 0; j + (1 << i) <= n; j++){
			mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
			mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
		}
	}
	
	for(ll i = 0; i < n; i++){
		v.pb(a[i].F.F);
	}
	
	for(ll i = 0; i < n; i++){
		if(v.back() <= a[i].F.S) r = n;
		else (r = upper_bound(v.begin(), v.end(), a[i].F.S) - v.begin());
		if(r > i + 1 && Mn(i + 1, r) < a[i].S.F){
			cout << "NO";
			return 0;
		}
		if(r > i + 1 && Mx(i + 1, r) > a[i].S.S){
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
	
	return 0;
}