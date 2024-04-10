#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int m;
char str[maxn], s[maxn];

int main() {
	gets(str + 1);
	scanf("%d", &m);
	for (int l, r, k; m--; ) {
		scanf("%d %d %d", &l, &r, &k);
		k %= r - l + 1;
		for (int i = l; i <= r; i++) {
			s[i] = str[i];
		}
		for (int i = l; i <= r; i++) {
			if (i + k > r) {
				str[i + k + l - r - 1] = s[i];
			} else {
				str[i + k] = s[i];
			}
		}
	}
	puts(str + 1);
	return 0;
}