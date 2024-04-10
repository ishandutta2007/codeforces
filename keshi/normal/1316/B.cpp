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

ll t, n, x;

string s, a[maxn], ans;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n >> s;
		for(ll i = 0; i < n; i++){
			a[i].clear();
		}
		ans = s;
		x = 1;
		for(ll i = 0; i < n; i++){
			for(ll j = i; j < n; j++){
				a[i] += s[j];
			}
			if((n - i) % 2 == 0){
				for(ll j = 0; j < i; j++){
					a[i] += s[j];
				}
			}
			else{
				for(ll j = i - 1; j > -1; j--){
					a[i] += s[j];
				}
			}
			if(ans > a[i]){
				ans = a[i];
				x = i + 1;
			}
		}
		cout << ans << '\n' << x << '\n';
	}
	
	return 0;
}