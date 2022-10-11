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

ll t, a, b;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b;
		if(a > 3){
			cout << "YES\n";
		}
		else if(a == 1){
			if(b == 1){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		else{
			if(b < 4){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	
	return 0;
}