#include <cstdio>

char s[1001];

int main() {
	int i, n;
	scanf("%s", s);
	for (i = n = 0; s[i] && s[i] == '0'; i++);
	if (!s[i]) {
		puts("no");
		return 0;
	}
	while (s[i]) {
		if (s[i] == '0') n++;
		i++;
	}
	puts(n > 5 ? "yes" : "no");
}