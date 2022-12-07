#include <stdio.h>
#include <string.h>

char a[105], b[105];
int vis[30];

void solve(char *str, int val) {
	for (int i = 0; i < strlen(str); i++)
		vis[str[i] - 'a'] += val;
}

bool jud(char *a, char *b) {
	int i = 0, j = 0;
	while (i < strlen(a) && j < strlen(b)) {
		if (b[j] == a[i]) {
			i++; j++;
		}
		else i++;
	}
	if (j == strlen(b)) return true;
	return false;
}

void gao() {
	int i;
	for (i = 0; i < 26; i++) {
		if (vis[i] > 0) {
			printf("need tree\n");
			return;
		}
	}
	if (jud(a, b)) {
		printf("automaton\n");
	}
	else {
		if (strlen(a) == strlen(b)) printf("array\n");
		else printf("both\n");
	}
}

int main() {
	scanf("%s%s", a, b);
	solve(b, 1);
	solve(a, -1);
	gao();
	return 0;
}