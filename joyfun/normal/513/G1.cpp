#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, K;
int a[10];
double sum = 0, cnt = 0;
void dfs(int h) {
    if (h == K) {
        cnt++;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++)
                if (a[i] > a[j]) sum++;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= (j + i) / 2; k++) {
                swap(a[k], a[j - k + i]);
            }
            dfs(h + 1);
            for (int k = i; k <= (j + i) / 2; k++)
                swap(a[k], a[j - k + i]);
        }
    }
}

int main() {
    while (~scanf("%d%d", &n, &K)) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        dfs(0);
        printf("%.10lf\n", sum / cnt);
    }
    return 0;
}