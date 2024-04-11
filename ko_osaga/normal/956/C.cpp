#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, int> pi;
const int MAXN = 100005;

int n, a[MAXN];
int dp[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		dp[i] = max(dp[i-1], a[i] + 1);
	}
	for(int i=n-1; i; i--) dp[i] = max(dp[i+1] - 1, dp[i]);
	cout << accumulate(dp + 1, dp + n + 1, 0ll) - accumulate(a + 1, a + n + 1, 0ll) - n << endl;
}