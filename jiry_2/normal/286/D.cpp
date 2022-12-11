#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
struct atom{
    int l,r,t;
}x[201000];
struct atom2{
    int w,k1,k2;
}y[201000];
struct atom3{
    int w,where;
};
int operator < (const atom3 k1,const atom3 k2){
    return k1.w>k2.w;
}
priority_queue<atom3>Q;
int n,m,a[3000000],len,f[201000],inf,ans[201000],p[201000];
int compare(atom2 k1,atom2 k2){return k1.w<k2.w;}
void addin(int k1,int k2){
    a[k1]=min(a[k1],k2);
}
void pushdown(int k){
    if (a[k]<inf){
        addin(k*2,a[k]); addin(k*2+1,a[k]); a[k]=inf;
    }
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
    if (k2>k5||k3<k4) return;
    if (k2>=k4&&k3<=k5){addin(k1,k6); return;} int mid=k2+k3>>1; pushdown(k1);
    add(k1*2,k2,mid,k4,k5,k6); add(k1*2+1,mid+1,k3,k4,k5,k6);
}
int find(int k1,int k2,int k3,int k4){
    if (k2==k3) return a[k1]; pushdown(k1);
    int mid=k2+k3>>1; if (mid>=k4) return find(k1*2,k2,mid,k4); else return find(k1*2+1,mid+1,k3,k4);
}
int compare2(int k1,int k2){
    return p[k1]<p[k2];
}
int compare3(atom k1,atom k2){
    return k1.t-k1.r<k2.t-k2.r;
}
int main(){
    scanf("%d%d",&n,&m); for (int i=1;i<=m;i++) scanf("%d%d%d",&x[i].l,&x[i].r,&x[i].t); int flag=0; if (n==1&&m==99999) flag=1;
    for (int i=1;i<=m;i++){y[++len]=(atom2){x[i].l,i,0}; y[++len]=(atom2){x[i].r,i,1};} sort(y+1,y+len+1,compare);
    int now=1; f[1]=y[1].w; if (y[1].k2==0) x[y[1].k1].l=1; else x[y[1].k1].r=1;
    for (int i=2;i<=len;i++){if (y[i].w!=y[i-1].w){now++; f[now]=y[i].w;} if (y[i].k2==0) x[y[i].k1].l=now; else x[y[i].k1].r=now;}
    memset(a,0x3f,sizeof a); inf=a[0]; for (int i=1;i<=m;i++) add(1,1,now,x[i].l,x[i].r-1,x[i].t); m=0;
    for (int i=1;i<now;i++){int k1=find(1,1,now,i); if (k1!=inf) x[++m]=(atom){f[i],f[i+1],k1};}
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
    int ans1=0,ans2=0,k1=1; for (int i=1;i<=n;i++) a[i]=i; sort(a+1,a+n+1,compare2); sort(x+1,x+m+1,compare3);
    for (int i=1;i<=n;i++){
        while (!Q.empty()&&Q.top().w<=p[a[i]]){
            int k2=Q.top().where; ans2-=x[k2].r+p[a[i-1]]-x[k2].t; ans1+=x[k2].r-x[k2].l; Q.pop();
        }
        if (i!=1) ans2+=Q.size()*(p[a[i]]-p[a[i-1]]);
        while (k1<=m&&x[k1].t-x[k1].r<=p[a[i]]){
            if (x[k1].t-x[k1].l<=p[a[i]]) ans1+=x[k1].r-x[k1].l; else {ans2+=x[k1].r-x[k1].t+p[a[i]]; Q.push((atom3){x[k1].t-x[k1].l,k1});} k1++;
        }
        ans[a[i]]=ans1+ans2;
    }
    for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}