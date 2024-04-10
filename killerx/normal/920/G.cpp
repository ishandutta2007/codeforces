#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int p;
int pfac[15], pcnt;

void init() {
	int s = p;
	pcnt = 0;
	for (int x = 2; x * x <= s; ++ x) {
		if (s % x == 0) {
			pfac[pcnt ++] = x;
			while (s % x == 0) s /= x;
		}
	}
	if (s > 1) pfac[pcnt ++] = s;
}

int traverse(int id, int x, int coef) {
	if (id == pcnt) return x * coef;
	int ans = 0;
	ans += traverse(id + 1, x, coef);
	ans += traverse(id + 1, x / pfac[id], coef * -1);
	return ans;
}

int rank(int x) {
	return traverse(0, x, 1);
}

void Main() {
	int x, k;
	scanf("%d %d %d", &x, &p, &k);
	init();
	k += rank(x);
	int lb = x + 1, rb = 1000000000;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (rank(md) < k) lb = md + 1;
		else rb = md;
	}
	printf("%d\n", lb);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}