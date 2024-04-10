#include <cstdio>
#include <algorithm>
using namespace std;

char a[52][52];
char s[101];

bool ok(int si, int sj, int (&map)[4]) {
    // puts("");
    // for (int i = 0; i < 4; i++)
    //     printf("%d ", map[i]);
                    //    D  R  U   L
    constexpr int dx[] = {1, 0, -1, 0};
    constexpr int dy[] = {0, 1, 0, -1};
    for (int i = 0; s[i]; i++) {
        si += dx[map[s[i] - '0']];
        sj += dy[map[s[i] - '0']];
        // printf("(%d %d %c) ", si, sj, a[si][sj]);
        if (a[si][sj] == '#')
            return false;
        if (a[si][sj] == 'E')
            return true;
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    fill_n(a[0], m + 2, '#');
    for (int i = 1; i <= n; i++) {
        a[i][0] = '#';
        scanf("%s", a[i] + 1);
        a[i][m + 1] = '#';
    }
    fill_n(a[n + 1], m + 2, '#');

    int si = 0, sj = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'S')
                si = i, sj = j;

    scanf("%s", s);
    int map[4] = {0, 1, 2, 3}, ans = 0;
    do {
        if (ok(si, sj, map))
            ans++;
    } while (next_permutation(map, map + 4));
    printf("%d\n", ans);
}