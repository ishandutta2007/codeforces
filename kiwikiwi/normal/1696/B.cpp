#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int a[maxN];
int n, k;
void solve() {
	scanf("%d", &n);
	int fp = n + 1;
	int lp = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 0) {
			fp = min(fp, i);
			lp = max(lp, i);
		}
	}
	if (lp == -1) {
		puts("0");
		return;
	}
	for (int i = fp; i <= lp; i++) {
		if (a[i] == 0) {
			puts("2");
			return;
		}
	}
	puts("1");
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}