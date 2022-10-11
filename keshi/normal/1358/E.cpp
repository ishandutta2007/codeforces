//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b, s, mn;

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n - n / 2; i++){
		cin >> a[i];
		s += a[i];
	}
	cin >> b;
	if(s + b * (n / 2) > 0){
		cout << n;
		return 0;
	}
	if(b >= 0){
		cout << -1;
		return 0;
	}
	b = -b;
	mn = inf;
	for(ll i = 0; i < n - n / 2; i++){
		mn = min(mn, n - n / 2 - i + (s + b - 1) / b);
		if(mn > n - i){
			cout << n - i;
			return 0;
		}
		s -= a[i];
	}
	cout << -1;
	
	return 0;
}