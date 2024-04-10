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

ll n, u, d, l, r;

string s;

int main(){
	fast_io;
	
	cin >> n;
	
	while(n--){
		u = d = l = r = 0;
		cin >> s;
		for(ll i = 0; i < s.size(); i++){
			if(s[i] == 'R') r++;
			if(s[i] == 'L') l++;
			if(s[i] == 'U') u++;
			if(s[i] == 'D') d++;
		}
		r = min(r, l);
		d = min(u, d);
		if(r == 0){
			d = min(1ll, d);
		}
		if(d == 0){
			r = min(1ll, r);
		}
		cout << 2 * (r + d) << '\n';
		for(ll i = 0; i < r; i++){
			cout << 'R';
		}
		for(ll i = 0; i < d; i++){
			cout << 'D';
		}
		for(ll i = 0; i < r; i++){
			cout << 'L';
		}
		for(ll i = 0; i < d; i++){
			cout << 'U';
		}
		cout << '\n';
	}
	
	return 0;
}