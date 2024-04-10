#include<bits/stdc++.h>
using namespace std;
const int MAX_N=400001;
int n,L;
int tot;
int len[MAX_N];
double vel[MAX_N];
double s[MAX_N];
double mn[4*MAX_N];
double lazy[4*MAX_N];
int perm[MAX_N];
void pushDown(int p){
    mn[p<<1]+=lazy[p];
    lazy[p<<1]+=lazy[p];
    mn[p<<1|1]+=lazy[p];
    lazy[p<<1|1]+=lazy[p];
    lazy[p]=0.0;
}
void pushUp(int p){
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
void build(int p,int l,int r){
    if(r-l==1){
        mn[p]=s[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid,r);
    pushUp(p);
}
void rangeAdd(int p,int l,int r,int x,int y,double z){
    if(l>=y||r<=x){
        return;
    }
    if(l>=x&&r<=y){
        mn[p]+=z;
        lazy[p]+=z;
        return;
    }
    int mid=(l+r)>>1;
    pushDown(p);
    rangeAdd(p<<1,l,mid,x,y,z);
    rangeAdd(p<<1|1,mid,r,x,y,z);
    pushUp(p);
}
double rangeMin(int p,int l,int r,int x,int y){
    if(l>=y||r<=x){
        return 1e18;
    }
    if(l>=x&&r<=y){
        return mn[p];
    }
    int mid=(l+r)>>1;
    pushDown(p);
    return min(rangeMin(p<<1,l,mid,x,y),rangeMin(p<<1|1,mid,r,x,y));
}
int main(){
    scanf("%d%d",&n,&L);
    int last=0;
    for(int i=0;i<n;++i){
        int l,r;
        double v;
        scanf("%d%d%lf",&l,&r,&v);
        if(l!=last){
            len[tot]=l-last;
            vel[tot++]=0.0;
        }
        len[tot]=r-l;
        vel[tot++]=v;
        last=r;
    }
    if(last!=L){
        len[tot]=L-last;
        vel[tot++]=0.0;
    }
    s[0]=vel[0]==0.0?0.0:len[0]/vel[0];
    for(int i=1;i<tot;++i){
        s[i]=s[i-1]+(vel[i]==0.0?0.0:len[i]/vel[i]);
    }
    build(1,0,tot);
    for(int i=0;i<tot;++i){
        perm[i]=i;
    }
    sort(perm,perm+tot,[&](int i,int j){
        return vel[i]<vel[j];
    });
    double ans=0;
    for(int i=0;i<tot;++i){
        int x=perm[i];
        if(vel[x]==0.0){
            double mx=min(len[x]/2.0,rangeMin(1,0,tot,x,tot));
            rangeAdd(1,0,tot,x,tot,-mx);
            ans+=len[x]-mx;
        }else{
            double mx=min(len[x]/vel[x]+len[x]/(vel[x]+2.0),rangeMin(1,0,tot,x,tot));
            rangeAdd(1,0,tot,x,tot,-mx);
            ans+=len[x]/vel[x]-mx/(vel[x]+1);
        }
    }
    printf("%.10f\n",ans);
    return 0;
}