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
int n,q;
struct cao{
    int x,y;
    int d;//0 up 1 lef
    int id;
}a[222222];
int cmp(const cao&a,const cao&b){
    return a.x<b.x;
}
map<int,bool>ma;
int gm(int i,int j){
    return a[i].id<a[j].id?i:j;
}
int mi[666666];


void build(int l,int r,int x){
    if(l==r){
        mi[x]=l;//a[l].id;
    }else{
        int mid=l+r>>1;
        build(l,mid,x<<1);
        build(mid+1,r,x<<1|1);
        mi[x]=gm(mi[x<<1],mi[x<<1|1]);//min(mi[x<<1],mi[x<<1|1]);
    }
}
int l1,r1,v;
void que(int l,int r,int x){
    if(l1<=l && r<=r1)v=gm(v,mi[x]);
    else{
        int mid=l+r>>1;
        if(l1<=mid)que(l,mid,x<<1);
        if(r1>mid)que(mid+1,r,x<<1|1);
    }
}

int ans[222222];
int getmin(int l,int r){
    v=0,l1=l,r1=r;
    que(1,q,1);
    return v;
}
void work(int l,int r,int dl=0,int du=0){
    if(l>r)return;
    int x=getmin(l,r);

    if(ma[a[x].x]){
        work(l,x-1,dl,du);
        work(x+1,r,dl,du);
        return;
    }
    ma[a[x].x]=1;
    if(a[x].d==0){
        ans[a[x].id]=a[r+1].x-a[x].x+du;
        work(l,x-1,dl,ans[a[x].id]);
        work(x+1,r,0,du);
    }else{
        ans[a[x].id]=a[x].x-a[l-1].x+dl;
        work(l,x-1,dl,0);
        work(x+1,r,ans[a[x].id],du);
    }
}
        


int main()
{
    a[0].id=1000000000;
    scanf("%d%d",&n,&q);
    a[0].x=0,a[q+1].x=n+1;
    for (int i=1;i<=q;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        char c;while((c=getchar())<'A'||c>'Z');
        if(c=='U')a[i].d=0;
        else a[i].d=1;
        a[i].id=i;
    }
    sort(a+1,a+1+q,cmp);
    build(1,q,1);
    work(1,q);
    for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}