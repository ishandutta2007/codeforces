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

ll q, t, n, k, a[maxn], b[maxn];

bool vis[maxn];

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n >> k;
		fill(vis, vis + n + 1, 0);
		t = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			if(!vis[a[i]]) b[t++] = a[i];
			vis[a[i]] = 1;
		}
		if(t > k){
			cout << -1 << '\n';
			continue;
		}
		fill(b + t, b + k, b[t - 1]);
		cout << n * k << '\n';
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < k; j++){
				cout << b[j] << " ";
			}
		}
		cout << '\n';
	}
	
	return 0;
}