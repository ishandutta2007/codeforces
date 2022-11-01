#include <cstdio>
#include <algorithm>
using namespace std;

char s[2002][2002];
constexpr int dx[4] = {1, -1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
constexpr char c1[4] = {'^', 'v', '<', '>'};
constexpr char c2[4] = {'v', '^', '>', '<'};
int head, tail;
pair<int, int> que[2000 * 2000];

#define FOR_NEIGHBOR(X, Y, XX, YY, TEMP) \
    for(int TEMP = 0, X, Y; TEMP < 4 && (X = XX + dx[TEMP], Y = YY + dy[TEMP], true); TEMP++) \
        if(s[X][Y] == '.')

int neighbor(int i, int j) {
    int cnt = 0;
    FOR_NEIGHBOR(x, y, i, j, k) cnt++;
    return cnt;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    fill_n(s[0], m + 2, '*');
    for(int i = 1; i <= n; i++) {
        s[i][0] = '*';
        scanf("%s", s[i] + 1);
        s[i][m + 1] = '*';
    }
    fill_n(s[n + 1], m + 2, '*');

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i][j] == '.' && neighbor(i, j) == 1)
                que[tail++] = {i, j};

    while(head != tail) {
        int i = que[head].first, j = que[head].second;
        head++;
        if(s[i][j] != '.')
            continue;
        FOR_NEIGHBOR(x, y, i, j, k) {
            s[i][j] = c1[k];
            s[x][y] = c2[k];
            FOR_NEIGHBOR(p, q, x, y, l)
                if(neighbor(p, q) == 1)
                    que[tail++] = {p, q};
            break;
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i][j] == '.') {
                puts("Not unique");
                return 0;
            }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            putchar(s[i][j]);
        putchar('\n');
    }
}