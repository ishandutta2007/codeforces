//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll q, n, vis[maxn], a[maxn];
vector<ll> vec;

ll get(ll i){
	cout << "? " << i << "\n";
	cout.flush();
	ll x;
	cin >> x;
	return x;
}

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n;
		fill(vis, vis + n + 10, 0);
		for(ll i = 1; i <= n; i++){
			if(vis[i]) continue;
			vec.clear();
			while(true){
				ll x = get(i);
				if(vis[x]) break;
				vec.pb(x);
				vis[x] = 1;
			}
			for(ll i = 1; i < Sz(vec); i++){
				a[vec[i - 1]] = vec[i];
			}
			a[vec[Sz(vec) - 1]] = vec[0];
		}
		cout << "! ";
		for(ll i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		cout.flush();
	}
	
	return 0;
}