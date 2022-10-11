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

ll n;

int main(){
	fast_io;
	
	cin >> n;
	
	cout << n * 3 + 4 << '\n';
	cout << "0 0\n0 1\n1 0\n1 1\n1 2\n2 1\n2 2\n";
	for(ll i = 0; i < n - 1; i++){
		cout << i + 2 << " " << i + 3 << '\n';
		cout << i + 3 << " " << i + 2 << '\n';
		cout << i + 3 << " " << i + 3 << '\n';
	}
	
	return 0;
}