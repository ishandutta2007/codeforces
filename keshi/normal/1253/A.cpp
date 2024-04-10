//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], b[maxn], c[maxn], l, r;

bool f;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		for(ll i = 0; i < n; i++){
			cin >> b[i];
			c[i] = b[i] - a[i];
		}
		l = 0;
		for(ll i = 0; i < n; i++){
			if(c[i] != 0){
				l = i;
				break;
			}
		}
		r = n - 1;
		for(ll i = 0; i < n; i++){
			if(c[i] != 0){
				r = i;
			}
		}
		f = (c[l] >= 0);
		for(ll i = l; i <= r; i++){
			if(c[l] != c[i]){
				f = 0;
				break;
			}
		}
		if(f){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
		cout << '\n';
	}
	
	return 0;
}