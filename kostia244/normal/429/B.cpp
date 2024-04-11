#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll
using namespace std;

int ans, t, n, m, a[1006][1006], dp1[1006][1006], dp2[1006][1006], dp3[1006][1006], dp4[1006][1006];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 0; i <= n+3; i++)
		for(int j = 0; j <= m+3; j++)
			dp1[i][j] = dp2[i][j] = -1000000000ll;
	dp1[1][1] = a[1][1];
	for(int i = 1; i <= n; i++)
		for(int j = 1+(i==1); j <= m; j++) {
			dp1[i][j] = a[i][j]+max(dp1[i - 1][j], dp1[i][j - 1]);
		}
	dp2[n][m] = a[n][m];
	for(int i = n; i > 0; i--)
		for(int j = m-(i==n); j > 0; j--) {
			dp2[i][j] = a[i][j]+max(dp2[i + 1][j], dp2[i][j + 1]);
		}
	dp3[n][1] = a[n][1];
	for(int i = n; i > 0; i--)
		for(int j = 1+(i==n); j <= m; j++) {
			dp3[i][j] = a[i][j]+max(dp3[i + 1][j], dp3[i][j - 1]);
		}
	dp4[1][m] = a[1][m];
	for(int i = 1; i <= n; i++)
		for(int j = m-(i==1); j > 0; j--) {
			dp4[i][j] = a[i][j]+max(dp4[i - 1][j], dp4[i][j + 1]);
		}
	for(int i=2;i<n;i++)
			for(int j=2;j<m;j++)
			{
				int temp=max(dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1],dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
				if(temp>ans) ans=temp;
			}
	cout << ans;
}