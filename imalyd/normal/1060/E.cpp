//Problem E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n,sz[N],d[N];
ll c[2],s;
vector<int>e[N];
void dfs(int v,int fa){
    sz[v]=1;
    for(int i=0;i<(int)e[v].size();i++){
        int u=e[v][i];
        if(u!=fa)d[u]=d[v]^1,dfs(u,v),sz[v]+=sz[u];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b),e[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)s+=(ll)sz[i]*(n-sz[i]),++c[d[i]];
    cout<<((s+c[0]*c[1])>>1);
    return 0;
}