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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, m, x, y;
bool a[maxn], b[maxn], f;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		x = y = 0;
		fill(a, a + n, 0);
		fill(b, b + m, 0);
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				cin >> f;
				if(f) a[i] = 1, b[j] = 1;
			}
		}
		for(ll i = 0; i < n; i++){
			if(!a[i]) x++;
		}
		for(ll i = 0; i < m; i++){
			if(!b[i]) y++;
		}
		cout << (min(x, y) % 2 ? "Ashish\n" : "Vivek\n");
	}
	
	return 0;
}