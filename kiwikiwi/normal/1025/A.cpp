#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[40];
char s[123456];
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 2) {
			puts("Yes");
			return 0;
		}
	}
	if (n == 1) {
		puts("Yes");
		return 0;
	}
	puts("No");
}