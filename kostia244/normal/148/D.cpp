#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e3 + 5;
ld dp[maxn][maxn][2];
ld f(ll w, ll b, ll p) {
//	cout << w << " " << b << " " << p << "\n";
	if(w<0||b<0) return 0;
	if(w==0) return p?0:1;
	if(b==0) return 1;
	if(dp[w][b][p] > -1) return dp[w][b][p];
	ld pw = ld(w)/(ld)(w+b);
	ld pb = ld(b)/(ld)(w+b);
	ld pbb = ld(b-1)/(ld)(w+b-1);
	ld pbw = ld(w)/(ld)(w+b - 1);
	if(p) {
		dp[w][b][p] = pw + pb*(1. - f(w, b-1, 0));
	} else {
		dp[w][b][p] = pw + pb*(pbb*(1. - f(w, b-2, 1)) + pbw*(1. - f(w-1, b-1, 1)));
	}
//	cout << pw << " " << pb << " " << w << " " << b << " " << p << " " << dp[w][b][p] << "\n";
	return dp[w][b][p];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int w, b;
	cout << fixed << setprecision(15);
	cin >>w>>b;
	for(int i = 0; i <= w; i++)
		for(int j = 0; j <= b; j++)
			dp[i][j][0] = dp[i][j][1] = -1000069;
	cout << f(w, b, 1);
}