#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<vector>
#define mo 1000000007
using namespace std;
int n;
int pre[100005];
struct edge{
       int v,next;
}e[100005];int etot=0;
int g[100005];
void ae(int u,int v){
     e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int col[100005];
int su[100005]={0};
int f[100005][2]={0};

int tmp[100005],tmp2[100005];
int tmpl[100005],tmpr[100005];int deg;
void dp(int u){
     if(col[u])f[u][0]=0;
     else{
          int ans=1;
          for (int i=g[u];~i;i=e[i].next)ans=1ll*ans*(f[e[i].v][1]+f[e[i].v][0])%mo;
          f[u][0]=ans;
     }
     if(!su[u])f[u][1]=0;
     else{
          if(col[u]){
                     int ans=1;
                     for (int i=g[u];~i;i=e[i].next)ans=1ll*ans*(f[e[i].v][1]+f[e[i].v][0])%mo;
                     f[u][1]=ans;
          }else{
                deg=0;
                for (int i=g[u];~i;i=e[i].next){
                    ++deg;
                    tmp[deg]=(f[e[i].v][1]+f[e[i].v][0]);
                    tmp2[deg]=f[e[i].v][1];
                }
                tmpl[0]=tmpr[deg+1]=1;
                for (int i=1;i<=deg;i++)tmpl[i]=1ll*tmpl[i-1]*tmp[i]%mo;
                for (int i=deg;i>=1;i--)tmpr[i]=1ll*tmpr[i+1]*tmp[i]%mo;
                int ans=0;
                for (int i=1;i<=deg;i++)ans=(ans+1ll*tmpl[i-1]*tmp2[i]%mo*tmpr[i+1])%mo;
                f[u][1]=ans;
          }
     }
}
int main()
{
    scanf("%d",&n);
    memset(g,-1,sizeof(g));
    for (int i=2;i<=n;i++){
        int x;scanf("%d",&x);x++;
        pre[i]=x;
        ae(x,i);
    }
    for (int i=1;i<=n;i++)scanf("%d",&col[i]),su[i]=col[i];
    for (int i=n;i>=2;i--){
        su[pre[i]]+=su[i];
    }
    for (int i=n;i>=1;i--)dp(i);
    printf("%d\n",f[1][1]%mo);
    return 0;
}