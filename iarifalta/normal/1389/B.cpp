#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()


using namespace std;

const ll N = 2e5;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;



void solve() {
	ll n, k, z;
	cin >> n >> k >> z;
	ll a[n + 1] = {0};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll bal = a[0];
	ll dp[n + 1][z + 3] = {{0}};
	/*
	1
	5 4 0
	1 5 4 3 2
	*/
	ll ans = a[1];
	dp[1][0] = a[1];
	for(int i = 2; i <= n; i++) {
		for(int l = 0; l <= z; l++) {
			for(int j = 0; l + j <= z ; j++) {
				if(j) {
					ll y = k - l * 2 - (i - 1);
					ll s = a[i] + a[i - 1];
					if(y >= (j - 1) * 2 + 1)
						ans = max(ans, dp[i - 1][l] + (j) * (s));
					if(y >= j * 2)
						dp[i][l + j] = max(dp[i][l + j], dp[i - 1][l] + j * s + a[i]),
						ans = max(dp[i][l + j], ans);
				} else {
					ll y = k - l * 2 - (i - 1);
					if(y >= 0)
						dp[i][l] = max(dp[i][l], dp[i - 1][l] + a[i]),
						ans = max(ans, dp[i][l]);
				}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	speed;
	ll t;
	cin >> t;
	while(t--) {
		solve();
	}

}

/*
13 21
*/