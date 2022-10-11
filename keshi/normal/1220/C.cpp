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

ll n;

string s;

char c;

int main(){
	fast_io;
	
	cin >> s;
	
	n = s.size();
	
	c = s[0];
	
	for(ll i = 0; i < n; i++){
		c = min(c, s[i]);
		if(c == s[i]) cout << "Mike\n";
		else cout << "Ann\n";
	}
	
	return 0;
}