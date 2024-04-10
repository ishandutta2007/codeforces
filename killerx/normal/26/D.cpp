#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)
#define forall(it, c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

template <typename T> inline void read(T &x) {
	x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (;  isdigit(c); c = getchar()) x = x * 10 + (c & 15);
	if (!f) x = -x;
}

int main() {
	int n, m, k;
	read(n); read(m); read(k);
	if (m <= k) { puts("1"); return 0; }
	if (m > n + k) { puts("0"); return 0; }
	double ans = 1;
	for (int i = 1; i <= k + 1; ++ i)
		ans = ans * (m - i + 1) / (n + i);
	printf("%.6f\n", 1.0 - ans);
	return 0;
}