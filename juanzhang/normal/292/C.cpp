#include <bits/stdc++.h>
using namespace std;

#define For(i) for (int i = 0; i < 1 << 8; i++)

const int maxn = 10;
int n;
bool a[maxn], vis[maxn];
char s[maxn << 1], str[maxn << 1];

vector <string> ans;

bool check(int x) {
	if (!x) {
		return a[0];
	}
	for (; x; x /= 10) {
		if (!a[x % 10]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	if (n > 6) {
		puts("0");
		return 0;
	}
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		a[x] = 1;
	}
	For(i1) if (check(i1)) For(i2) if (check(i2)) For(i3) if (check(i3)) {
		bool flag = 0;
		int i4 = 0, pw = 1;
		memset(vis, 0, sizeof vis);
		sprintf(str, "%d%d%d", i1, i2, i3);
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] != '.') {
				vis[str[i] ^ 48] = 1;
			}
		}
		for (int i = 0; i < 10; i++) {
			if (vis[i] ^ a[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int i = 1; i < 4; i++) {
			i4 += pw * (str[i - 1] ^ 48);
			pw = (pw << 3) + (pw << 1);
			if (i > 1 && str[i - 1] == 48) {
				continue;
			}
			if (i4 >= 1 << 8) {
				break;
			}
			flag = 0;
			sprintf(s, "%d%d%d%d", i1, i2, i3, i4);
            for (int j = 0; j < strlen(s); j++) {
				if (s[j] != s[strlen(s) - j - 1]) {
					flag = 1;
					break;
				}
            }
			if (flag) {
				continue;
			}
			sprintf(s, "%d.%d.%d.%d", i1, i2, i3, i4);
			ans.push_back(s);
		}
	}
	printf("%d\n", ans.size());
	for (string s : ans) {
		puts(s.c_str());
	}
	return 0;
}