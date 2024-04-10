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
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789
using namespace std;
int n;
db a[1111][1111];
db f[1111];
int vis[1111];
#define inf 100000000000000000.0

db down[1111],up[1111];
int main()
{
    gn(n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            int x;
            gn(x);
            a[i][j]=x*0.01;
        }
    vis[n]=0;
    for (int i=0;i<=n;i++)f[i]=inf,down[i]=up[i]=1.0;
    f[n]=0.0;

    for (int ii=1;ii<=n;ii++){
        int u=0;
        for (int i=1;i<=n;i++)if(!vis[i] && f[i]<f[u]){
            u=i;
        }
        vis[u]=1;
        for (int i=1;i<=n;i++)if(!vis[i]){
            up[i]+=down[i]*a[i][u]*f[u];
            down[i]*=(1.0-a[i][u]);
            if(fabs(down[i]-1.0)>1e-9){
                f[i]=min(f[i],up[i]/(1.0-down[i]));
            }
        }
    }
    printf("%.10lf\n",f[1]);
    return 0;
}