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

ll q, n, m, k, t;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n >> m >> k;
		t = min(m, n / k);
		cout << t - (m - t + k - 2) / (k - 1) << '\n';
	}
	
	return 0;
}