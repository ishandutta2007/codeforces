//In the name of GOD
//Hello Yellow
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

string s;

deque<char> d;

void solve(ll l, ll r){
	if(r < l) return;
	if(r - l <= 1){
		d.pb(s[l]);
		if(r != l && s[r] == s[l]) d.pb(s[r]);
		return;
	}
	if(s[l] == s[r]){
		solve(l + 1, r - 1);
		d.pb(s[r]);
		d.push_front(s[l]);
		return;
	}
	if(s[l] == s[r - 1]){
		solve(l + 1, r - 2);
		d.pb(s[r - 1]);
		d.push_front(s[l]);
		return;
	}
	if(s[l + 1] == s[r]){
		solve(l + 2, r - 1);
		d.pb(s[r]);
		d.push_front(s[l + 1]);
		return;
	}
	if(s[l + 1] == s[r - 1]){
		solve(l + 2, r - 2);
		d.pb(s[r - 1]);
		if(l + 1 != r - 1) d.push_front(s[l + 1]);
		return;
	}
	return;
}

int main(){
	fast_io;
	
	cin >> s;
	
	solve(0, s.size() - 1);
	
	for(ll i = 0; i < d.size(); i++){
		cout << d[i];
	}
	
	return 0;
}