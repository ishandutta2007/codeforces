#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[105];
int vis[30];
char aa[105], bb[105];
int an, bn;

int main() {
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) vis[str[i] - 'A']++;
	int c;
	for (int i = 0; i < 26; i++) if (vis[i] == 2) c = i;
	int l, r;
	for (int i = 0; i < len; i++) {
		if (c == str[i] - 'A') {
			l = i;
			break;
		}
	}
	for (int i = len - 1; i >= 0; i--) {
		if (c == str[i] - 'A') {
			r = i;
			break;
		}
	}
	int f = ((l + len - 1 - r - 1) % 2 + 2) % 2;
	if (l + 1 == r) printf("Impossible\n");
	else {
		if (!f) aa[an++] = c + 'A';
		for (int i = r + 1; i < len; i++) aa[an++] = str[i];
		for (int i = 0; i < l; i++) aa[an++] = str[i];
		if (f) aa[an++] = c + 'A';
		for (int i = l + 1; i < r; i++) bb[bn++] = str[i];
	//	printf("%d %d %d %d\n", an, bn, f, bn / 2 + f);
		for (int i = an / 2 - 1; i >= 0; i--) printf("%c", aa[i]);
		for (int i = 0; i < bn / 2 + f; i++) printf("%c", bb[i]);
		printf("\n");
		for (int i = an / 2; i < an; i++) printf("%c", aa[i]);
		for (int i = bn - 1; i >= bn / 2 + f; i--) printf("%c", bb[i]);
		printf("\n");
	}
	return 0;
}