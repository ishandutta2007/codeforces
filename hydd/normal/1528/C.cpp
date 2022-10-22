#include<bits/stdc++.h>
using namespace std;
int T,n,a[310000],b[310000];
int cnt,L[310000],R[310000];
int ans,sum,tree[610000];
vector<int> vec[310000];
void add(int x,int y){
    for (;x<=cnt;x+=x&-x) tree[x]^=y;
}
int query(int x){
    int res=0;
    for (;x;x-=x&-x) res^=tree[x];
    return res;
}
void dfs1(int u,int f){
    L[u]=++cnt;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs1(v,u);
    }
    R[u]=cnt;
}
void dfs2(int u,int f){
    int v=query(L[u]);
    if (v) add(L[v],v),add(R[v]+1,v),sum--;
    add(L[u],u); add(R[u]+1,u); sum++;
    ans=max(ans,sum);
    for (int v:vec[u]){
        if (v==f) continue;
        dfs2(v,u);
    }
    add(L[u],u); add(R[u]+1,u); sum--;
    if (v) add(L[v],v),add(R[v]+1,v),sum++;
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=2;i<=n;i++) scanf("%d",&a[i]);
        for (int i=2;i<=n;i++) scanf("%d",&b[i]);
        for (int i=2;i<=n;i++) vec[b[i]].push_back(i);
        cnt=0; dfs1(1,0);
        for (int i=1;i<=n;i++) vec[i].clear();
        for (int i=2;i<=n;i++) vec[a[i]].push_back(i);
        ans=0; dfs2(1,0);
        for (int i=1;i<=n;i++) vec[i].clear();
        printf("%d\n",ans);
    }
    return 0;
}