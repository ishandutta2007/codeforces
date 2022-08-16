#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 3005;
char s[N][N];
const int mod = 1e9 + 7;
int dp1[N][N], dp2[N][N];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
	}
	if(s[1][2] == '#' || s[2][1] == '#'){
		printf("0\n");
		return 0;
	}
	dp1[1][2] = dp2[2][1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && j == 1) continue;
			if(i == 1 && j == 2) continue;
			if(s[i][j] == '#') continue;
			dp1[i][j] = dp1[i - 1][j] + dp1[i][j - 1];
			if(dp1[i][j] >= mod) dp1[i][j] -= mod;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && j == 1) continue;
			if(i == 2 && j == 1) continue;
			if(s[i][j] == '#') continue;
			dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
			if(dp2[i][j] >= mod) dp2[i][j] -= mod;
		}
	}
	long long det = dp1[n - 1][m] * 1ll * dp2[n][m - 1] - dp1[n][m - 1] * 1ll * dp2[n - 1][m];
	det %= mod;
	if(det < 0) det += mod;
	// det = (det * ((mod + 1)/2)) % mod;
	printf("%lld", det);
}