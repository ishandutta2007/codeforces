#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 505;

int n, k;
int ans[N][N];

int main() {
    scanf("%d%d", &n, &k);
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k - 1; j++) {
            ans[i][j] = cnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            ans[i][j] = cnt++;
        }
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += ans[i][k];
    printf("%lld\n", sum);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}