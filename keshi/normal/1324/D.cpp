//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll maxm = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn], ans, fen[maxm];

void upd(ll x){
	for(; x < maxm; x += x & -x){
		fen[x]++;
	}
	return;
}

ll get(ll x){
	ll s = 0;
	for(; x > 0; x -= x & -x){
		s += fen[x];
	}
	return s;
}

vector<ll> vec;

map<ll, ll> mp;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		cin >> b[i];
		vec.pb(b[i] - a[i]);
		vec.pb(a[i] - b[i]);
	}
	
	sort(vec.begin(), vec.end());
	
	for(ll i = 0; i < vec.size(); i++){
		mp[vec[i]] = i + 1;
	}
	
	for(ll i = 0; i < n; i++){
		ans += i - get(mp[b[i] - a[i]]);
		upd(mp[a[i] - b[i]]);
	}
	
	cout << ans;
	
	return 0;
}