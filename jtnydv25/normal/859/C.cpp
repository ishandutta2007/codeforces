#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &x)
const int N = 55;
int A[N];
int dp[2][N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++) sd(A[i]);
	dp[0][n] = A[n];
	dp[1][n] = 0;
	int sm = A[n];
	for(int i = n - 1; i >= 0; i--){
		dp[0][i] = max(dp[0][i + 1], A[i] + dp[1][i + 1]);
		dp[1][i] = min(dp[1][i + 1] + A[i], dp[0][i + 1]);
		sm += A[i];
	}
	printf("%d %d\n", dp[1][1], sm - dp[1][1]);
}