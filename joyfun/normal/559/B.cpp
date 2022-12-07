#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 200005;
char s[2][N];


void gao(int u, int l, int r) {
    if ((r - l + 1) % 2) return;
    int mid = (l + r) / 2;
    gao(u, l, mid);
    gao(u, mid + 1, r);
    if (strncmp(s[u] + l, s[u] + mid + 1, (r - l + 1) / 2) > 0) {
        for (int i = l; i <= mid; i++)
            swap(s[u][i], s[u][i + (r - l + 1) / 2]);
    }
}

int main() {
    scanf("%s%s", s[0], s[1]);
    int n = strlen(s[0]);
    gao(0, 0, n - 1); gao(1, 0, n - 1);
    printf("%s\n", strcmp(s[0], s[1]) == 0 ? "YES" : "NO");
    return 0;
}