#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;

int n, m, c;

int main() {
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int Min = INF;
        for (int j = 0; j < m; j++) {
            scanf("%d", &c);
            Min = min(Min, c);
        }
        ans = max(Min, ans);
    }
    printf("%d\n", ans);
    return 0;
}