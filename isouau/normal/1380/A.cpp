#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int a[N], l[N], r[N];
int T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(l, 0, sizeof(l)); memset(r, 0, sizeof(r));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int minn = 1;
		for (int i = 2; i <= n; i++) {
			if (a[minn] < a[i]) {
				l[i] = minn;
			} else {
				minn = i;
			}
		}
		minn = n;
		for (int i = n - 1; i >= 1; i--) {
			if (a[minn] < a[i]) {
				r[i] = minn;
			} else {
				minn = i;
			}
		}
		bool ok = 0;
		for (int i = 2; i < n; i++) {
			if (l[i] && r[i]) {
				puts("YES");
				printf("%d %d %d\n", l[i], i, r[i]);
				ok = 1; break;
			}
		}
		if (!ok) puts("NO");
	}
	return 0;
}