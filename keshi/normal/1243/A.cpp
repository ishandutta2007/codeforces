//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[maxn], ans, c;

int main(){
	fast_io;
	
	cin >> k;
	
	while(k--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		ans = 0;
		for(ll i = 1; i <= n; i++){
			c = 0;
			for(ll j = 0; j < n; j++){
				if(a[j] >= i){
					c++;
				}
			}
			if(c >= i){
				ans = i;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}