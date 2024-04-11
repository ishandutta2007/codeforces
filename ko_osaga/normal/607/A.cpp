#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, dp[100005];
pi a[100005];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		a[i] = pi(x, x-y);
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++){
		int p = lower_bound(a+1, a+n+1, pi(a[i].second, -1e9)) - a - 1;
		dp[i] = dp[p] + 1;
	}
	cout << n - *max_element(dp, dp + n + 1);
}