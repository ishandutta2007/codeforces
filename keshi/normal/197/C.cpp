//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 998244353;
const ll inf = 8e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, l, k;

string s;

vector <ll> a[26];

int main(){
	fast_io;
	
	cin >> s;
	
	n = s.size();
	
	for(ll i = 0; i < n; i++){
		a[s[i] - 'a'].pb(i);
	}
	
	l = -1;
	
	for(ll i = 25; i > -1; i--){
		k = upper_bound(a[i].begin(), a[i].end(), l) - a[i].begin();
		for(ll j = k; j < a[i].size(); j++){
			cout << s[a[i][j]];
			l = a[i][j];
		}
	}
	
	return 0;
}