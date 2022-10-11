//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x, ans;

map<ll, ll> mp;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		mp[x - i] += x;
	}
	
	for(map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++){
		ans = max(ans, it -> S);
	}
	
	cout << ans;
	
	return 0;
}