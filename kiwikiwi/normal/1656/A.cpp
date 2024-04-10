#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN (1 << 18) + 10

int n, a[maxN];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d %d\n", max_element(a + 1, a + n + 1) - a, min_element(a + 1, a + n + 1) - a);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++) {
		solve();
	}
}