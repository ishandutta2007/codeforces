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



int main(){
	fast_io;
	
	ll l, r;
	
	cin >> l >> r;
	
	if(l == r){
		cout << 0;
		return 0;
	}
	
	cout << (1ll << (64 - __builtin_clzll(l ^ r))) - 1;
	
	return 0;
}