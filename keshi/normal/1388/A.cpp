//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		if(n <= 30){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if(n == 36) cout << "5 6 10 15\n";
		else if(n == 40) cout << "6 10 9 15\n";
		else if(n == 44) cout << "6 7 10 21\n";
		else cout << "6 10 14 " << n - 30 << '\n';
	}
	
	return 0;
}