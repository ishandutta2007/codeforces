#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
int n;
char a[N], b[N];

int g[30][30];
int vis[30];

int main() {
    scanf("%d%s%s", &n, a + 1, b + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i]) sum++;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            if (g[b[i] - 'a'][a[i] - 'a']) {
                printf("%d\n%d %d\n", sum - 2, i, g[b[i] - 'a'][a[i] - 'a']);
                return 0;
            }
            g[a[i] - 'a'][b[i] - 'a'] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            vis[b[i] - 'a'] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i] && vis[a[i] - 'a']) {
            printf("%d\n%d %d\n", sum - 1, i, vis[a[i] - 'a']);
            return 0;
        }
    }
    printf("%d\n-1 -1\n", sum);
    return 0;
}