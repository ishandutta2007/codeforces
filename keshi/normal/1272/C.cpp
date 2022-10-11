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

ll n, k, l, ans;

char c;

string s;

map<char, bool> vis;

int main(){
	fast_io;
	
	cin >> n >> k >> s;
	
	for(ll i = 0; i < k; i++){
		cin >> c;
		vis[c] = 1;
	}
	
	l = -1;
	
	for(ll i = 0; i < n; i++){
		if(!vis[s[i]]){
			ans += (i - l) * (i - l - 1) / 2;
			l = i;
		}
	}
	
	ans += (n - l) * (n - l - 1) / 2;
	
	cout << ans;
	
	return 0;
}