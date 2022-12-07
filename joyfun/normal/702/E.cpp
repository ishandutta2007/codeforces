#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;
int n;
int fa[N][40], Min[N][40];
long long k, sum[N][40];

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &fa[i][0]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Min[i][0]);
        sum[i][0] = Min[i][0];
    }
    for (int i = 1; i < 40; i++) {
        for (int j = 0; j < n; j++) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            Min[j][i] = min(Min[j][i - 1], Min[fa[j][i - 1]][i - 1]);
            sum[j][i] = sum[j][i - 1] + sum[fa[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        int u = i;
        long long s = 0;
        int m = INF;
        for (int j = 0; j < 40; j++) {
            if (k&(1LL<<j)) {
                s += sum[u][j];
                m = min(m, Min[u][j]);
                u = fa[u][j];
            }
        }
        printf("%lld %d\n", s, m);
    }
    return 0;
}