#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[1005][1005];

int start_a(int x, int y){
    static int memo[1005][1005];
    static bool bio[1005][1005];
    if (x < 0 || y < 0) return 0;
    if (bio[x][y]++) return memo[x][y];
    return memo[x][y] = a[x][y] + max(start_a(x - 1, y), start_a(x, y - 1));
}

int end_a(int x, int y){
    static int memo[1005][1005];
    static bool bio[1005][1005];
    if (x >= n || y >= m) return 0;
    if (bio[x][y]++) return memo[x][y];
    return memo[x][y] = a[x][y] + max(end_a(x + 1, y), end_a(x, y + 1));
}

int start_b(int x, int y){
    static int memo[1005][1005];
    static bool bio[1005][1005];
    if (x >= n || y < 0) return 0;
    if (bio[x][y]++) return memo[x][y];
    return memo[x][y] = a[x][y] + max(start_b(x + 1, y), start_b(x, y - 1));
}

int end_b(int x, int y){
    static int memo[1005][1005];
    static bool bio[1005][1005];
    if (x < 0 || y >= m) return 0;
    if (bio[x][y]++) return memo[x][y];
    return memo[x][y] = a[x][y] + max(end_b(x - 1, y), end_b(x, y + 1));
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", a[i] + j);
    int r = -10000000;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j){
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) continue;
        int nr = start_a(i - 1, j) + end_a(i + 1, j) + start_b(i, j - 1) + end_b(i, j + 1);
        if (nr > r) r = nr;
        nr = start_a(i, j - 1) + end_a(i, j + 1) + start_b(i + 1, j) + end_b(i - 1, j);
        //printf("%d %d -> %d\n", i, j, nr);
        if (nr > r) r = nr;
    }
    printf("%d\n", r);
    return 0;
}