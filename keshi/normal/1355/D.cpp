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

ll t, n, s;

int main(){
	fast_io;
	
	cin >> n >> s;
	if(2 * n <= s){
		cout << "YES\n";
		for(ll i = 1; i < n; i++){
			cout << "2 ";
		}
		cout << s - 2 * n + 2 << "\n1\n";
	}
	else cout << "NO\n";
	
	return 0;
}