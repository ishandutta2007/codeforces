#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=0){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
int n,k;
int a[2009][2009];
int X[2009*2009],Y[2009*2009];
int b[4][2];
bool vis[2009][2009];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
            X[a[i][j]]=i;
            Y[a[i][j]]=j;
        }
    }
    for(int i=n*n;i>=1;--i){
        int x=X[i],y=Y[i],ma=0;
        for(int j=0;j<4;++j){
            if(b[j][0]){
                ma=max(ma,abs(b[j][0]-x)+abs(b[j][1]-y));
            }
        }
        if(ma<=k){
            vis[x][y]=1;
            if(!b[0][0]||b[0][0]-b[0][1]<x-y)b[0][0]=x,b[0][1]=y;
            if(!b[1][0]||b[1][0]-b[1][1]>x-y)b[1][0]=x,b[1][1]=y;
            if(!b[2][0]||b[2][0]+b[2][1]<x+y)b[2][0]=x,b[2][1]=y;
            if(!b[3][0]||b[3][0]+b[3][1]>x+y)b[3][0]=x,b[3][1]=y;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            putchar(vis[i][j]?'M':'G');
        }
        puts("");
    }
    return 0;
}