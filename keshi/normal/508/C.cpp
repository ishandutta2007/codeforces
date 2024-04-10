//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, t, r, ans, a[maxn], b[maxn];

int main(){
	fast_io;
	
	cin >> n >> t >> r;
	
	if(r > t){
		cout << -1;
		return 0;
	}
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 1; j <= r - b[i]; j++){
			for(ll k = i + 1; k < n; k++){
				if(a[k] - (a[i] - j) <= t){
					b[k]++;
				}
			}
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}