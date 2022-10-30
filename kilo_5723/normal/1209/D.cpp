#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int fa[maxn];
int ff(int u){
    if (fa[u]==u) return u;
    return fa[u]=ff(fa[u]);
}
bool conn(int u,int v){
    u=ff(u); v=ff(v);
    if (u==v) return true;
    fa[ff(u)]=fa[ff(v)];
    return false;
}
int main(){
    int i,n,m;
    int u,v;
    int ans;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) fa[i]=i;
    ans=0;
    for (i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        ans+=conn(u,v);
    }
    printf("%d\n",ans);
    return 0;
}