//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 4e5 + 100;
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

ll t, n, a[maxn], vis[maxn], c[maxn];

int main(){
    fast_io;

	cin >> t;
	while(t--){
		cin >> n;
		fill(vis, vis + 3 * n + 10, 0);
		fill(c, c + 3 * n + 10, 0);
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			c[a[i]]++;
		}
		ll ans = 0;
		for(ll i = 0; i < 3 * n + 10; i++){
			if(vis[i]){
				if(c[i] > 0) vis[i + 1] = 1;
			}
			else{
				if(c[i] > 0) vis[i] = 1;
				if(c[i] > 1) vis[i + 1] = 1;
			}
			if(vis[i]) ans++;
		}
		cout << ans << "\n";
	}

    return 0;
}