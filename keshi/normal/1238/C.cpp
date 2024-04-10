#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, h, a[maxn], ans, b, f;

bool t;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> h >> n;
		
		ans = 0;
		
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		a[n + 1] = inf;
		f = 1;
		
		for(ll i = 1; i <= n; i++){
			if(a[i - 1] != a[i] + 1) b = a[i];
			if(a[i + 1] != a[i] - 1 && a[i] > 1){
				if((b - a[i] + 1 - f) % 2){
					ans++;
				}
				f = 0;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}