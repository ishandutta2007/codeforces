#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const char str[3] = {'R', 'S', 'P'};

char c[N];
int cnt[3];
int T, n;

int main() {
	scanf("%d", &T);
	while (T--) {
		cnt[0] = cnt[1] = cnt[2] = 0;
		scanf("%s", c + 1); n = strlen(c + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 2; j++) {
				if (c[i] == str[j]) {
					++cnt[j];
				}
			}
		}
		int maxn = 0;
		for (int i = 1; i <= 2; i++) if (cnt[i] > cnt[maxn]) maxn = i;
		for (int i = 1; i <= n; i++) putchar(str[(maxn + 2) % 3]);
		putchar('\n');
	}
	return 0;
}