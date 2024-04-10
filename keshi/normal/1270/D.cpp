//In the name of GOD
//Good Bye 2019
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

ll n, k, b, x;

map<ll, ll> c;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	if(k == 1){
		cout << "! 1";
		return 0;
	}
	
	b = -1;
	
	for(ll i = 1; i <= k + 1; i++){
		cout << "? ";
		for(ll j = 1; j <= k + 1; j++){
			if(i != j) cout << j << " ";
		}
		cout << '\n';
		cout.flush();
		cin >> x >> x;
		c[x]++;
		b = max(b, x);
	}
	
	cout << "! " << c[b];
	
	return 0;
}