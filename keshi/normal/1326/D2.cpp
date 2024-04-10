//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, m, x, ans;

bool val[maxn];

string s;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> s;
		m = 0;
		ans = 0;
		n = s.size();
		val[0] = 1;
		for(ll i = 1; i <= n; i++){
			val[i] = 0;
			if(val[i - 1] && s[i - 1] == s[n - i]) val[i] = 1;
		}
		vector<ll> d1(n);
		for(ll i = 0, l = 0, r = -1; i < n; i++) {
		    ll k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
		        k++;
		    }
		    d1[i] = k--;
		    if (i + k > r) {
		        l = i - k;
		        r = i + k;
		    }
		}
		vector<ll> d2(n);
		for(ll i = 0, l = 0, r = -1; i < n; i++) {
		    ll k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
		        k++;
		    }
		    d2[i] = k--;
		    if (i + k > r) {
		        l = i - k - 1;
		        r = i + k ;
		    }
		}
		for(ll i = 0; i < n; i++){
			x = min(i - d1[i] + 1, n - i - d1[i]);
			if(val[x]){
				if(2 * (x + d1[i]) - 1 > m){
					m = 2 * (x + d1[i]) - 1;
					ans = i;
				}
			}
			x = min(i - d2[i], n - i - d2[i]);
			if(val[x]){
				if(2 * (x + d2[i]) > m){
					m = 2 * (x + d2[i]);
					ans = i;
				}
			}
		}
		if(m % 2){
			if(2 * (n - ans) - 1 == m){
				for(ll i = n - 1; i > ans; i--){
					cout << s[i];
				}
				for(ll i = ans; i < n; i++){
					cout << s[i];
				}
			}
			else{
				for(ll i = 0; i < ans; i++){
					cout << s[i];
				}
				for(ll i = ans; i > -1; i--){
					cout << s[i];
				}
			}
		}
		else{
			if(2 * (n - ans) == m){
				for(ll i = n - 1; i >= ans; i--){
					cout << s[i];
				}
				for(ll i = ans; i < n; i++){
					cout << s[i];
				}
			}
			else{
				for(ll i = 0; i < ans; i++){
					cout << s[i];
				}
				for(ll i = ans - 1; i > -1; i--){
					cout << s[i];
				}
			}
		}
		cout << '\n';
	}
	
	return 0;
}