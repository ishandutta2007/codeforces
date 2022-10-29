#include<iostream>
#include<cmath> 
#include<cstdio>
#include<cstring> 
#include<algorithm>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)
#define INF 0x3f3f3f3f

using namespace std;

int i,j,k,x,y,n,m,ans,o;
int a[2002][2002];

int main(){
    cin>>n>>m>>k;
    rep(i,0,n+1)
    rep(j,0,m+1)
        a[i][j]=0;
    ans=0;
    rep(o,1,k){
        scanf("%d %d",&x,&y);
        a[x][y]=1;
        if (a[x-1][y]&&a[x-1][y-1]&&a[x][y-1]){
            ans=o;
            break;
        }
        if (a[x-1][y]&&a[x-1][y+1]&&a[x][y+1]){
            ans=o;
            break;
        }
        if (a[x+1][y]&&a[x+1][y-1]&&a[x][y-1]){
            ans=o;
            break;
        }
        if (a[x+1][y]&&a[x+1][y+1]&&a[x][y+1]){
            ans=o;
            break;
        }
    } 
    cout<<ans<<endl;
    return 0;
}