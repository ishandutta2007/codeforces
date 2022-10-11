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

ll n, a[maxn], b[maxn], t[maxn], m, ans;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		t[a[i]] = n - i;
	}
	
	for(ll i = 0; i < n; i++){
		cin >> b[i];
		b[i] = t[b[i]];
	}
	
	for(ll i = n - 1; i > -1; i--){
		if(b[i] < m){
			ans++;
		}
		m = max(m, b[i]);
	}
	
	cout << ans;
	
	return 0;
}