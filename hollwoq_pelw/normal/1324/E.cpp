#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS         std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rnd(n)      fixed << setprecision(n)

#define F           first
#define S           second
#define pii         pair<int, int>
#define pll         pair<ll, ll>

#define pb          push_back
#define all(a)      a.begin(), a.end()
#define rall(a)     a.rbegin(), a.rend()
#define sz(a)       a.size()

#define pi          acos(-1.0)
#define g_sin(a)    sin(a*pi/180)
#define g_cos(a)    cos(a*pi/180)
#define g_tan(a)    tan(a*pi/180)

const int mod1 = 998244353, mod2 = 1e+7;

int n,h,l,r,dp[2005][2005],a[2005];
void solve(){
	cin>>n>>h>>l>>r;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i < h; i++) dp[0][i] = -1e9;
	
	dp[0][0]=0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < h; j++){
			int x = j - a[i];
			if(x < 0)x += h;
			dp[i][j] = dp[i-1][x] + (l<=j&&j<=r);
			x = j - a[i] + 1;
			if(x < 0) x += h;
			dp[i][j] = max(dp[i][j], dp[i-1][x] + (l<=j&&j<=r));
		}
	}
	int mx = 0;
	for(int i = 0; i < h; i++) mx = max(mx, dp[n][i]);
	cout << mx;
}

int main(){
    IOS;
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}