#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 123456;

int n, a[maxn], s[maxn];
void solve() {
	scanf("%d",&n);
	int ans = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + (a[i] == 0);
	}
	for (int i = 0; i <= n; i++) {
		int c1 = i - s[i], c0 = s[n] - s[i];
		ans = min(ans, max(c0, c1));
	}
	printf("%d\n", ans);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		solve();
	}
}