#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c=='-')sg=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sg;
}
const int mo=1000000007;
const int inf=1061109567;
//const ll inf=1000000000000000000ll;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789

int n,m;
int g[444][444];

int vis[444][444][2];
int qx[444*444*2],qy[444*444*2],qf[444*444*2];
int p=0,q=0;
void ad(int x,int y,int f,int d){
    if(~vis[x][y][f])return;
    vis[x][y][f]=d;
    qx[q]=x;
    qy[q]=y;
    qf[q++]=f;
}

int main()
{
    gn(n);
    gn(m);
    while(m--){
        int x,y;
        gn(x);gn(y);
        g[x][y]=g[y][x]=1;
    }
    for (int i=1;i<=n;i++)g[i][i]=-1;
    memset(vis,-1,sizeof(vis));
    ad(1,1,0,0);
    while(p!=q){
        int x=qx[p],y=qy[p],f=qf[p++];
        int cd=vis[x][y][f];
        if(f==0){
            if(x==n)ad(x,y,1,cd+1);
            for (int j=1;j<=n;j++)if(g[x][j]==0)ad(j,y,1,cd+1);
        }else{
            if(y==n)ad(x,y,0,cd+1);
            for (int j=1;j<=n;j++)if(g[y][j]==1 && (j==n || j!=x))ad(x,j,0,cd+1);
        }
    }
    if(vis[n][n][0]==-1)printf("-1\n");
    else printf("%d\n",vis[n][n][0]/2);
    return 0;
}