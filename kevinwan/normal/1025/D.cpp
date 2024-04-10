#include <bits/stdc++.h>
#define mod(a,b) (a>=0?(a%b):(b-a%b))
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
	if (!a || !b)return 0;
	while (b)a %= b, a ^= b ^= a ^= b;
	return a;
}
int a[702];
bool dp[702][702][2][2];
bool kk[702][702];
int main() {
	int n,i,j,k,r;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", a + i);
	for (i = 1; i <= n + 1; i++)for (j = 0; j < 2; j++)for (k = 0; k < 2; k++) dp[i][i - 1][j][k] = 1;
	for (i = 0; i <= n + 1; i++)for (j = 0; j <= n + 1; j++)kk[i][j] = (gcd(a[i], a[j]) != 1);
	for (i = 0; i < n; i++) {
		for (j = 1; j + i <= n; j++) {
			r = j + i;
			for (k = j; k <= r; k++) {
				bool poss = dp[j][k - 1][0][1] && dp[k + 1][r][1][0];
				dp[j][r][0][0] |= poss;
				dp[j][r][1][0] |= poss && kk[k][j-1];
				dp[j][r][0][1] |= poss &&kk[k][r+1];
			}
		}
	}
	if (dp[1][n][0][0])printf("Yes");
	else printf("No");
	getchar(); getchar();
}