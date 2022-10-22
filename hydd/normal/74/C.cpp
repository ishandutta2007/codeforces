#include<bits/stdc++.h>
using namespace std;
int n,m,ans,fa[4100000];
int findset(int x){
    if (x!=fa[x]) fa[x]=findset(fa[x]);
    return fa[x];
}
int hs(int x,int y){
    if (x==1&&y<m) return y;
    if (y==m&&x<n) return x+(m-1);
    if (x==n&&y>1) return (m-1)+(n-1)+(y-1);
    return (m-1)+(n-1)+(m-1)+(x-1);
}
void Union(int x,int y){
    x=findset(x); y=findset(y);
    if (x==y) return;
    ans--; fa[y]=x;
}
int main(){
    scanf("%d%d",&n,&m); ans=n-1+n-1+m-1+m-1;
    for (int i=1;i<=n-1+n-1+m-1+m-1;i++) fa[i]=i;
    int v;
    for (int i=1;i<=n;i++){//(i,1)
        v=min(i-1,m-1); Union(hs(i,1),hs(i-v,1+v));
        v=min(n-i,m-1); Union(hs(i,1),hs(i+v,1+v));
    }
    for (int i=1;i<=m;i++){//(1,i)
        v=min(n-1,i-1); Union(hs(1,i),hs(1+v,i-v));
        v=min(n-1,m-i); Union(hs(1,i),hs(1+v,i+v));
    }
    for (int i=1;i<=n;i++){//(i,m)
        v=min(i-1,m-1); Union(hs(i,m),hs(i-v,m-v));
        v=min(n-i,m-1); Union(hs(i,m),hs(i+v,m-v));
    }
    for (int i=1;i<=m;i++){//(n,i)
        v=min(n-1,i-1); v=min(hs(n,i),hs(n-v,i-v));
        v=min(n-1,m-i); v=min(hs(n,i),hs(n-v,i+v));
    }
    printf("%d\n",ans);
    return 0;
}