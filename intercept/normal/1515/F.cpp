#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=3e5+9;
int n,m,c;
int a[M],f[M],t[M<<1];
ll val[M];
vector<pii>g[M];
vector<int>ans;
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int u,int v){
    u=find(u),v=find(v);
    f[v]=u;
    val[u]+=val[v]-c;
    if(g[u].size()<g[v].size())swap(g[u],g[v]);
    for(auto o:g[v]){
        g[u].eb(o);
    }
    g[v].clear();
}
void push(int x,int y){
    for(t[x+=n-1]=y;x;x>>=1)t[x>>1]=val[t[x]]>val[t[x^1]]?t[x]:t[x^1];
}
int main(){
    ll sum=0;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),f[i]=i,val[i]=a[i],sum+=a[i];
    if(sum-1ll*(n-1)*c<0){
        puts("NO");
        return 0;
    }
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].eb(v,i);
        g[v].eb(u,i);
    }
    for(int i=1;i<=n;++i)push(i,i);
    val[0]=-1;
    while(1){
        int u=t[1];
        if(u==0)break;
        if(g[u].size()==0){
            push(u,0);
            continue;
        }
        auto o=g[u].back();
        g[u].pop_back();
        int v=o.fi;
        if(find(u)==find(v))continue;
        merge(u,v);
        push(u,u);
        ans.eb(o.se);
    }
    puts("YES");
    for(auto o:ans)printf("%d\n",o);
    return 0;
}