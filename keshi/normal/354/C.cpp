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
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, ans, a[maxn], ps[maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		ps[a[i]]++;
	}
	
	for(ll i = 1; i < maxn; i++){
		ps[i] += ps[i - 1];
	}
	
	for(ll i = 1; i < maxn; i++){
		bool f = 1;
		if(ps[i - 1] > 0) f = 0;
		for(ll j = 0; i * (j + 1) - 1 < maxn; j++){
			if(i - 1 > k && ps[i * (j + 1) - 1] - ps[i * j + k] > 0) f = 0;
		}
		if(f) ans = i;
	}
	
	cout << ans;
	
	return 0;
}