#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, a[MAXN], b[MAXN], ans, d;
string s;


int main(){
	fast_io;
	
	cin >> s;
	
	s = '0' + s;
	
	n = s.size();
	
	for(ll i = 0; i < n; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			d++;
		}
		a[i] = d;
	}
	d = 0;
	for(ll i = n; i > -1; i--){
		b[i] = d;
		if(s[i] >= 'A' && s[i] <= 'Z'){
			d++;
		}
	}
	
	ans = INF;
	for(ll i = 0; i < n; i++){
		ans = min(ans, a[i] + b[i]);
	}
	
	cout << ans;
	
	return 0;
}