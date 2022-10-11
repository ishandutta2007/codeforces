//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F second.first
#define S second.second
#define val first.first
#define id first.second

ll n, p, s, ans, dp[maxn][maxn], pd[maxn][maxn], par;

bool pr[maxn][maxn], rp[maxn][maxn];

pair<pll, pll> a[maxn];

int main(){
	fast_io;
	
	cin >> n >> p >> s;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F;
		a[i].id = i;
	}
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].S;
	}
	
	for(ll i = 1; i <= n; i++){
		a[i].val = a[i].S - a[i].F;
	}
	
	sort(a + 1, a + n + 1);
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= p; j++){
			if(j > i) continue;
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i].F);
			if(dp[i][j] == dp[i - 1][j - 1] + a[i].F) pr[i][j] = 1;
		}
	}
	
	for(ll i = n; i > 0; i--){
		for(ll j = 1; j <= s; j++){
			if(n - i + 1 < j) continue;
			pd[i][j] = max(pd[i + 1][j], pd[i + 1][j - 1] + a[i].S);
			if(pd[i][j] == pd[i + 1][j - 1] + a[i].S) rp[i][j] = 1;
		}
	}
	
	for(ll i = p; n - i >= s; i++){
		ans = max(ans, dp[i][p] + pd[i + 1][s]);
		if(ans == dp[i][p] + pd[i + 1][s]) par = i;
	}
	
	ll i = par, j = p;
	
	cout << ans << '\n';
	
	while(i){
		if(pr[i][j]){
			cout << a[i].id << " ";
			j--;
		}
		i--;
	}
	
	cout << '\n';
	i = par + 1, j = s;
	
	while(i <= n){
		if(rp[i][j]){
			cout << a[i].id << " ";
			j--;
		}
		i++;
	}
	
	return 0;
}