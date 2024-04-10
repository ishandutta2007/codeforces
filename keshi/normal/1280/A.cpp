//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, x, ans, c;

string s;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> x >> s;
		ans = s.size();
		for(ll i = 0; i < x; i++){
			c = s[i] - '0';
			if(c >= 2){
				if(s.size() < x){
					for(ll j = i + 1; j < ans; j++){
						if(s.size() >= x) break;
						s += s[j];
					}
				}
			}
			if(c == 3){
				if(s.size() < x){
					for(ll j = i + 1; j < ans; j++){
						if(s.size() >= x) break;
						s += s[j];
					}
				}
			}
			ans = ((ans - i - 1) * c + i + 1 + mod * 2) % mod;
		}
		cout << ans << '\n';
	}
	
	return 0;
}