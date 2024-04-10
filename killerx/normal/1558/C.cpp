#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n;
	scanf("%d", &n);
	std::vector <int> v(n);
	rep(i, n) scanf("%d", &v[i]);
	std::vector <int> cmd;
#define OP(x) cmd.push_back(x), std::reverse(v.begin(), v.begin() + x)
	for (int i = n / 2; i; -- i) {
		int a = 0; while (v[a] != i * 2) ++ a;
		int b = 0; while (v[b] != i * 2 + 1) ++ b;
		if (a % 2 != 1 || b % 2 != 0) return puts("-1"), void();
		OP(b + 1);
		if (a < b) a = b - a;
		OP(a);
		OP(a + 2);
		OP(3);
		OP(i * 2 + 1);
	}
	printf("%d\n", (int) cmd.size());
	for (int x : cmd) printf("%d ", x);
	printf("\n");
	rep(i, n) assert(v[i] == i + 1);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}