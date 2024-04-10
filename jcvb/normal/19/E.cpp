#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct edge{
       int u,v;
}E[100005];
struct edge2{
       int v,next;
}e[200005];int etot=0;
int g[100005];
void ae(int u,int v){
     e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
     e[etot].v=u;e[etot].next=g[v];g[v]=etot++;
}
int f[200005];
int ff[100005];
inline int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
inline int gff(int x){return x==ff[x]?x:ff[x]=gff(ff[x]);}
int n,m;

int vis[100005]={0},pre[100005]={0},mar[100005];
int bo[100005]={0};
int cyc[100005];int len=0;
int Ma;
void dfs(int u){
     vis[u]=1;
     for (int i=g[u];~i;i=e[i].next){
         if(i>=Ma)continue;
         int v=e[i].v;
         if(!vis[v]){
                     pre[v]=u;
                     mar[v]=i/2+1;
                     dfs(v);
         }
     }
}
int check(int j){
    for (int i=1;i<=2*n;i++)f[i]=i;
    for (int i=1;i<=m;i++)if(i!=j){
        int u=E[i].u,v=E[i].v;
        f[gf(u)]=gf(v+n);
        f[gf(v)]=gf(u+n);
        if(gf(u)==gf(u+n)){
                           Ma=(i-1)*2;
                           dfs(u);
                           while(v!=u){
                                       cyc[++len]=v;
                                       bo[mar[v]]=1;
                                       v=pre[v];
                           }
                           cyc[++len]=u;
                           mar[u]=i;
                           bo[i]=1;
                           return 0;
        }                           
    }
    return 1;
}
int check2(){
     for (int i=1;i<=2*n;i++)f[i]=i;
     for (int i=1;i<=n;i++)ff[i]=i;
     for (int i=1;i<=m;i++)if(!bo[i]){
        int u=E[i].u,v=E[i].v;
        f[gf(u)]=gf(v+n);
        f[gf(v)]=gf(u+n);         
        ff[gff(u)]=gff(v);          
    }
    for (int i=1;i<=n;i++)if(gf(i)==gf(i+n))return 0;
    return 1;
}
int fid[100005];
int ord[100005];
int cmp(int i,int j){
    return fid[i]<fid[j];
}
int first[100005]={0};
struct seg{
       int l,r;
}mnot[100005];int na=0;
int cmpseg(const seg&a,const seg &b){
    if(a.l==b.l)return a.r<b.r;
    else return a.l<b.l;
}
int ans[100005];int anstot=0;
int main()
{
    memset(g,-1,sizeof(g));
    //freopen("fairy.in","r",stdin);
  //  freopen("fairy.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&E[i].u,&E[i].v);
        ae(E[i].u,E[i].v);
    }
    if(check(0)){
                 printf("%d\n",m);
                 for (int i=1;i<=m;i++)printf("%d ",i);
                 printf("\n");
                 return 0;
    }
    if(!check2()){
                  printf("0\n\n");
                  return 0;
    }
    cyc[0]=cyc[len];cyc[len+1]=cyc[1];
    for (int i=0;i<=len+1;i++)fid[i]=gff(cyc[i]);
    for (int i=1;i<=len;i++)ord[i]=i;
    sort(ord+1,ord+1+len,cmp);
    for (int i=1;i<=len;i++)if(first[fid[ord[i]]]==0)first[fid[ord[i]]]=i; first[n+1]=len+1;
    for (int i=n;i>=1;i--)if(first[i]==0)first[i]=first[i+1];
    
    for (int i=1;i<=n;i++){
        if(first[i+1]-first[i]<2)continue;
        int u=cyc[ord[first[i]]];
        for (int j=first[i]+1;j<first[i+1];j++){
            int v=cyc[ord[j]];
            if((gf(u)==gf(v)) ^ ((ord[j]-ord[first[i]])%2==0)){
                             mnot[na++]=(seg){0,min(ord[j],ord[first[i]])-1};
                             if(mnot[na-1].l>mnot[na-1].r)na--;
                             mnot[na++]=(seg){max(ord[j],ord[first[i]]),len-1};
                             if(mnot[na-1].l>mnot[na-1].r)na--;
            }else{
                  mnot[na++]=(seg){min(ord[j],ord[first[i]]),max(ord[j],ord[first[i]])-1};
                  if(mnot[na-1].l>mnot[na-1].r)na--;
            }
        }
    }
    int far=-1;
    sort(mnot,mnot+na,cmpseg);
    mnot[na++]=(seg){len,len};
    for (int i=0;i<na;i++){
        if(mnot[i].l<=far+1) far=max(far,mnot[i].r);
        else{
             for (int j=far+1;j<mnot[i].l;j++)
                 ans[anstot++]=mar[cyc[j]];
              far=max(far,mnot[i].r);
        }
    }
    sort(ans,ans+anstot);                 
    printf("%d\n",anstot);
    for (int i=0;i<anstot;i++)printf("%d ",ans[i]);
    printf("\n");
    return 0;
}