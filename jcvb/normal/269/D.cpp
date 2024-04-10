#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
int n,t;
struct node{int h,l,r;}a[100005];
struct po{
    int x,i,d;
}p[200005];
int cmp(const po&a,const po&b){
    if(a.x==b.x)return a.d<b.d;
    return a.x<b.x;
}
set<pair<int,int> >se;
set<pair<int,int> >graf;
struct edge{
    int v,next,w;
}e[400005];int etot=0;int g[100005];
int nu[400005];
void ae(int u,int v){
    int w=min(a[v].r,a[u].r)-max(a[u].l,a[v].l);
    nu[etot]=w;
    e[etot].v=v;e[etot].next=g[u];e[etot].w=w;g[u]=etot++;
}
int vis[100005];
int qu[100005];
int check(int w){
    static int tmp=0;
    tmp++;
    int p=0,q=0;
    qu[q++]=n+1;vis[n+1]=tmp;
    while(p!=q){
        int u=qu[p++];
        for (int i=g[u];~i;i=e[i].next)if(e[i].w>=w && vis[e[i].v]!=tmp){
            if((qu[q++]=e[i].v)==n+2)return 1;
            vis[e[i].v]=tmp;
        }
    }
    return 0;
}
int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d%d",&n,&t);
    a[n+1]=(node){t,-1000000000,1000000000};
    a[n+2]=(node){0,-1000000000,1000000000};
    for (int i=1;i<=n;i++)scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].r);
    for (int i=1;i<=n+2;i++)p[i*2-1]=(po){a[i].l,i,1},p[i*2]=(po){a[i].r,i,-1};
    sort(p+1,p+2*n+5,cmp);
    for (int i=1;i<=2*n+4;i++)
        if(p[i].d==1){
            set<pair<int,int> >::iterator it,it1,it2;
            int bo=1;
            it=se.insert(make_pair(a[p[i].i].h,p[i].i)).first;
            if(it!=se.begin()){
                it1=it;it1--;
                graf.insert(make_pair(p[i].i,it1->second));
            }else bo=0;
            if((it2=it,++it2)!=se.end()){
                graf.insert(make_pair(it2->second,p[i].i));
            }else bo=0;
            if(bo) graf.erase(make_pair(it2->second,it1->second));
        }else{
            se.erase(make_pair(a[p[i].i].h,p[i].i));
        }

    for (set<pair<int,int> >::iterator it=graf.begin();it!=graf.end();it++)ae(it->first,it->second);
    sort(nu,nu+etot);
    int l=0,r=etot-1,mid;
    while(l<=r){
        mid=l+r>>1;
        if(check(nu[mid]))l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",nu[r]);
    return 0;
}