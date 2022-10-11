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
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, x, a[maxn], ans;

string s;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n >> x >> s;
		for(ll i = 1; i <= n; i++){
			if(s[i - 1] == '0') a[i] = a[i - 1] + 1;
			else a[i] = a[i - 1] - 1;
		}
		ans = 0;
		if(a[n] == 0){
			for(ll i = 0; i <= n; i++){
				if(a[i] == x) ans = -1;
			}
		}
		else{
			if(x == 0) ans++;
			for(ll i = 1; i <= n; i++){
				if((x - a[i]) % a[n] == 0 && (x - a[i]) / a[n] >= 0){
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}