//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

bool f[maxn];

bool val(ll s, ll x){
	ll i = s;
	do{
		if(!f[i]) return 0;
		i = (i + x) % n;
	}while(i != s);
	
	return 1;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> f[i];
	}
	
	for(ll i = 3; i <= n; i++){
		if(n % i == 0){
			for(ll j = 0; j < n / i; j++){
				if(val(j, n / i)){
					cout << "YES";
					return 0;
				}
			}
		}
	}
	
	cout << "NO";
	
	return 0;
}