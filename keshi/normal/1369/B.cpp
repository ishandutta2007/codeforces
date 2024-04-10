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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, x, y;
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> s;
		x = inf;
		y = -inf;
		for(ll i = 0; i < n; i++){
			if(s[i] == '1') x = min(x, i);
			else y = i;
		}
		if(x > y){
			cout << s << '\n';
			continue;
		}
		for(ll i = 0; i <= x; i++){
			cout << '0';
		}
		for(ll i = 0; i < n - y - 1; i++){
			cout << '1';
		}
		cout << '\n';
	}
	
	return 0;
}