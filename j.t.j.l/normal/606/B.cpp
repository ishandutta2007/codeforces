#include<bits/stdc++.h>

using namespace std;

const int N = 1000;
const int L = 1e5 + 10;

int a[N][N];
int ans[L];
char s[L];

int main(){
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            a[i][j] = -1;
    a[x][y] = 0;
    scanf("%s", s+1);
    int l = strlen(s + 1);
    for(int i = 1; i <= l; i++){
        char ch = s[i]; /*getchar();
        while(ch != 'U' && ch != 'L' && ch != 'R' && ch != 'D')
            ch = getchar();*/
        switch (ch){
            case 'U':
                if (x > 1)
                    x--;
                if (a[x][y] == -1)
                    a[x][y] = i;
                break;
            case 'D':
                if (x < n)
                    x++;
                if (a[x][y] == -1)
                    a[x][y] = i;
                break;
            case 'L':
                if (y > 1)
                    y--;
                if (a[x][y] == -1)
                    a[x][y] = i;
                break;
            case 'R':
                if (y < m)
                    y++;
                if (a[x][y] == -1)
                    a[x][y] = i;
                break;
        }
        
    /*  for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                cout<<a[i][j]<<' ';
            cout<<endl; 
        }*/
        
    }
    for(int i = 0; i <= l; i++)
        ans[i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if (a[i][j] == -1)
                ans[l]++;
            else
                ans[a[i][j]]++;
    for(int i = 0; i <= l; i++)
        printf("%d%c", ans[i], " \n"[i==l]);
    return 0;
}