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

ll t, n, x, v, c[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> x;
		fill(c, c + n + 1, 0);
		for(ll i = 1; i < n; i++){
			cin >> v;
			c[v]++;
			cin >> v;
			c[v]++;
		}
		if(c[x] <= 1){
			cout << "Ayush";
		}
		else{
			if(n % 2) cout << "Ashish";
			else cout << "Ayush";
		}
		cout << '\n';
	}
	
	return 0;
}