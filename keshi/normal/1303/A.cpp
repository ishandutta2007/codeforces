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

ll t, n, a, b;

string s;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> s;
		n = s.size();
		a = 0;
		b = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] == '0') a++;
		}
		if(a == n){
			cout << "0\n";
			continue;
		}
		for(ll i = 0; i < n; i++){
			if(s[i] == '1') break;
			b++;
		}
		for(ll i = n - 1; i > -1; i--){
			if(s[i] == '1') break;
			b++;
		}
		cout << a - b << '\n';
	}
	
	return 0;
}