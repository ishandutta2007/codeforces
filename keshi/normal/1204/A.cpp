// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll ans, f;
string s;

int main(){
	fast_io;
	
	cin >> s;
	
	ans = (s.size() + 1) / 2;
	
	if(s.size() % 2){
		f = 1;
	}
	for(ll i = 1; i < s.size(); i++){
		if(s[i] == '1'){
			f = 0;
		}
	}
	
	cout << ans - f;
	
	
	return 0;
}