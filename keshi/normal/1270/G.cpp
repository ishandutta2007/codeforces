//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, a[maxn], v;
vector<ll> vec;
bool vis[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			a[i] = i - a[i];
		}
		fill(vis, vis + n + 1, 0);
		vec.clear();
		v = 1;
		while(!vis[v]){
			vis[v] = 1;
			v = a[v];
		}
		while(vis[v]){
			vec.pb(v);
			vis[v] = 0;
			v = a[v];
		}
		cout << vec.size() << '\n';
		for(ll i = 0; i < vec.size(); i++){
			cout << vec[i] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}