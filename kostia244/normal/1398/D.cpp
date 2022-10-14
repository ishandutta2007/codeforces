//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 222, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[maxn][maxn][maxn];
void minq(int &a, int b) {
	a = max(a, b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	vector<int> a(x), b(y), c(z);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	for(auto &i : c) cin >> i;
	sort(rall(a));
	sort(rall(b));
	sort(rall(c));
	memset(dp, -0x4f, sizeof dp);
	dp[0][0][0] = 0;
	for(int i = 0; i <= x; i++)
		for(int j = 0; j <= y; j++)
			for(int k = 0; k <= z; k++) {
				minq(dp[i+1][j][k], dp[i][j][k]);
				minq(dp[i][j][k+1], dp[i][j][k]);
				minq(dp[i][j+1][k], dp[i][j][k]);
				if(i < x && j < y)
					minq(dp[i+1][j+1][k], dp[i][j][k]+a[i]*b[j]);
				if(i < x && k < z)
					minq(dp[i+1][j][k+1], dp[i][j][k]+a[i]*c[k]);
				if(j < y && k < z)
					minq(dp[i][j+1][k+1], dp[i][j][k]+b[j]*c[k]);
			}
	cout << dp[x][y][z] << endl;
}