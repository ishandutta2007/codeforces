#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
char str[maxn], buf[maxn];

int main() {
	int n, tot = 0;
	scanf("%d %s", &n, str + 1);
	bool flg = 0;
	for (int i = 1; i <= n; i++) {
		if (flg || str[i + 1] >= str[i]) {
			buf[++tot] = str[i];
		} else {
			flg = 1;
		}
	}
	if (!flg) tot--;
	for (int i = 1; i <= tot; i++) {
		putchar(buf[i]);
	}
	return 0;
}