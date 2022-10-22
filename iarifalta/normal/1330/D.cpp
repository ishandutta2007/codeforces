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
#define ex exit(0)

using namespace std;

const ll N = 2e5 + 10;
const ll big = 1e18;
const ll block = 32;
const ll mod = 1e6;

ll t;

ll a, b;

int main() {
	speed;
	cin >> t;
	while(t--){
		cin >> a >> b;
		ll ans = 0;
		ll per[32];
		ll dp[32][32];
		ll lst = 0;
		ll s = 1;
//		
		for(int i = 0 ; i < 32 ; i++)
			for(int j = 0 ; j < 32 ; j++)
				dp[i][j] = 0;
		for(int i = 0 ; i < 31 ; i++)
			if((1 << i) & a)
				lst = i;
		for(int i = 0 ; i < lst ; i++){
			per[i] = (1 << i);
			dp[0][i] = per[i];
			dp[0][i] %= b;
			ans += per[i];
		}
		dp[0][lst] = a - (1 << lst) + 1;
		per[lst] = a - (1 << lst) + 1;
		dp[0][lst] %= b;
		ans += per[lst];
		ans %= b;
//	
		while(s <= lst){
			for(int i = 0 ; i <= lst ; i++){
				for(int j = 0 ; j < i ; j++)
					dp[s][i] += dp[s - 1][j],
					dp[s][i] %= b;
				dp[s][i] *= per[i];
				dp[s][i] %= b;
				ans += dp[s][i];
				ans %= b;
			}
			s++;
		}
		cout << ans << '\n';
	}
}

/*

*/