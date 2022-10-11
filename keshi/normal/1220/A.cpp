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

ll n, a, b;

string s;

int main(){
	fast_io;
	
	cin >> n >> s;
	
	for(ll i = 0; i < n; i++){
		if(s[i] == 'n') a++;
		if(s[i] == 'z') b++;
	}
	
	for(ll i = 0; i < a; i++){
		cout << "1 ";
	}
	
	for(ll i = 0; i < b; i++){
		cout << "0 ";
	}
	
	return 0;
}