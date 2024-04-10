#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

typedef long long ll;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, x, ans;

char c;

string s;

bool val(char d){
	return d == '.';
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	cin >> s;
	
	s = ' ' + s + ' ';
	
	for(ll i = 1; i <= n; i++){
		if(val(s[i]) && val(s[i - 1])){
			ans++;
		}
	}
	
	for(ll i = 0; i < m; i++){
		cin >> x >> c;
		if(val(s[x]) != val(c)){
			if(val(c)){
				ans += val(s[x - 1]) + val(s[x + 1]);
			}
			else{
				ans -= val(s[x - 1]) + val(s[x + 1]);
			}
		}
		s[x] = c;
		cout << ans << endl;
	}
	
	return 0;
}