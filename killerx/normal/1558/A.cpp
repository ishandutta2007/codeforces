#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int a, b;
std::set <int> avai;
int x, y;

void doit() {
	for (int s = 0; s <= a; ++ s) {
		int t = a - s;
		if (s < 0 || s > x) continue;
		if (t < 0 || t > y) continue;
		avai.insert(x - s + t);
	}
}

void Main() {
	scanf("%d %d", &a, &b);
	int n = a + b;
	avai.clear();
	x = n / 2, y = n - x;
	doit();
	y = n / 2, x = n - x;
	doit();
	printf("%d\n", (int) avai.size());
	for (int k : avai) printf("%d ", k);
	printf("\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}