#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

typedef long long ll;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	n = min(n, m);
	
	cout << n + 1 << endl;
	
	for(ll i = 0; i <= n; i++){
		cout << i << " " << n - i << endl;
	}
	
	return 0;
}