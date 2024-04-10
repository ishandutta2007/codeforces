#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;

void Main() {
	int n;
	static char s[mxn], t[mxn];
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	int ans = 1 << 30;
	int cnt0 = 0, cnt1 = 0;
	rep(i, n) {
		if (s[i] != t[i]) {
			if (s[i] < t[i]) ++ cnt0;
			else ++ cnt1;
		}
	}
	if (cnt0 == cnt1) ans = std::min(ans, cnt0 + cnt1);
	cnt0 = 0, cnt1 = 0;
	rep(i, n) {
		if ((s[i] ^ 1) != t[i]) {
			if ((s[i] ^ 1) < t[i]) ++ cnt0;
			else ++ cnt1;
		}
	}
	if (cnt0 == cnt1 + 1) ans = std::min(ans, cnt0 + cnt1);
	if (ans > n) puts("-1");
	else printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}