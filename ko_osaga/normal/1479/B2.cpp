#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 998244353; //1e9 + 7;//998244353;
const int MAXN = 100005;

int n, a[MAXN], sum[MAXN];
int dp[MAXN];
int foo[MAXN];

int main(){
	fill(foo, foo + MAXN, -1e9);
	scanf("%d",&n);
	a[0] = n + 1;
	a[n + 1] = n + 2;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1; i <= n + 1; i++){
		sum[i] = sum[i - 1] + (a[i] == a[i - 1]);
	}
	int curMax = dp[0] - sum[1];
	for(int i = 1; i <= n; i++){
		dp[i] = max(curMax, foo[a[i + 1]] + 1) + sum[i];
		curMax = max(curMax, dp[i] - sum[i + 1]);
		foo[a[i]] = max(foo[a[i]], dp[i] - sum[i + 1]);
	}
	cout << n - dp[n] << endl;
}