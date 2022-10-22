#include <bits/stdc++.h>
using namespace std;

int cnt[26];
char s[105], t[105], p[105];

void solve() {
	memset(cnt, 0, sizeof cnt);
	scanf("%s %s %s", s + 1, t + 1, p + 1);
	int n = strlen(p + 1);
	for (int i = 1; i <= n; i++) {
		cnt[p[i] - 'a']++;
	}
	int l1 = strlen(s + 1);
	int l2 = strlen(t + 1);
	if (l1 > l2) {
		puts("NO"); return;
	}
	int i = 1, j = 1;
	for (; i <= l2; i++) {
		for (; i <= l2 && t[i] != s[j]; i++) {
			if (!cnt[t[i] - 'a']) {
				puts("NO"); return;
			}
			cnt[t[i] - 'a']--;
		}
		j += i <= l2 && t[i] == s[j];
	}
	if (j <= l1) {
		puts("NO"); return;
	}
	puts("YES");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
  return 0;
}