//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, a;
bool vis[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		fill(vis, vis + maxn, 0);
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a;
			vis[a] = 1;
		}
		ll c = 0;
		for(ll i = 1; i + 1 < maxn; i++){
			if(vis[i] && (!vis[i + 1])) c++;
		}
		cout << (c > 1 ? "NO\n" : "YES\n");
	}
	
	return 0;
}