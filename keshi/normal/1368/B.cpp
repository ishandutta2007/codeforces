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

ll n, a[20], x, y;
string s;

int main(){
	fast_io;
	
	s = "codeforces";
	cin >> n;
	for(ll i = 0; i < s.size(); i++){
		a[i] = 1;
	}
	x = 1;
	while(x < n){
		y = 0;
		for(ll i = 0; i < s.size(); i++){
			if(a[y] > a[i]) y = i;
		}
		x /= a[y];
		a[y]++;
		x *= a[y];
	}
	for(ll i = 0; i < s.size(); i++){
		for(ll j = 0; j < a[i]; j++){
			cout << s[i];
		}
	}
	
	return 0;
}