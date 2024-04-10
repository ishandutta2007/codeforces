#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, e, f;
int main() {
	scanf("%d", &n);
	scanf("%d%d", &a, &b);
	scanf("%d%d", &c, &d);
	scanf("%d%d", &e, &f);
	auto separate = [](int a, int b, int c) {
		if (a > b) swap(a, b);
		return a < c && c < b;
	};
	if (separate(c, e, a) || separate(d, f, b)) {
		puts("NO");
	} else {
		puts("YES");
	}
}