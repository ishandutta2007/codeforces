#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,n,m,flag,vis[60][60],tot;
char a[60][60],ch;

void dfs(int fa, int x, int y){
    vis[x][y]=tot;
    if (fa!=1){
        if (a[x-1][y]==a[x][y]){
            if (vis[x-1][y]){
                flag=1;
                return;
            }
            else
                dfs(2,x-1,y);
        }
    }
    if (fa!=2){
        if (a[x+1][y]==a[x][y]){
            if (vis[x+1][y]){
                flag=1;
                return;
            }
            else
                dfs(1,x+1,y);
        }
    }
    if (fa!=3){
        if (a[x][y-1]==a[x][y]){
            if (vis[x][y-1]){
                flag=1;
                return;
            }
            else
                dfs(4,x,y-1);
        }
    }
    if (fa!=4){
        if (a[x][y+1]==a[x][y]){
            if (vis[x][y+1]){
                flag=1;
                return;
            }
            else
                dfs(3,x,y+1);
        }
    }
    
}

int main(){
    cin>>n>>m;  
    rep(i,0,n+1)
    rep(j,0,m+1)
        a[i][j]='#';
    rep(i,1,n)
    rep(j,1,m){
        scanf("%c",&ch);
        while ((ch<'A')||(ch>'Z'))
            scanf("%c",&ch);
        a[i][j]=ch;
    }
    rep(i,1,n)
    rep(j,1,m)
        vis[i][j]=0;
    flag=0;
    tot=0;
    rep(i,1,n)
    rep(j,1,m)
        if (not vis[i][j]){
            tot++;
            dfs(0,i,j);
            if (flag)
                break;
        }
    if (flag)   
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}