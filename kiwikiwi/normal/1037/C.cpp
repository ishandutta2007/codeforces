#include <bits/stdc++.h>
using namespace std;

const int N = 1234567;

int n, ans;
char s[N], t[N];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] != s[i + 1] && t[i] != t[i + 1] && s[i] != t[i]) {
			swap(s[i], s[i + 1]);
			ans += 1;
		}
	}
	for (int i = 0; i < n; i++)
		if (s[i] != t[i])
			ans += 1;
	printf("%d\n", ans);
}