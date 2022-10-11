//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, a[maxn], b[maxn], d;

bool vis[maxn];

void dfs(ll v){
	vis[v] = 1;
	d++;
	if(!vis[a[v]]){
		dfs(a[v]);
	}
	b[v] = d;
	return;
}

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			vis[i] = 0;
		}
		for(ll i = 1; i <= n; i++){
			if(!vis[i]){
				d = 0;
				dfs(i);
			}
			cout << b[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}