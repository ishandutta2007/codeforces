#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10005;
char a[N], b[N * 100];
int n, m;
int jump[N][26];

int main() {
    scanf("%s%s", a + 1, b + 1);
    n = strlen(a + 1); m = strlen(b + 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            jump[i][j] = jump[i + 1][j];
            if (a[i + 1] == j + 'a') jump[i][j] = i + 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int s = i;
        int u = 0;
        while (jump[u][b[s] - 'a']) {
            u = jump[u][b[s] - 'a'];
            s++;
        }
        cnt++;
        if (s == i) {
            cnt = -1;
            break;
        }
        i = s - 1;
    }
    printf("%d\n", cnt);
    return 0;
}