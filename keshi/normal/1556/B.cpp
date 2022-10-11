//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll t, n, a[maxn], c[2];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		c[0] = c[1] = 1;
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			a[i] &= 1;
			c[a[i]]++;
		}
		if(c[0] > c[1] + 1 || c[1] > c[0] + 1){
			cout << "-1\n";
			continue;
		}
		if(c[0] != c[1]){
			ll x = 0, ans = 0;
			if(c[0] < c[1]){
				for(ll i = 0; i < n; i++){
					if(a[i]){
						ans += max(0ll, -x);
						x++;
					}
					else{
						ans += max(0ll, x - 1);
						x--;
					}
				}
				cout << ans << "\n";
			}
			else{
				for(ll i = 0; i < n; i++){
					if(a[i] == 0){
						ans += max(0ll, -x);
						x++;
					}
					else{
						ans += max(0ll, x - 1);
						x--;
					}
				}
				cout << ans << "\n";
			}
			continue;
		}
		ll x = 0, ans1 = 0;
		for(ll i = 0; i < n; i++){
			if(a[i]){
				ans1 += max(0ll, -x);
				x++;
			}
			else{
				ans1 += max(0ll, x - 1);
				x--;
			}
		}
		x = 0;
		ll ans2 = 0;
		for(ll i = 0; i < n; i++){
			if(a[i] == 0){
				ans2 += max(0ll, -x);
				x++;
			}
			else{
				ans2 += max(0ll, x - 1);
				x--;
			}
		}
		cout << min(ans1, ans2) << "\n";
	}
	
	return 0;
}