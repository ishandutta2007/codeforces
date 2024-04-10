//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 4010;
const ll maxk = 810;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, k, c[maxn][maxn], dp[maxk][maxn];

ll cal(ll l, ll r){
	return c[r][r] - c[l - 1][r] - c[r][l - 1] + c[l - 1][l - 1];
}

void solve(ll s, ll e, ll l, ll r, ll t){
	if(s > e) return;
	if(l > r) return;
	ll mid = (s + e) >> 1;
	dp[t][mid] = inf;
	ll p = -1;
	for(ll i = l; i <= r && i <= mid; i++){
		ll co = dp[t - 1][i - 1] + cal(i, mid);
		if(dp[t][mid] > co){
			dp[t][mid] = co;
			p = i;
		}
	}
	solve(s, mid - 1, l, p, t);
	solve(mid + 1, e, p, r, t);
	return;
}

int main(){
    fast_io;

	//cin >> n >> k;
	scanf("%d %d", &n, &k);
	getchar();
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			c[i][j] = (getchar() - '0');
			getchar();
			c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
		}
	}
	fill(dp[0], dp[0] + n + 1, inf);
	dp[0][0] = 0;
	for(ll i = 1; i <= k; i++){
		solve(1, n, 1, n, i);
	}
	cout << dp[k][n] / 2;

    return 0;
}