#include<bits/stdc++.h>

using namespace std;

const int MAXN = 600;

char a[MAXN][MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];
int sum[MAXN][MAXN];
int ff[MAXN][MAXN], gg[MAXN][MAXN];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            char ch = getchar();
            while(ch != '#' && ch != '.')
                ch = getchar();
            a[i][j] = ch;
        }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++)
            if (a[i][j] == '.' && a[i][j+1] == '.')
                f[i][j] = 1;
            else
                f[i][j] = 0;
        f[i][m] = 0;
    }
    for(int j = 1; j <= m; j++){
        for(int i = 1; i < n; i++)
            if (a[i][j] == '.' && a[i+1][j] =='.')
                g[i][j] = 1;
            else
                g[i][j] = 0;
        g[n][j] = 0;
    }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            f[j][i] += f[j-1][i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            g[i][j] += g[i][j-1];
/*  sum[1][1] = 0;
    for(int i = 2; i <= m; i++)
        sum[1][i] = sum[1][i-1] + f[1][i-1];
    for(int i = 2; i <= n; i++){
        sum[i][1] = sum[i-1][1] + g[i-1][1];
        for(int j = 2; j <= m; j++)
            sum[i][j] = sum[i][j-1] + f[i][j-1] + g[i-1][j];
    }
*/
    for(int i = 1; i <= n; i++){
        int now = 0;
        for(int j = 1; j <= m; j++){
            sum[i][j] = sum[i-1][j] + g[i-1][j] + now;
            if (a[i][j] == '.' && a[i][j+1] == '.')
                now++;
        }
    }
/*  for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout<<sum[i][j]<<' ';
            cout<<endl;
    }
    cout<<endl;
            
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout<<f[i][j]<<' ';
            cout<<endl;
    }
    cout<<endl;
    
            
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout<<g[i][j]<<' ';
            cout<<endl;
    }
    cout<<endl;
    */
            
    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] - g[x1-1][y2] + g[x1-1][y1-1] - f[x2][y1-1] + f[x1-1][y1-1]);
    }
    return 0;
}