//In the name of GOD
//Out of competition B-)
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

ll q, n, p, s, k, ans, a[maxn];

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		ans = 0;
		cin >> n >> p >> k;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		for(ll i = 0; i < k; i++){
			s = p;
			if(s >= 0) ans = max(ans, i);
			for(ll j = k - 1 + i; j < n; j += k){
				s -= a[j];
				if(s >= 0) ans = max(ans, j + 1);
			}
			p -= a[i];
		}
		cout << ans << '\n';
	}
	
	return 0;
}