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

ll q, n, k, o;

string s;

vector<ll> v;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		v.clear();
		cin >> n >> k >> s;
		for(ll i = 0 ; i < n; i++){
			if(s[i] == '0') v.pb(i);
			s[i] = '1';
		}
		for(ll i = 0; i < v.size(); i++){
			o = min(k, v[i] - i);
			k -= o;
			v[i] -= o;
		}
		for(ll i = 0; i < v.size(); i++){
			s[v[i]] = '0';
		}
		cout << s << endl;
	}
	
	return 0;
}