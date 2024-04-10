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
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], b[maxn];

bool f, q, r;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		f = q = r = 1;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		for(ll i = 0; i < n; i++){
			cin >> b[i];
		}
		for(ll i = 0; i < n; i++){
			if(a[i] < b[i] && f) r = 0;
			else if(a[i] > b[i] && q) r = 0;
			if(a[i] == 1) f = 0;
			else if(a[i] == -1) q = 0;
		}
		if(r) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
	
	return 0;
}