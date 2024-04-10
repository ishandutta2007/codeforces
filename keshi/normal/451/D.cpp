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
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c[2][2], ans[2], t;

string s;

int main(){
	fast_io;
	
	cin >> s;
	
	for(ll i = 0; i < s.size(); i++){
		t = s[i] - 'a';
		c[t][i % 2]++;
		ans[0] += c[t][i % 2];
		ans[1] += c[t][1 - i % 2];
	}
	
	cout << ans[1] << " " << ans[0];
	
	return 0;
}