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

ll t, n, k;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n >> k;
		if(k % 2 == 0 && n % 2){
			cout << "NO\n";
			continue;
		}
		if(n % 2 == k % 2){
			if(n < k){
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			cout << n - k + 1 << " ";
			for(ll i = 1; i < k; i++){
				cout << 1 << " ";
			}
			cout << '\n';
			continue;
		}
		if(n < 2 * k){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << n - 2 * k + 2 << " ";
		for(ll i = 1; i < k; i++){
			cout << "2 ";
		}
		cout << '\n';
	}
	
	return 0;
}