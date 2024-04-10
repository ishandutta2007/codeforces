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

ll t, n, x;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		if(n < 4){
			cout << "-1\n";
			continue;
		}
		x = n;
		if(n % 2) x--;
		for(ll i = x; i > 0; i -= 2){
			if(i > 4) cout << i << " ";
			if(i == 4) cout << "2 ";
			if(i == 2) cout << "4 ";
		}
		for(ll i = 1; i <= n; i += 2){
			cout << i << " ";
		}
		cout << '\n';
	}
	
	return 0;
}