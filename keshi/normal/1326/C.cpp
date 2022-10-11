//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[maxn], s, ans;

vector<ll> vec;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > n - k) vec.pb(i), s += a[i];
	}
	
	ans = 1;
	
	for(ll i = 1; i < vec.size(); i++){
		ans = (ans * (vec[i] - vec[i - 1])) % mod;
	}
	
	cout << s << " " << ans;
	
	return 0;
}