//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1520;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, a[maxn][maxn], b[maxn][maxn], c[maxn], d[maxn];
bool ok[maxn];
vector<ll> vec;

int main(){
    fast_io;
    
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
    	for(ll j = 0; j < m; j++){
    		cin >> a[i][j];
		}
	}
    for(ll i = 0; i < n; i++){
    	for(ll j = 0; j < m; j++){
    		cin >> b[i][j];
		}
	}
	for(ll i = 1; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(b[i][j] < b[i - 1][j]){
				c[j]++;
			}
		}
	}
	for(ll j = 0; j < m; j++){
		if(c[j] == 0) vec.pb(j);
	}
	ll ptr = 0;
	while(ptr < Sz(vec)){
		ll x = vec[ptr++];
		for(ll i = 1; i < n; i++){
			if(b[i][x] != b[i - 1][x] && !ok[i]){
				ok[i] = 1;
				for(ll j = 0; j < m; j++){
					if(b[i][j] < b[i - 1][j]){
						c[j]--;
						if(c[j] == 0) vec.pb(j);
					}
				}
			}
		}
	}
	reverse(all(vec));
	for(ll i = 0; i < n; i++){
		d[i] = i;
	}
	for (ll t : vec) {
    	stable_sort(d, d + n, [&](ll i, ll j) {
     	 	return a[i][t] < a[j][t];
    	});
  }
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(a[d[i]][j] != b[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	cout << Sz(vec) << "\n";
	for(ll i : vec){
		cout << i + 1 << " ";
	}
 
    return 0;
}