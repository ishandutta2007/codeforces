//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k;


int main(){
	fast_io;
	
	cin >> n >> k;
	
	if(k != 2 && k != 3){
		cout << -1;
		return 0;
	}
	
	if(n < 4){
		cout << -1;
		return 0;
	}
	if(n == 4 && k == 2){
		cout << -1;
		return 0;
	}
	
	cout << n - 1 << endl;
	
	if(k == 3){
		for(ll i = 2; i < n; i++){
			cout << 1 << " " << i << endl;
		}
		cout << n - 1 << " " << n << endl;
	}
	else{
		for(ll i = 2; i < n - 1; i++){
			cout << 1 << " " << i << endl;
		}
		cout << n - 2 << " " << n - 1 << endl;
		cout << n - 1 << " " << n << endl;
	}
	
	return 0;
}