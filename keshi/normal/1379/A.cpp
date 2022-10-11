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

ll q, n;
string s, t, p;

bool check(ll i){
	for(ll j = 0; j < 7; j++){
		if(s[i + j] != t[j]) return 0;
	}
	return 1;
}

bool solve(ll i){
	for(ll j = 0; j < 7; j++){
		if(s[i + j] == '?') s[i + j] = t[j];
	}
	for(ll j = 0; j < n; j++){
		if(s[j] == '?') s[j] = 'z';
	}
	ll x = 0;
	for(ll j = 0; j + 6 < n; j++){
		if(check(j)) x++;
	}
	return (x == 1);
}

int main(){
	fast_io;
	
	t = "abacaba";
	cin >> q;
	while(q--){
		cin >> n >> p;
		bool f = 0;
		for(ll i = 0; i + 6 < n; i++){
			s = p;
			if(solve(i)){
				cout << "Yes\n" << s << '\n';
				f = 1;
				break;
			}
		}
		if(!f) cout << "No\n";
	}
	
	return 0;
}