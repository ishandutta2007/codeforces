#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, a[maxn], b[maxn], dp[2][3];

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i] >> b[i];
		}
		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = b[0] * 2;
		for(ll i = 1; i < n; i++){
			for(ll j = 0; j < 3; j++){
				dp[i % 2][j] = inf;
				for(ll k = 0; k < 3; k++){
					if(a[i] + j != a[i - 1] + k){
						dp[i % 2][j] = min(dp[i % 2][j], dp[(i - 1) % 2][k] + b[i] * j);
					}
				}
			}
		}
		n--;
		cout << min(dp[n % 2][0], min(dp[n % 2][1], dp[n % 2][2])) << endl;
	}
	
	return 0;
}