//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e7 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll a, n, ans[maxn], x;

int main(){
	fast_io;
	
	for(ll i = 1; i * i < maxn; i++){
		for(ll j = 1; j * i * i < maxn; j++){
			ans[j * i * i] = i * i;
		}
	}
	
	cin >> a >> n;
	
	for(ll i = 0; i < n; i++){
		x += (a + i) / ans[a + i];
	}
	
	cout << x;
	
	return 0;
}