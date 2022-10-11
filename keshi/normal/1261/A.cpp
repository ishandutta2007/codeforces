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

ll t, n, k;

string s, d;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n >> k >> s;
		d = "(";
		for(ll i = 0; i < n / 2 - k; i++){
			d += "()";
		}
		d += ")";
		for(ll i = 0; i < k - 1; i++){
			d += "()";
		}
		cout << n << '\n';
		for(ll i = 0; i < n; i++){
			ll j = i;
			while(s[j] != d[i]) j++;
			cout << i + 1 << " " << j + 1 << '\n';
			reverse(s.begin() + i, s.begin() + j + 1);
		}
	}
	
	return 0;
}