//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll maxk = 22;
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

ll n, k, a[maxn], dp[maxk][maxn], cnt[maxn], dl, dr, ans;


void solve(ll s, ll e, ll l, ll r, ll x){
	if(s > e) return;
	ll mid = (s + e) >> 1;
	while(dr < mid) ans += cnt[a[++dr]]++;
	while(dr > mid) ans -= --cnt[a[dr--]];
	while(dl < min(mid, r)) ans -= --cnt[a[dl++]];
	while(dl > min(mid, r)) ans += cnt[a[--dl]]++;
	pll p = Mp(inf, -1);
	for(ll i = min(mid, r); i >= l; i--){
		p = min(p, Mp(ans + dp[x - 1][i - 1], i));
		ans += cnt[a[--dl]]++;
	}
	dp[x][mid] = p.F;
	solve(s, mid - 1, l, p.S, x);
	solve(mid + 1, e, p.S, r, x);
	return;
}

int main(){
    fast_io;

	cin >> n >> k;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	fill(dp[0] + 1, dp[0] + n + 1, inf);
	dl = 1;
	dr = 1;
	cnt[a[1]] = 1;
	for(ll i = 1; i <= k; i++){
		solve(1, n, 1, n, i);
	}
	cout << dp[k][n];

    return 0;
}