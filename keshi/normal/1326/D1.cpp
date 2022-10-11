//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, m, x;

bool f;

string s, t;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> s;
		n = s.size();
		m = 0;
		t = "";
		for(ll i = 0; i < n / 2; i++){
			x = i;
			for(ll j = 0; j <= i; j++){
				if(s[i + j] != s[i - j]) break;
				x = i - j;
			}
			f = 1;
			for(ll j = 0; j < x; j++){
				if(s[j] != s[n - j - 1]) f = 0;
			}
			if(f && 2 * i + 1 > m){
				m = 2 * i + 1;
				t = "";
				for(ll j = 0; j < i; j++){
					t += s[j];
				}
				for(ll j = i; j > -1; j--){
					t += s[j];
				}
			}
		}
		for(ll i = 1; i <= n / 2; i++){
			x = i;
			for(ll j = 0; j < i; j++){
				if(s[i + j] != s[i - j - 1]) break;
				x = i - j - 1;
			}
			f = 1;
			for(ll j = 0; j < x; j++){
				if(s[j] != s[n - j - 1]) f = 0;
			}
			if(f && 2 * i > m){
				m = 2 * i;
				t = "";
				for(ll j = 0; j < i; j++){
					t += s[j];
				}
				for(ll j = i - 1; j > -1; j--){
					t += s[j];
				}
			}
		}
		for(ll i = n / 2; i < n; i++){
			x = 0;
			for(ll j = 0; i + j < n; j++){
				if(s[i + j] != s[i - j]) break;
				x = i + j;
			}
			f = 1;
			for(ll j = x + 1; j < n; j++){
				if(s[j] != s[n - j - 1]) f = 0;
			}
			if(f && 2 * (n - i) - 1 > m){
				m = 2 * (n - i) - 1;
				t = "";
				for(ll j = n - 1; j > i; j--){
					t += s[j];
				}
				for(ll j = i; j < n; j++){
					t += s[j];
				}
			}
		}
		for(ll i = n / 2 + 1; i < n; i++){
			x = i - 1;
			for(ll j = 0; i + j < n; j++){
				if(s[i + j] != s[i - j - 1]) break;
				x = i + j;
			}
			f = 1;
			for(ll j = x + 1; j < n; j++){
				if(s[j] != s[n - j - 1]) f = 0;
			}
			if(f && 2 * (n - i) > m){
				m = 2 * (n - i);
				t = "";
				for(ll j = n - 1; j >= i; j--){
					t += s[j];
				}
				for(ll j = i; j < n; j++){
					t += s[j];
				}
			}
		}
		cout << t << '\n';
	}
	
	return 0;
}