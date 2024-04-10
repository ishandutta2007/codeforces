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

ll n, k, a[maxn], ps[maxn], l, ans = inf;

int main(){
	fast_io;
	
	cin >> n >> k;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(ll i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + a[i];
	}
	for(ll i = 1; i <= n; i++){
		if(a[i] != a[i + 1]){
			if(i - l >= k){
				cout << 0;
				return 0;
			}
			if(i >= k) ans = min(ans, i * (a[i] - 1) - ps[i] + k);
			if(n - l >= k) ans = min(ans, ps[n] - ps[l] - (n - l) * (a[i] + 1) + k);
			ans = min(ans, l * (a[i] - 1) - ps[l] + ps[n] - ps[i] - (n - i) * (a[i] + 1) + k - i + l);
			l = i;
		}
	}
	cout << ans;
	
	return 0;
}