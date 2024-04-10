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

ll q, n, a[maxn], b[maxn], x, c;

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			b[a[i]] = i;
		}
		x = 0;
		
		for(ll i = 1; i <= n; i++){
			c = b[i];
			while(b[i] > x){
				ll j = b[i];
				if(a[j] > a[j - 1]) break;
				swap(a[j], a[j - 1]);
				b[a[j]] = j;
				b[a[j - 1]] = j - 1;
			}
			x = max(c, x);
		}
		for(ll i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}