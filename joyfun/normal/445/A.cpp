#include <stdio.h>
#include <string.h>

int n, m;
char g[105][105];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf("%s", g[i]);
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (g[i][j] == '-') continue;
	    if ((i + j) % 2 == 0) g[i][j] = 'B';
	    else g[i][j] = 'W';
	}
    }
    for (int i = 0; i < n; i++)
	printf("%s\n", g[i]);
    return 0;
}