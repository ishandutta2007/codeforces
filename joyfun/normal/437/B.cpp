#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 100001;
int sum, limit, ans[N], an = 0;
int i, j;
struct Low {
    int lowbit;
    int num;
} l[N];

bool cmp(Low a, Low b) {
    return a.lowbit > b.lowbit;
}

int main() {
    scanf("%d%d", &sum, &limit);
    for (i = 1; i < N; i++) {
        l[i].num = i;
        l[i].lowbit = (i&(-i));
    }
    sort(l + 1, l + N, cmp);
    for (i = 1; i < N; i++) {
        if (l[i].num <= limit) {
            if (sum >= l[i].lowbit) {
                ans[an++] = l[i].num;
                sum -= l[i].lowbit;
            }
        }
        if (sum == 0) break;
    }
    if (sum != 0) printf("-1\n"); 
    else {
        printf("%d\n", an);
        for (int i = 0; i < an - 1; i++)
            printf("%d ", ans[i]);
        printf("%d\n", ans[an - 1]);
    }
    return 0;
}