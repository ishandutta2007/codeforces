#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long double ld;
int n = 10;
pair<int, int> get_pos(int i) {
	int x = i / n;
	int y = i % n;
	if(x % 2 == 1) {
		y = 9 - y;
	}
	return {x, y};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    vvi a(n, vi(10));
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		cin >> a[i][j];
    	}
    }
    vector<vector<ld>> dp(n, vector<ld>(n, 0));
 	for(int i = 1; i < n * n; i++) {
 		ld here = 0;
 		if(i < 6) {
 			for(int j = 0; j < i; j++) {
 				here += dp[0][j];
 			}
 			here /= i;
 			here += (ld)6 / i;
 			dp[0][i] = here;
 			continue;
 		}
 		for(int j = 1; j <= 6; j++) {
 			auto p = get_pos(i - j);
 			int x = p.first;
 			int y = p.second;
 			here += min(dp[x][y], dp[x - a[x][y]][y]);
 		}
 		auto p = get_pos(i);
 		int x = p.first;
 		int y = p.second;
 		//cout << x << ' ' << y << endl;
 		dp[x][y] = here / 6 + 1;
 	}
 	cout << fixed << setprecision(17) << dp[n - 1][0] << '\n';

}