#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, color, ans[5005][2], len, sum[105];

struct Have {
    int color;
    int num;
} h[105];

int cmp(Have a, Have b) {
    return a.num > b.num;
}

int main() {
    len = 0;
    memset(ans, -1, sizeof(ans));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
	h[i].color = i;
    for (int i = 0; i < n; i ++) {
	scanf("%d", &color);
	h[color].num ++;
    }
    sum[0] = 0;
    sort(h + 1, h + 1 + m, cmp);
    for (int i = 1; i <= m; i ++) {
	sum[i] = sum[i - 1] + h[i].num;
	for (int j = 0; j < h[i].num; j ++) {
	    ans[len][0] = ans[len][1] = h[i].color;
	    len ++;
	}
    }
    for (int i = m - 1; i >= 1; i --) {
	for (int j = 0; j < sum[i] - sum[i - 1]; j ++) {
	    int a = sum[i] - 1 - j, b = sum[i] + j;
	    if (ans[a][1] == -1 || ans[b][1] == -1) break;
	    swap(ans[a][1], ans[b][1]);
	}
    }
    int anss = 0;
    for (int i = 0; i < len; i ++)
	if (ans[i][0] != ans[i][1])
	    anss ++;
    printf("%d\n", anss);
    for (int i = 0; i < len; i ++) {
	printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}