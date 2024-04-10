//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, d, x, a[maxn], b[maxn], c[maxn], s[maxn];

int main(){
	fast_io;
	
	cin >> n >> m >> d;
	
	for(ll i = 0; i < m; i++){
		cin >> a[i];
	}
	b[m] = n + 1;
	for(ll i = m - 1; i > -1; i--){
		b[i] = b[i + 1] - a[i];
	}
	
	for(ll i = 0; i < m; i++){
		c[i] = min(x + d, b[i]);
		x = c[i] + a[i] - 1;
	}
	if(x + d < n + 1){
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < a[i]; j++){
			s[c[i] + j] = i + 1;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		cout << s[i] << " ";
	}
	
	return 0;
}