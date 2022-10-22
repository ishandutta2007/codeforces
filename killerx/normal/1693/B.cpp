#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n;
int fa[mxn];
int l[mxn], r[mxn];
long long s[mxn];
int a[mxn];

inline void Main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i)
		scanf("%d", &fa[i]), -- fa[i];
	rep(i, n) scanf("%d %d", &l[i], &r[i]);
	rep(i, n) s[i] = 0;
	int ans = 0;
	for (int i = n - 1; ~i; -- i) {
		if (s[i] < l[i]) a[i] = r[i], ++ ans;
		else a[i] = std::min(s[i], 1LL * r[i]);
		if (i) s[fa[i]] += a[i];
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}