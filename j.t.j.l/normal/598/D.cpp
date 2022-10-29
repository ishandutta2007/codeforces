#include<bits/stdc++.h>

int cnt;
int n,m,k;
char s[1111][1111];
int c[1111][1111], vis[1111][1111];
int b[1111];
int tot;

void dfs(int p, int q){
    c[p][q] = cnt;
    vis[p][q] = 1;
    if (s[p-1][q] == '.' && !vis[p-1][q]) dfs(p-1,q);
    if (s[p-1][q] == '*') tot++;
    if (s[p+1][q] == '.' && !vis[p+1][q]) dfs(p+1,q);
    if (s[p+1][q] == '*') tot++;
    if (s[p][q-1] == '.' && !vis[p][q-1]) dfs(p,q-1);
    if (s[p][q-1] == '*') tot++;
    if (s[p][q+1] == '.' && !vis[p][q+1]) dfs(p,q+1);
    if (s[p][q+1] == '*') tot++;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for(int i = 0; i <= m+1; i++){
        s[0][i] = s[n+1][i] = '#';
    }
    for(int i = 1; i <= n; i++)
        s[i][0] = s[i][m+1] = '#';
    cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            vis[i][j] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if (!vis[i][j] && s[i][j] == '.'){
                tot = 0;
                cnt++;
                dfs(i,j);
                b[cnt] = tot;
            }
    for(int i = 1; i <= k; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", b[c[x][y]]);
    }
    return 0;
}