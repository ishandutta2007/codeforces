#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int a, b, k;
	scanf("%d %d %d", &a, &b, &k);
	int n = a + b;
	std::string sa(n, '0');
	std::string sb(n, '0');
	bool f = b > 1;
	if (f) sa[0] = sb[0] = '1', -- b;
	if (k + f >= n) { puts("No"); return 0; }
	sa[0 + f] = sb[k + f] = '1', -- b;
	rep(i, n) if (b)
		if (sa[i] != '1' && sb[i] != '1')
			sa[i] = sb[i] = '1', -- b;
	if (b) { puts("No"); return 0; }
	if (sa[0] != '1' || sb[0] != '1') { puts("No"); return 0; }
	printf("Yes\n%s\n%s\n", sa.c_str(), sb.c_str());
	return 0;
}