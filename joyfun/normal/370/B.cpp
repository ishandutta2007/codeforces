#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 105, M = 105;
int n, m[N][M], have[N], cross[N], vis[M];

bool judge(int i) {
    memset(vis, 0, sizeof(vis));
    for (int j = 1; j <= have[i]; j ++)
	vis[m[i][j]] = 1;
    for (int k = 1; k <= n; k ++) {
	if (k != i && have[k] <= have[i]) {
	    int j;
	    for (j = 1; j <= have[k]; j ++) {
		if (vis[m[k][j]] == 0)
		    break;
	    }
	    if (j == have[k] + 1)
		return false;
	}
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
	scanf("%d", &have[i]);
	for (int j = 1; j <= have[i]; j ++)
	    scanf("%d", &m[i][j]);
	sort(m[i] + 1, m[i] + have[i] + 1);
    }
    for (int i = 1; i <= n; i ++) {
	if (judge(i)) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}