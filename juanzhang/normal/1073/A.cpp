#include <bits/stdc++.h>
using namespace std;

#define re register int
const int maxn = 1010;
int n, cnt[26][maxn]; char str[maxn];

int main() {
	scanf("%d %s", &n, str + 1);
	for (re i = 1; i <= n; i++) {
		for (re j = 0; j < 26; j++) {
			cnt[j][i] = cnt[j][i - 1];
		}
		cnt[str[i] - 'a'][i]++;
	}
	bool flag; int l, r;
	for (re i = 1; i <= n; i++) {
		l = r = 0;
		for (re j = i; j <= n; j++) {
			flag = 1;
			for (re k = 0; k < 26; k++) {
				if (cnt[k][j] - cnt[k][i - 1] > (j - i + 1) >> 1) {
					flag = 0; break;
				}
			}
			if (flag) {
				l = i, r = j; break;
			}
		}
		if (l) {
			puts("YES");
			for (re k = l; k <= r; k++) {
				putchar(str[k]);
			}
			return 0;
		}
	}
	puts("NO");
	return 0;
}