#include <cstdio>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
char s[502][502];
int com[502][502], maxcom;
int comsz[500 * 500];
void dfs(int i, int j, int c) {
    if(s[i][j] != '.')
        return;
    if(com[i][j] != 0)
        return;
    com[i][j] = c;
    comsz[c]++;
    dfs(i + 1, j, c);
    dfs(i - 1, j, c);
    dfs(i, j + 1, c);
    dfs(i, j - 1, c);
}
int cov[500 * 500];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(s[i][j] == '.' && com[i][j] == 0)
                dfs(i, j, ++maxcom);
    int ans = 0;
    for(int i = 1; i + m <= n + 1; i++) {
        fill_n(cov, maxcom + 1, 0);
        int size = 0;
        for(int j = 0; j < m; j++)
            if(s[i + j][1] == '.')
                if(cov[com[i + j][1]]++ == 0)
                    size += comsz[com[i + j][1]];
        // fprintf(stderr, "> %d\n", size);
        for(int j = 1; j <= m; j++) {
            if(s[i - 1][j] == '.')
                if(cov[com[i - 1][j]]++ == 0)
                    size += comsz[com[i - 1][j]];
            for(int k = 0; k < m; k++) {
                if(s[i + k][j] != '.') {
            // fprintf(stderr, "> YEE\n");

                    size++;
                }
                if(s[i + k][1 + j] == '.')
                    if(cov[com[i + k][1 + j]]++ == 0)
                        size += comsz[com[i + k][1 + j]];
            }
            if(s[i + m][j] == '.')
                if(cov[com[i + m][j]]++ == 0)
                    size += comsz[com[i + m][j]];
        }
        ans = max(ans, size);
        for(int j = m + 1; j + 1 <= n + 1; j++) {
            // fprintf(stderr, "> %d -> ", size);
            // --
            if(s[i - 1][j - m] == '.')
                if(--cov[com[i - 1][j - m]] == 0)
                    size -= comsz[com[i - 1][j - m]];
            for(int k = 0; k < m; k++) {
                if(s[i + k][j - m] != '.')
                    size--;
                if(s[i + k][j - m - 1] == '.')
                    if(--cov[com[i + k][j - m - 1]] == 0)
                        size -= comsz[com[i + k][j - m - 1]];
            }
            if(s[i + m][j - m] == '.')
                if(--cov[com[i + m][j - m]] == 0)
                    size -= comsz[com[i + m][j - m]];
            // fprintf(stderr, "%d -> ", size);
            // ++
            if(s[i - 1][j] == '.')
                if(cov[com[i - 1][j]]++ == 0)
                    size += comsz[com[i - 1][j]];
            for(int k = 0; k < m; k++) {
                if(s[i + k][j] != '.')
                    size++;
                if(s[i + k][j + 1] == '.')
                    if(cov[com[i + k][j + 1]]++ == 0)
                        size += comsz[com[i + k][j + 1]];
            }
            if(s[i + m][j] == '.')
                if(cov[com[i + m][j]]++ == 0)
                    size += comsz[com[i + m][j]];
            // fprintf(stderr, "%d\n", size);
            ans = max(ans, size);
        }
    }
    printf("%d\n", ans);
}