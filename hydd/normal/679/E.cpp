#include<bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
using namespace std;
typedef long long ll;
int n,q; ll pw[15]; int pos[410000];
ll taga[410000],tagv[410000],mn[410000];
inline int calc(ll x){ return lower_bound(pw,pw+12,x)-pw;}
void pushv(int now,ll v,int p){
    taga[now]=0; pos[now]=p;
    tagv[now]=mn[now]=v;
}
void pusha(int now,ll v){
    if (pos[now]){
        tagv[now]-=v;
        while (tagv[now]<0) tagv[now]+=pw[pos[now]+1]-pw[pos[now]],pos[now]++;
        mn[now]=tagv[now];
    } else mn[now]-=v,taga[now]+=v;
}
void pushdown(int now){
    if (tagv[now]){
        pushv(ls,tagv[now],pos[now]);
        pushv(rs,tagv[now],pos[now]);
        tagv[now]=pos[now]=0;
    }
    if (taga[now]){
        pusha(ls,taga[now]);
        pusha(rs,taga[now]);
        taga[now]=0;
    }
}
void changev(int now,int l,int r,int x,int y,ll v,int p){
    if (x<=l&&r<=y){
        pushv(now,v,p);
        return;
    }
    pushdown(now); int mid=(l+r)>>1;
    if (x<=mid) changev(ls,l,mid,x,y,v,p);
    if (y>mid) changev(rs,mid+1,r,x,y,v,p);
    mn[now]=min(mn[ls],mn[rs]);
}
void changea(int now,int l,int r,int x,int y,ll v){
    if (x<=l&&r<=y&&(mn[now]>=v||pos[now])){
        pusha(now,v);
        return;
    }
    pushdown(now); int mid=(l+r)>>1;
    if (x<=mid) changea(ls,l,mid,x,y,v);
    if (y>mid) changea(rs,mid+1,r,x,y,v);
    mn[now]=min(mn[ls],mn[rs]);
}
ll query(int now,int l,int r,int x){
    if (l==r) return pw[pos[now]]-mn[now];
    pushdown(now); int mid=(l+r)>>1;
    if (x<=mid) return query(ls,l,mid,x);
    else return query(rs,mid+1,r,x);
}
int main(){
    pw[0]=1; for (int i=1;i<=11;i++) pw[i]=pw[i-1]*42;
    cin>>n>>q; int x;
    for (int i=1;i<=n;i++){
        cin>>x; int t=calc(x);
        changev(1,1,n,i,i,pw[t]-x,t);
    }
    int op,l,r;
    while (q--){
        cin>>op;
        if (op==1){
            cin>>x;
            cout<<query(1,1,n,x)<<'\n';
        } else
            if (op==2){
                cin>>l>>r>>x; int t=calc(x);
                changev(1,1,n,l,r,pw[t]-x,t);
            } else{
                cin>>l>>r>>x;
                do{ changea(1,1,n,l,r,x);} while (!mn[1]);
            }
    }
    return 0;
}