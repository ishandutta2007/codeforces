#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5;

int n, C;
bool is[mxn];
int sum[mxn];

inline void Main() {
	scanf("%d %d", &n, &C);
	for (int i = 1; i <= C; ++ i) is[i] = 0;
	rep(i, n) {
		int x;
		scanf("%d", &x);
		is[x] = 1;
	}
	for (int i = 1; i <= C; ++ i) sum[i] = sum[i - 1] + is[i];
	bool ok = 1;
	for (int x = 1; x <= C; ++ x) {
		if (!is[x]) {
			for (int k = 1; k * x <= C; ++ k) {
				if (is[k]) {
					int yl = k * x;
					int yr = k * (x + 1) - 1;
					yr = std::min(yr, C);
					if (yl <= yr && sum[yr] - sum[yl - 1]) ok = 0;
				}
			}
		}
	}
	puts(ok ? "Yes" : "No");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}