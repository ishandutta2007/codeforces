//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans, a[maxn], b[maxn], ps[maxn], sp[maxn];

map<ll, bool> vis;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
		vis[ps[i]] = 1;
	}
	
	cin >> m;
	
	for(ll i = 1; i <= m; i++){
		cin >> b[i];
		sp[i] = sp[i - 1] + b[i];
		if(vis[sp[i]]){
			ans++;
		}
	}
	
	if(ps[n] != sp[m]){
		ans = -1;
	}
	
	
	cout << ans;
	
	return 0;
}