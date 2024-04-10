#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n, forb; scanf("%d %d", &n, &forb);
	std::vector <int> x(n); rep(i, n) scanf("%d", &x[i]);
	std::sort(x.begin(), x.end());
	int ans = 0;
	rep(i, n) {
		ans += x[i];
		if (ans == forb) {
			if (i == n - 1) {
				printf("NO\n");
				return ;
			}
			ans -= x[i];
			std::swap(x[i], x[i + 1]);
			ans += x[i];
		}
	}
	printf("YES\n");
	rep(i, n) printf("%d ", x[i]);
	printf("\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}