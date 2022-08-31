#include <bits/stdc++.h>
using namespace std;

const int N = 234567;
int n, m;
char s[N], t[N];
bool check() {
	bool star = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') star = 1;
	}

	if (!star) {
		if (n != m) return 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i])
				return 0;
		}
		return 1;
	}
	if (m < n - 1) return 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') break;
		if (s[i] != t[i]) return 0;
	}
	for (int i = 0; i < n; i++) {
		if (s[n - 1 - i] == '*') break;
		if (s[n - 1 - i] != t[m - 1 - i]) return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	scanf("%s", t);
	puts(check() ? "YES" : "NO");
}