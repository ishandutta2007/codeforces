//In the name of GOD
//Global Round just dont make me blue :)
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

ll r, c;

int main(){
	fast_io;
	
	cin >> r >> c;
	
	if(r * c == 1){
		cout << 0;
		return 0;
	}
	
	if(c == 1){
		for(ll i = 0; i < r; i++){
			cout << i + 2 << '\n';
		}
		return 0;
	}
	
	for(ll j = 0; j < c; j++){
		cout << j + 2 << " ";
	}
	cout << '\n';
	
	for(ll i = 1; i < r; i++){
		for(ll j = 0; j < c; j++){
			cout << (j + 2) * (c + i + 1) << " ";
		}
		cout << '\n';
	}
	
	return 0;
}