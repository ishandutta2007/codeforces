#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int a[maxN];
int n, k;
void solve() {
	scanf("%d%d", &n, &k);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		ans = max(ans, k | x);
	}
	printf("%d\n", ans);
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}