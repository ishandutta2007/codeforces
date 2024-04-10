#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=2e5+9;
const int L=-1e9-1e8;
const int R=1e9+1e8;
int n,sz,rt;
int vis[M*30],ls[M*30],rs[M*30],lv[M*30],rv[M*30];
void pu(int num,int l,int r){
    lv[num]=ls[num]?lv[ls[num]]+vis[num]:l+vis[num];
    rv[num]=rs[num]?rv[rs[num]]+vis[num]:r+vis[num];
}
void update(int&num,int l,int r,int x,int y,int v){
    if(!num){
        num=++sz;
        lv[num]=l;
        rv[num]=r;
    }
    if(x<=l&&r<=y){
        vis[num]+=v;
        lv[num]+=v;
        rv[num]+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)update(ls[num],l,mid,x,y,v);
    if(y>mid)update(rs[num],mid+1,r,x,y,v);
    pu(num,l,r);
}
int query(int num,int l,int r,int x,int v){
    v+=vis[num];
    if(l==r)return v+l;
    int mid=(l+r)>>1;
    if(x<=mid)return query(ls[num],l,mid,x,v);
    else return query(rs[num],mid+1,r,x,v);
}
int queryl(int num,int l,int r,int x,int v){
    v+=vis[num];
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(v+(rs[num]?lv[rs[num]]:mid+1)<=x)return queryl(rs[num],mid+1,r,x,v);
    return queryl(ls[num],l,mid,x,v);
}
int queryr(int num,int l,int r,int x,int v){
    v+=vis[num];
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(v+(ls[num]?rv[ls[num]]:mid)>=x)return queryr(ls[num],l,mid,x,v);
    return queryr(rs[num],mid+1,r,x,v);
}
int ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int t,k;
        scanf("%d%d",&t,&k);
        int l=queryl(rt,L,R,t-1,0);
        int r=queryr(rt,L,R,t+1,0);
        update(rt,L,R,L,l,1);
        update(rt,L,R,r,R,-1);
        for(int j=1;j<=k;++j){
            int x;
            scanf("%d",&x);
            x=(x+ans)%int(1e9+1);
            printf("%d\n",ans=query(rt,L,R,x,0));
        }
    }
    return 0;
}
/*
1
50
3
1 2 3

*/