#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m[MAXN], r;

map<string, ll> c, d;

string s[MAXN];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i] >> m[i];
		c[s[i]] += m[i];
	}
	r = 0;
	
	for(map<string, ll>::iterator i = c.begin(); i != c.end(); i++){
		r = max(r, i -> S);
	}
	
	for(ll i = 0; i < n; i++){
		d[s[i]] += m[i];
		if(d[s[i]] >= r && c[s[i]] == r){
			cout << s[i];
			return 0;
		}
	}
	
	return 0;
}