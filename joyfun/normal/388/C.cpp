#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 105;
int n, i, j;

struct Pipe {
    int s[N], top, bottom, sum;
} p[N];

bool cmp(Pipe a, Pipe b) {
    return a.sum > b.sum;
}

int main() {
    memset(p, 0, sizeof(p));
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i].bottom);
        for (j = 0; j < p[i].bottom; j++) {
            scanf("%d", &p[i].s[j]);
            p[i].sum = p[i].s[p[i].bottom / 2];
        }
    }
    sort(p, p + n, cmp);
    int ans1 = 0, ans2 = 0, bo = 0;
    for (i = 0; i < n; i++) {
        if (p[i].bottom % 2== 0) {
            for (j = 0; j < p[i].bottom / 2; j++) {
                ans1 += p[i].s[j];
            }
            for (; j< p[i].bottom;j++)
                ans2 += p[i].s[j];
        }
        else {
        for (j = 0; j < p[i].bottom / 2 + (bo % 2 == 0); j++)
            ans1 += p[i].s[j];
        for (;j < p[i].bottom; j++)
            ans2 += p[i].s[j];
        bo++;
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}