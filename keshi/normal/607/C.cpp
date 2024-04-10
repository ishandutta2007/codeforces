//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll cmod = 2;
const ll mod[cmod] = {1000000007, 1000000009};
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[2][maxn], b[2][maxn], p;

char c;

int main(){
	fast_io;
	
	cin >> n;
	n--;
	
	for(ll i = n; i--;){
		cin >> c;
		if(c == 'N') a[0][i] = 0;
		if(c == 'E') a[0][i] = 1;
		if(c == 'W') a[0][i] = 2;
		if(c == 'S') a[0][i] = 3;
		a[1][i] = a[0][i];
	}
	
	for(ll i = n; i--;){
		cin >> c;
		if(c == 'N') b[0][i] = 3;
		if(c == 'E') b[0][i] = 2;
		if(c == 'W') b[0][i] = 1;
		if(c == 'S') b[0][i] = 0;
		b[1][i] = b[0][i];
	}
	
	for(ll j = 0; j < cmod; j++){
		p = 1;
		for(ll i = 1; i < n; i++){
			p = (p * 4) % mod[j];
			a[j][i] = (a[j][i] * p + a[j][i - 1]) % mod[j];
			b[j][i] = (b[j][i] + b[j][i - 1] * 4) % mod[j];
		}
	}
	
	for(ll i = 0; i < n; i++){
		bool f = 1;
		for(ll j = 0; j < cmod; j++){
			if(a[j][i] != b[j][i]) f = 0;
		}
		if(f){
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
	
	return 0;
}