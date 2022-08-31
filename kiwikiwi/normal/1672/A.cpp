#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int a[maxN];
void solve() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans += a[i] - 1;
	}
	if (ans % 2 == 1) puts("errorgorn");
	else puts("maomao90");
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}