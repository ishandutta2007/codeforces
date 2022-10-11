//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1010;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, k, lcp[maxn][maxn], dp[maxn][maxn], ps[maxn][maxn];
string s;
vector<pll> vec;

bool cmp(pll a, pll b){
	ll x = lcp[a.F][b.F];
	char c = ' ';
	if(a.F + x <= a.S) c = s[a.F + x];
	char d = ' ';
	if(b.F + x <= b.S) d = s[b.F + x];
	if(c == ' ' && d == ' ') return a.S - a.F < b.S - b.F;
	return c < d;
}

ll cal(ll l, ll r){
	dp[n][0] = 1;
	for(ll i = 0; i <= n; i++){
		ps[i][0] = 1;
	}
	for(ll i = n; i--;){
		ll x = -1;
		if(lcp[l][i] > r - l) x = i + r - l + 2;
		else{
			if(s[l + lcp[l][i]] <= s[i + lcp[l][i]]) x = i + lcp[l][i] + 1;
		}
		for(ll j = 1; j <= m; j++){
			dp[i][j] = 0;
			if(x != -1) dp[i][j] = ps[x][j - 1];
			ps[i][j] = dp[i][j] + ps[i + 1][j];
			if(ps[i][j] >= inf) ps[i][j] = inf;
		}
	}
	return dp[0][m];
}

int main(){
    fast_io;
    
    cin >> n >> m >> k >> s;
    s += ' ';
    lcp[n][n] = 0;
    for(ll i = n; i--;){
    	for(ll j = n; j--;){
    		lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
		}
	}
	vec.reserve(n * n);
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j <= i; j++){
			vec.pb(Mp(j, i));
		}
	}
	sort(all(vec), cmp);
	ll l = -1, r = Sz(vec);
	while(r - l > 1){
		ll mid = (l + r) >> 1;
		if(cal(vec[mid].F, vec[mid].S) < k) r = mid;
		else l = mid;
	}
	for(ll i = vec[r].F; i <= vec[r].S; i++){
		cout << s[i];
	}
	
    return 0;
}