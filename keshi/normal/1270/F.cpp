//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll tof = 450;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, b[maxn], a[maxn], c[maxn * tof];
long long ans;
vector<ll> vec;
string s;

ll cal(ll l, ll r, ll x){
	return ((r + (x - r % x) % x) - (l + (x - l % x) % x)) / x;
}

int main(){
	fast_io;
	
	cin >> s;
	n = s.size();
	for(ll i = 1; i <= n; i++){
		a[i] = a[i - 1];
		if(s[i - 1] == '1') a[i]++;
	}
	vec.pb(0);
	for(ll i = 1; i <= n; i++){
		if(s[i - 1] == '1') vec.pb(i);
		for(ll j = 1; j < tof; j++){
			if(j >= vec.size()) break;
			ans += cal(vec[vec.size() - j - 1] - i, vec[vec.size() - j] - i, j);
		}
	}
	for(ll j = 1; j < tof; j++){
		ll ptr = 0;
		for(ll i = 1; i <= n; i++){
			while(a[i] - a[ptr] >= tof) c[b[ptr++] + maxn]++;
			b[i] = a[i] * j - i;
			ans += c[b[i] + maxn];
		}
		for(ll i = 0; i <= n; i++){
			c[b[i] + maxn] = 0;
		}
	}
	cout << ans;
	
	return 0;
}