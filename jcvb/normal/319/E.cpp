#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct query{int opt,a,b;}qu[100005];
int num[200005],tot=0;
int fa[200005],cur=0;
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
int lef[200005],rig[200005];
int olef[200005],orig[200005];
int off[200005]={0};
vector<int> seg[600000];

int l1,r1,I,v;
void cover(int l,int r,int x){
    if(l1<=l && r<=r1)seg[x].push_back(v);
    else{
        int mid=l+r>>1;
        if(l1<=mid)cover(l,mid,x<<1);
        if(r1>mid)cover(mid+1,r,x<<1|1);
    }
}int lis[200005],len;
void que(int l,int r,int x){
    while(!seg[x].empty()){
            int y=seg[x].back();seg[x].pop_back();
            if(!off[y]){
                off[y]=1;
                lis[++len]=y;
            }
    }
    if(l!=r){
        int mid=l+r>>1;
        if(I<=mid)que(l,mid,x<<1);
        else que(mid+1,r,x<<1|1);
    }
}
void add(int l,int r){
    int nl=l,nr=r,nv=++cur;fa[nv]=nv;
    olef[nv]=l;orig[nv]=r;
    len=0;
    I=l;que(1,tot,1);
    I=r;que(1,tot,1);   
    for (int i=1;i<=len;i++){
        nl=min(nl,lef[lis[i]]);
        nr=max(nr,rig[lis[i]]);
        fa[gf(lis[i])]=nv;
    }   
    lef[nv]=nl,rig[nv]=nr;
    l1=nl+1,r1=nr-1,v=nv;if(l1<=r1)cover(1,tot,1);
}
int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d%d",&qu[i].opt,&qu[i].a,&qu[i].b);
        if(qu[i].opt==1)num[++tot]=qu[i].a,num[++tot]=qu[i].b;
    }
    sort(num+1,num+1+tot);
    tot=unique(num+1,num+1+tot)-num-1;
    for (int i=1;i<=n;i++)if(qu[i].opt==1){
        qu[i].a=lower_bound(num+1,num+1+tot,qu[i].a)-num;
        qu[i].b=lower_bound(num+1,num+1+tot,qu[i].b)-num;
    }
    for(int i=1;i<=n;i++){
        if(qu[i].opt==1){
            add(qu[i].a,qu[i].b);
        }else{
            int x=qu[i].a,y=qu[i].b;
            x=gf(x);y=gf(y);
            if(x==y)printf("YES\n");
            else{
                if(orig[qu[i].a]<rig[y] && orig[qu[i].a]>lef[y] || olef[qu[i].a]<rig[y] && olef[qu[i].a]>lef[y])printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}