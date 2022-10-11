//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, k, ans;

map<ll, ll> m[2];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		if(a % k == 0){
			ans += m[1][a / k];
			m[1][a] += m[0][a / k];
		}
		m[0][a]++;
	}
	
	cout << ans;
	
	return 0;
}