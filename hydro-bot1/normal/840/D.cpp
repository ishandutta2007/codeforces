// Hydro submission #61f4b96537cee20376bcc30d@1643428198505
#include<bits/stdc++.h>
#define mid (l+r>>1)
#define seg int &p,int l,int r
#define lid tr[p].l,l,mid
#define rid tr[p].r,mid+1,r
const int N=3e5+5;
int rt[N],cnt,n,m,a[N];
struct segtree{int s,l,r;}tr[N<<5];
using namespace std;
void build(seg){
    p=++cnt;
    if(l==r)return;
    build(lid),build(rid);
}
void add(int q,seg,int x){
    p=++cnt;
    tr[p]=tr[q];
    if(l==r){
        tr[p].s++;
        return;
    }
    if(x<=mid)add(tr[q].l,lid,x);
    if(x>mid)add(tr[q].r,rid,x);
    tr[p].s=tr[tr[p].l].s+tr[tr[p].r].s;
}
int ask(int p,int q,int l,int r,int t){
    if(l==r)return l;
    int x=tr[tr[q].l].s-tr[tr[p].l].s,y=tr[tr[q].r].s-tr[tr[p].r].s;
    if(x>=t){
        int ans=ask(tr[p].l,tr[q].l,l,mid,t);
        if(ans>0)return ans;
    }
    if(y>=t){
        int ans=ask(tr[p].r,tr[q].r,mid+1,r,t);
        if(ans>0)return ans;
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(rt[0],1,n);
    for(int i=1;i<=n;i++)add(rt[i-1],rt[i],1,n,a[i]);
    for(int i=1;i<=m;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        int t=(r-l+1)/k+1;
        printf("%d\n",ask(rt[l-1],rt[r],1,n,t));
    }
}