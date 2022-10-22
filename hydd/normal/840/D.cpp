#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,rt[310000];
int treesize,tree[8100000],ls[8100000],rs[8100000];
void change(int &now,int last,int l,int r,int x){
    now=++treesize;
    tree[now]=tree[last]; ls[now]=ls[last]; rs[now]=rs[last];
    if (l==r){ tree[now]++; return;}
    int mid=(l+r)>>1;
    if (x<=mid) change(ls[now],ls[last],l,mid,x);
    else change(rs[now],rs[last],mid+1,r,x);
    tree[now]=tree[ls[now]]+tree[rs[now]];
}
int query(int u,int v,int l,int r,int k){
    if (tree[u]-tree[v]<=k) return n+1;
    if (l==r) return l;
    int mid=(l+r)>>1;
    return min(query(ls[u],ls[v],l,mid,k),query(rs[u],rs[v],mid+1,r,k));
}
int main(){
    scanf("%d%d",&n,&q);
    int x;
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        change(rt[i],rt[i-1],1,n,x);
    }
    int l,r,k,ans;
    for (int i=1;i<=q;i++){
        scanf("%d%d%d",&l,&r,&k);
        k=(r-l+1)/k; ans=query(rt[r],rt[l-1],1,n,k);
        if (ans!=n+1) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}