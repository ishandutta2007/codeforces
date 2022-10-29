#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 510;

int a[MAXN][MAXN], vis[MAXN][MAXN];
int d[MAXN];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            vis[i][j] = -1;
            a[i][j] = 0;
        }
    for(int i = 1; i <= m; i++){
        int x, y;   
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++)
        d[i] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int i = 2; i <= n; i++)
            if (a[v][i] != a[1][n] && !d[i])
                d[i] = d[v] + 1, Q.push(i);
    }
    cout<<(d[n]?d[n]:-1)<<endl;
    /*
    queue<PII> Q;
    Q.push(PII(1,1));
    vis[1][1] = 0;
    while(!Q.empty()){
        PII Nico = Q.front();
        Q.pop();
        int x = Nico.first, y = Nico.second;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if ((i != j || i == n) && a[x][i] == 0 && a[y][j] == 1 && vis[i][j] == -1){
                    vis[i][j] = vis[x][y] + 1;
                    if (i == n && j == n)
                        goto LALA;
                    Q.push(PII(i, j));
                }
    }
    LALA: 
    cout<<vis[n][n]<<endl;*/
    return 0;
}