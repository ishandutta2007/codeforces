#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

int n, a[maxN], b[maxN], pos[maxN], nxt[maxN], cnt[maxN];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++) pos[i] = n + 1;
	for (int i = n; i >= 1; i--) {
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	int r = 1;
	for (int i = 1; i <= n; i++) {
		while (r <= n && (a[r] != b[i] || cnt[r] == 0)) {
			if (a[r] != b[i] && cnt[r] != 0) {
				int q = nxt[r];
				if (q == n + 1) {
					puts("NO");
					return;
				}
				cnt[q] += cnt[r];
				cnt[r] = 0;
			}
			r++;
		}
		if (r > n) { puts("NO"); return; }
		cnt[r] --;
	}
	puts("YES");
}
int main() {
	int tc;
	scanf("%d", &tc);
	for (int T = 0 ; T < tc; T++) {
		solve();
	}
}