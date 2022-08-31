#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
void gn(ll &x){
    int sg=1;char tmp;while(((tmp=getchar())<'0'||tmp>'9')&&tmp!='-');
    if(tmp=='-')sg=-1,x=0;else x=tmp-'0';
    while((tmp=getchar())>='0'&&tmp<='9')x=x*10+tmp-'0';
    x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


struct edge{
    int v,next;
}e[444444];int g[444444];int etot=0;
void ae(int u,int v){
    e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
struct para{
    int x,y;
}pa[444444],ed[444444];
int cmp1(const para&a,const para&b){
    return 1ll*a.x*b.y<1ll*b.x*a.y;
}
int ptot=0;
int n,m,k;
int deg[444444];
int fbd[444444];
int minu[444444];
int ans[444444];
int notok[444444];

void output(){
    int x=0;
    for (int i=1;i<=n;i++)x+=ans[i];
    printf("%d\n",x);
    for (int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
    printf("\n");
}
int qu[444444];

int curdeg[444444];
int check(int x,int y){
    if(x==0){
        for (int i=1;i<=n;i++)ans[i]=1;
        for (int i=1;i<=k;i++)ans[fbd[i]]=0;
        return 1;
    }
    for (int i=1;i<=n;i++){
        minu[i]=(1ll*x*deg[i]-1)/y+1;
        curdeg[i]=notok[i]=0;
    }
    for (int i=1;i<=m;i++)curdeg[ed[i].x]++,curdeg[ed[i].y]++;
    int p=0,q=0;
    for (int i=1;i<=k;i++)notok[fbd[i]]=1,qu[q++]=fbd[i];
    while(p!=q){
        int u=qu[p++];
        for (int i=g[u];~i;i=e[i].next){
            int v=e[i].v;
            if(notok[v])continue;
            curdeg[v]--;
            if(curdeg[v]<minu[v]){
                notok[v]=1;
                qu[q++]=v;
            }
        }
    }
    if(q==n)return 0;
    for (int i=1;i<=n;i++)ans[i]=!notok[i];
    return 1;
}
int main()
{
    
    memset(g,-1,sizeof(g));
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=k;i++)scanf("%d",&fbd[i]);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&ed[i].x,&ed[i].y);
        ae(ed[i].x,ed[i].y);
        ae(ed[i].y,ed[i].x);
        deg[ed[i].x]++;
        deg[ed[i].y]++;
    }
    for (int i=1;i<=n;i++)
        for (int j=0;j<=deg[i];j++)pa[++ptot]=(para){j,deg[i]};
    sort(pa+1,pa+1+ptot,cmp1);
    int l=1,r=ptot,mid;
    while(l<=r){
        mid=l+r>>1;
        if(check(pa[mid].x,pa[mid].y))l=mid+1;
        else r=mid-1;
    }
    check(pa[r].x,pa[r].y);
    output();
    return 0;
}