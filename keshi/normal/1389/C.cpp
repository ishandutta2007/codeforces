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

ll t, n, c[maxn], a[maxn], ans;
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		if(n == 1){
			cout << "0\n";
			continue;
		}
		for(ll i = 0; i < n; i++){
			a[i] = s[i] - '0';
		}
		ans = 0;
		for(ll i = 0; i < 10; i++){
			for(ll j = 0; j < 10; j++){
				ll p = 0;
				for(ll k = 0; k < n; k++){
					if(p & 1){
						if(a[k] == j) p++;
					}
					else{
						if(a[k] == i) p++;
					}
				}
				ans = max(ans, (p / 2) * 2);
				if(i == j) ans = max(ans, p);
			}
		}
		cout << n - ans << '\n';
	}
	
	return 0;
}