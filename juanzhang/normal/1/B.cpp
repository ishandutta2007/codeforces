#include <bits/stdc++.h>
using namespace std;

int n;
char str[100];

bool pd(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

bool check() {
	int pos = strlen(str);
	for (int i = 0; i < strlen(str); i++) {
		if (pd(str[i]) && pos < i - 1)
			return 0;
		if (pd(str[i])) pos = i;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	while (getchar() != '\n');
	while (n--) {
		memset(str, 0, sizeof str);
		gets(str);
		if (check()) {
			int flag = 0, pos = 1, x = 0;
			for (int i = 0; i < strlen(str); i++)
				if (! pd(str[i])) {
					flag = i - 1;
					break;
				}
			for (int i = flag; i >= 0; i--)
				x += (str[i] - 'A' + 1) * pos, pos *= 26;
			putchar('R');
			for (int i = flag + 1; i < strlen(str) && str[i] >= '0' && str[i] <= '9'; i++)
				putchar(str[i]);
			printf("C%d\n", x);
		} else {
			int flag, s = 1, x = 0, pos = 26;
			for (int i = strlen(str) - 1; i >= 0; i--)
				if (pd(str[i])) {
					flag = i + 1;
					break;
				}
			for (int i = flag; i < strlen(str) && str[i] >= '0' && str[i] <= '9'; i++)
				x = (x << 1) + (x << 3) + (str[i] ^ 48);
			for (; x > pos; s++, x -= pos, pos *= 26);
			pos /= 26;
			for (int i = 1; i <= s; i++, x %= pos, pos /= 26) {
				if (x) putchar(x / pos + (x % pos ? 1 : 0) + 'A' - 1);
				else putchar('Z');
			}
			for (int i = 1; i < flag - 1; i++)
				putchar(str[i]);
			putchar('\n');
		}
	}
	return 0;
}