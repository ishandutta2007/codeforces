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

ll t, a, b, c, k;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b >> c;
		if(b % 2){
			k = b / 2 + 1;
			for(ll i = 0; i < a + 1; i++){
				cout << 0;
			}
			for(ll i = 0; i < c + 1; i++){
				cout << 1;
			}
			for(ll i = 0; i < k - 1; i++){
				cout << "01";
			}
		}
		else{
			k = b / 2;
			if(a < c){
				for(ll i = 0; i < a + 1; i++){
					if(a > 0 || b) cout << 0;
				}
				for(ll i = 0; i < c + 1; i++){
					if(c > 0 || b) cout << 1;
				}
				for(ll i = 0; i < k - 1; i++){
					cout << "01";
				}
				if(b) cout << "0";
			}
			else{
				for(ll i = 0; i < c + 1; i++){
					if(c > 0 || b) cout << 1;
				}
				for(ll i = 0; i < a + 1; i++){
					if(a > 0 || b) cout << 0;
				}
				for(ll i = 0; i < k - 1; i++){
					cout << "10";
				}
				if(b) cout << "1";
			}
		}
		cout << '\n';
	}
	
	return 0;
}