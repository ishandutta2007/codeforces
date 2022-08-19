#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

int n, a[200005], dp[200005];

int main(){
	scanf("%d",&n);
	int p1 = 0, p2 = 0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		while(p1+1 < i && a[i] - a[p1+1] >= 1440) p1++;
		while(p2+1 < i && a[i] - a[p2+1] >= 90) p2++;
		dp[i] = dp[i-1] + 20;
		dp[i] = min(dp[i], dp[p2] + 50);
		dp[i] = min(dp[i], dp[p1] + 120);
		printf("%d\n", dp[i] - dp[i-1]);
	}
}