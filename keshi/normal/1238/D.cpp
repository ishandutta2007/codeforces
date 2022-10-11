#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ans;

vector<ll> a, b;

string s;

int main(){
	fast_io;
	
	cin >> n >> s;
	
	a.pb(-1);
	b.pb(-1);
	
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A') a.pb(i);
		else b.pb(i);
	}
	
	a.pb(n);
	b.pb(n);
	
	for(ll i = 1; i < a.size() - 1; i++){
		ans += a[i + 1] - a[i];
	}
	for(ll i = 1; i < a.size() - 1; i++){
		ans += a[i] - a[i - 1] - 1;
	}
	
	for(ll i = 1; i < b.size() - 1; i++){
		ans += max(1ll, b[i + 1] - b[i] - 1);
	}
	for(ll i = 1; i < b.size() - 1; i++){
		ans += max(0ll, b[i] - b[i - 1] - 2);
	}
	
	cout << n * (n + 1) / 2 - ans;
	
	return 0;
}