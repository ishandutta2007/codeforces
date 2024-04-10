#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
int p[mn],s[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
void u(int a,int b){
    a=f(a),b=f(b);
    if(a==b)return;
    if(s[a]<s[b])swap(a,b);
    p[b]=a;
    s[a]+=s[b];
}
vector<int> g[mn];
bool cyc[mn],vis[mn],tv[mn];
void dfs(int x){
    vis[x]=tv[x]=1;
    for(int y:g[x]){
        if(!vis[y])dfs(y);
        else if(tv[y])cyc[f(x)]=1;
    }
    tv[x]=0;
}
int main()
{
    int n,m,a,b,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)p[i]=i,s[i]=1;
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        u(a,b);
    }
    for(i=1;i<=n;i++)if(!vis[i])dfs(i);
    int ans=n;
    for(i=1;i<=n;i++)if(p[i]==i&&!cyc[i])ans--;
    printf("%d",ans);
}