#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 2020;
ll n;
ld h;
ld p;
ld dp[maxn][maxn][2][2];
ld x[maxn];
ld f(int l, int r, int lf, int rf) {
	if(l > r) return 0;
	if(dp[l][r][lf][rf] > -1) return dp[l][r][lf][rf];
	ld lcov = lf ? min(x[l], x[l-1]+h) : x[l-1];
	ld rcov = rf ? x[r+1] : max(x[r], x[r+1]-h);
	
	ld l2l = min(x[l] - lcov, h);
	ld l2r = min(min(x[l+1], rcov)-x[l], h);
	ld r2l = min(x[r]-max(lcov, x[r-1]), h);
	ld r2r = min(rcov-x[r], h);
	
	if(lf && x[l-1]+h > x[l]) return dp[l][r][lf][rf] = l2r + f(l+1, r, 1, rf);
	if(!rf && x[r+1]-h < x[r]) return dp[l][r][lf][rf] = r2l + f(l, r-1, lf, 0);
	ld ls = 0, rs = 0;
	
	ls += p * (l2l + f(l+1, r, 0, rf));
	ls += (1.-p) * (l2r + f(l+1, r, 1, rf));
	rs += p * (r2l + f(l, r-1, lf, 0));
	rs += (1.-p) * (r2r + f(l, r-1, lf, 1));
	
	//cout << l << " " << r << " " << lf << " " << rf << " | " << lcov << " " << rcov << " | " << ls << " " << rs << endl;
	//cout << l2l << " " << l2r << " || " << r2l << " " << r2r << endl;
	
	return dp[l][r][lf][rf] = (ls+rs)/2;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cin >> n >> h >> p;
    for(int i = 1; i <= n; i++) cin >> x[i];
    sort(x+1, x+n+1);
    x[0] = -(1<<28);
    x[n+1] = 1<<28;
	memset(dp, -1, sizeof dp);
	cout << f(1, n, 0, 1);
}