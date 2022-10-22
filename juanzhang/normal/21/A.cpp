#include <bits/stdc++.h>
using namespace std;

#define exit return puts("NO"), 0
const int maxn = 110;
int n; char str[maxn];

bool check(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c > 47 && c < 58) || c == '_';
}

int count(char c) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += str[i] == c;
	}
	return res;
}

int main() {
	scanf("%s", str + 1), n = strlen(str + 1);
	if (count('@') > 1 || !count('@') || count('/') > 1) exit;
	for (int i = 1; i <= n; i++) {
		if (str[i] == str[i - 1] && str[i] == '.') exit;
	}
	int pos_at = 0;
	for (int i = 1; i <= n; i++) {
		if (str[i] == '@') {
			pos_at = i; break;
		}
		if (!check(str[i])) exit;
	}
	if (pos_at < 2 || pos_at > 17) exit;
	if (str[pos_at + 1] == '.') exit;
	int pos_r = n + 1;
	for (int i = pos_at + 1; i <= n; i++) {
		if (str[i] == '/') {
			pos_r = i; break;
		}
		if (!check(str[i]) && str[i] != '.') exit;
	}
	if (str[pos_r - 1] == '.') exit;
	if (pos_r - pos_at - 1 < 1 || pos_r - pos_at - 1 > 32) exit;
	for (int i = pos_r + 1; i <= n; i++) {
		if (!check(str[i])) exit;
	}
	if (pos_r == n || n - pos_r > 16) exit;
	puts("YES");
	return 0;
}