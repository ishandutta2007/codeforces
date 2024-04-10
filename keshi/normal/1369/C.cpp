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

ll t, n, k, a[maxn], b[maxn], l, s, x;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		l = s = 0;
		x = n - 1;
		for(ll i = 0; i < k; i++){
			cin >> b[i];
			s += a[n - i - 1];
			if(b[i] == 1) s += a[x--];
		}
		sort(b, b + k, greater<ll>());
		for(ll i = 0; i < k; i++){
			if(b[i] == 1) continue;
			s += a[l];
			l += b[i] - 1;
		}
		cout << s << '\n';
	}
	
	return 0;
}