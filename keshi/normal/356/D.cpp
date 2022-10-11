//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 7e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, s, b[maxn];

pll a[maxn], g[maxn];

bitset<maxn> dp[2], ch;

int main(){
	fast_io;
	
	cin >> n >> s;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	
	sort(a, a + n);
	
	dp[0][a[n - 1].F] = 1;
	b[a[n - 1].F] = n;
	
	for(ll i = 1; i < n; i++){
		dp[i % 2] = dp[1 - i % 2] | (dp[1 - i % 2] << a[n - i - 1].F);
		ch = dp[i % 2] ^ dp[1 - i % 2];
		for(ll j = ch._Find_first(); j < ch.size(); j = ch._Find_next(j)){
			b[j] = n - i;
		}
	}
	
	g[a[0].S].S = a[0].F;
	
	for(ll i = 0; i < n - 1; i++){
		if(b[s] != i + 1) g[a[i + 1].S].F = a[i].S + 1, g[a[i + 1].S].S = a[i + 1].F - a[i].F;
		else s -= a[i].F, g[a[i + 1].S].S = a[i + 1].F;
	}
	
	if(s != a[n - 1].F){
		cout << -1;
		return 0;
	}
	
	for(ll i = 0; i < n; i++){
		cout << g[i].S << " ";
		if(g[i].F) cout << "1 " << g[i].F << '\n';
		else cout << "0\n";
	}
	
	return 0;
}