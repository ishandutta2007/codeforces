// In The Name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll c[3], n[3], p[3], r;
string s;

ll cal(ll x){
	ll ans = 0;
	for(ll i = 0; i < 3; i++){
		ans += max(0ll, x * c[i] - n[i]) * p[i];
	}
	return ans;
}

ll isval(ll x){
	//cout << x << " => " << cal(x) << endl;
	return cal(x) > r;
}

ll binary_search(){
	ll l = 0, r = 1e15, mi;
	while(r - l > 1){
		//cout << l << " " << r << endl;
		mi = (l + r) / 2;
		if(isval(mi)){
			r = mi;
		}
		else{
			l = mi;
		}
	}
	return l;
}

int main(){
	fast_io;
	
	cin >> s;
	
	for(ll i = 0; i < s.size(); i++){
		if(s[i] == 'B'){
			c[0]++;
		}
		if(s[i] == 'S'){
			c[1]++;
		}
		if(s[i] == 'C'){
			c[2]++;
		}
	}
	
	for(ll i = 0; i < 3; i++){
		cin >> n[i];
	}
	
	for(ll i = 0; i < 3; i++){
		cin >> p[i];
	}
	
	cin >> r;
	
	cout << binary_search();
	
	
	return 0;
}