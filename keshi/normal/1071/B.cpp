//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2100;
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

ll n, k, dp[maxn][maxn];
string s[maxn];
bool vis[maxn][maxn];
vector<pll> vec, v2;

int main(){
    fast_io;

	cin >> n >> k;
	for(ll i = 0; i < n; i++){
		cin >> s[i];
	}
	dp[0][0] = ll(s[0][0] != 'a');
	if(dp[0][0] <= k) s[0][0] = 'a';
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(i + j == 0) continue;
			dp[i][j] = inf;
			if(i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			dp[i][j] += ll(s[i][j] != 'a');
			if(dp[i][j] <= k) s[i][j] = 'a';
		}
	}
	vec.pb(Mp(0ll, 0ll));
	vis[0][0] = 1;
	cout << s[0][0];
	for(ll o = 2; o < n + n; o++){
		char c = 'z';
		v2.clear();
		for(pll i : vec){
			if(i.F + 1 < n && !vis[i.F + 1][i.S]){
				v2.pb(Mp(i.F + 1, i.S));
				c = min(c, s[i.F + 1][i.S]);
				vis[i.F + 1][i.S] = 1;
			}
			if(i.S + 1 < n && !vis[i.F][i.S + 1]){
				v2.pb(Mp(i.F, i.S + 1));
				c = min(c, s[i.F][i.S + 1]);
				vis[i.F][i.S + 1] = 1;
			}
		}
		vec.clear();
		for(pll i : v2){
			if(s[i.F][i.S] == c) vec.pb(i);
		}
		cout << c;
	}

    return 0;
}