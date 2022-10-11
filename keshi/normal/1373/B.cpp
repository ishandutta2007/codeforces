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

ll t, n, a, b;
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		a = b = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] == '0') a++;
			else b++;
		}
		cout << (((n - abs(a - b)) / 2) % 2 == 0 ? "NET\n" : "DA\n");
	}
	
	return 0;
}