#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int n, k;
char a[3][10000];
int vis[3][10000];
queue<PII> Q;

int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%d%d", &n, &k);
        for(int i = 0; i < 3; i++){
            scanf("%s", a[i]);
            a[i][n] = a[i][n+1] = a[i][n+2] = a[i][n+3] = '.';
        }
        for(int i = 0; i < 3; i++)
            for(int j = 0; j <= n + 3; j++)
                vis[i][j] = 0;
        while(!Q.empty())
            Q.pop();
        for(int i = 0; i < 3; i++)
            if (a[i][0] == 's')
                Q.push(PII(i, 0));
        int flag = 0;
        while (!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
        //  cout<<x<<' '<<y<<endl;
            if (y >= n){
                flag = 1;
                break;
            }
            Q.pop();
            if (a[x][y+1]=='.' && a[x][y+1]=='.' && a[x][y+2]=='.' && a[x][y+3]=='.')
                if (!vis[x][y+3]){
                    Q.push(PII(x, y+3));
                    vis[x][y+3] = 1;
                }
            if (x < 2 && a[x][y+1]=='.' && a[x+1][y+1]=='.' && a[x+1][y+2]=='.' && a[x+1][y+3]=='.')
                if (!vis[x+1][y+3]){
                    Q.push(PII(x+1, y+3));
                    vis[x+1][y+3] = 1;
                }
            if (x > 0 && a[x][y+1]=='.' && a[x-1][y+1]=='.' && a[x-1][y+2]=='.' && a[x-1][y+3]=='.')
                if (!vis[x-1][y+3]){
                    Q.push(PII(x-1, y+3));
                    vis[x-1][y+3] = 1;
                }
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}