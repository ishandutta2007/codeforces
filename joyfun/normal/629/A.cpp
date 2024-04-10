#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;

int n;
char g[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (g[i][j] == 'C' && g[i][k] == 'C') ans++;
                if (g[j][i] == 'C' && g[k][i] == 'C') ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}