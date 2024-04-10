#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int sz=250;
int n,m;
struct ed{
    int u,v,c;
}E[100005];
struct que{
    int u,v;
}Q[100005];int q;
int ans[100005]={0};
int cmp(const ed &a,const ed&b){
    return a.c<b.c;
}
int est[100005]={0};
int fa[100005];
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
int vis[100005]={0};int tms=0;
int seq[100005]={0};

int has[8000000]={0};
inline int fh(int u,int v){
    return (1ll*u*100007+v)%7777777;
}
void hasins(int i){
    int hh=fh(Q[i].u,Q[i].v);
    for (;hh<8000000;hh++)if(!has[hh]){has[hh]=i;return;}
    for (hh=0;;hh++)if(!has[hh]){has[hh]=i;return;}
}
int hasfind(int u,int v){
    if(u>v)swap(u,v);
    int hh=fh(u,v);
    for (;hh<8000000;hh++){
        if(!has[hh])return 0;
        if(Q[has[hh]].u==u && Q[has[hh]].v==v)return has[hh];
    }
    for (hh=0;hh<8000000;hh++){
        if(!has[hh])return 0;
        if(Q[has[hh]].u==u && Q[has[hh]].v==v)return has[hh];
    }
    return 0;
}
int sam[100005];
void work(int l){
    tms++;
    int len=0;
    for (int i=l;i==l || !est[i];i++){
        if(vis[E[i].u]!=tms){vis[seq[++len]=E[i].u]=tms;}
        if(vis[E[i].v]!=tms){vis[seq[++len]=E[i].v]=tms;}
        fa[E[i].u]=E[i].u;
        fa[E[i].v]=E[i].v;
    }
    for (int i=l;i==l || !est[i];i++){
        vis[E[i].u]=vis[E[i].v]=tms;
        fa[gf(E[i].v)]=gf(E[i].u);
    }
    if(len>sz){
        for (int i=1;i<=q;i++)if(!sam[i] && vis[Q[i].u]==tms && vis[Q[i].v]==tms && gf(Q[i].u)==gf(Q[i].v))ans[i]++;
    }else{
        for (int i=1;i<=len;i++)
            for (int j=i+1;j<=len;j++)if(gf(seq[i])==gf(seq[j])){
                int id=hasfind(seq[i],seq[j]);
                if(id)ans[id]++;
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].c);
    sort(E+1,E+1+m,cmp);
    for (int i=1;i<=m+1;i++){
        if(i==1 || i==m+1 || E[i].c!=E[i-1].c)est[i]=1;
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        scanf("%d%d",&Q[i].u,&Q[i].v);
        if(Q[i].u>Q[i].v)swap(Q[i].u,Q[i].v);
        int tmp=0;
        if(tmp=hasfind(Q[i].u,Q[i].v)){
            sam[i]=tmp;
        }else hasins(i);
    }
    for (int i=1;i<=m;i++)if(est[i]){
        work(i);
    }
    for (int i=1;i<=q;i++){
        if(!sam[i])printf("%d\n",ans[i]);
        else printf("%d\n",ans[sam[i]]);
    }
    return 0;
}