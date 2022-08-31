#include<cstdio>
#include<algorithm>
#include<cassert>
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
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;

char a[1005][1005];
int n,m;

int d[4][1005][1005];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int qlen=1005*1005;
int qux[1005*1005],quy[1005*1005];
int vis[1005][1005];
#define inf 500000000

int ok(int i,int j){
    return i>=1 && i<=n && j>=1 && j<=m && a[i][j]!='#';
}
void bfs(int id){
    int p=0,q=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            vis[i][j]=0;
            d[id][i][j]=inf;
            if(a[i][j]=='0'+id){
                d[id][i][j]=0;
                vis[i][j]=1;
                qux[q]=i;
                quy[q++]=j;
            }
        }
    while(p!=q){
        int ux=qux[p],uy=quy[p++];if(p==qlen)p=0;
        for (int k=0;k<4;k++){
            int vx=ux+dx[k],vy=uy+dy[k];
            if(vis[vx][vy] || !ok(vx,vy))continue;
            if(a[vx][vy]=='.'){
                d[id][vx][vy]=d[id][ux][uy]+1;
                vis[vx][vy]=1;
                qux[q]=vx,quy[q++]=vy;
                if(q==qlen)q=0;
            }else{
                d[id][vx][vy]=d[id][ux][uy];
                vis[vx][vy]=1;
                p--;if(p==-1)p=qlen-1;
                qux[p]=vx,quy[p]=vy;
            }
        }
    }
}
int dd[4][4];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%s",a[i]+1);
    for (int id=1;id<=3;id++)bfs(id);

    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)dd[i][j]=inf;
    for (int id=1;id<=3;id++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)if(a[i][j]==id+'0'){
                dd[id][1]=min(dd[id][1],d[1][i][j]);
                dd[id][2]=min(dd[id][2],d[2][i][j]);
                dd[id][3]=min(dd[id][3],d[3][i][j]);
            }
    int ans=inf;
    ans=min(ans,dd[1][2]+dd[2][3]);
    ans=min(ans,dd[1][2]+dd[1][3]);
    ans=min(ans,dd[3][2]+dd[1][3]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)if(a[i][j]=='.'){
            ans=min(ans,d[1][i][j]+d[2][i][j]+d[3][i][j]-2);
        }
    if(ans==inf)printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}