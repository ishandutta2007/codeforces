#include<bits/stdc++.h>
using namespace std;
int n,a[210000],u[210000],v[210000];
int cnt,bel[210000],rt,dis;
vector<int> vec[210000];
void dfs(int u,int f){
    bel[u]=cnt;
    for (int v:vec[u]){
        if (v==f||a[v]!=a[u]) continue;
        dfs(v,u);
    }
}
void dfs(int u,int f,int d){
    if (d>dis) dis=d,rt=u;
    for (int v:vec[u]){
        if (v==f) continue;
        dfs(v,u,d+1);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<n;i++){
        scanf("%d%d",&u[i],&v[i]);
        vec[u[i]].push_back(v[i]);
        vec[v[i]].push_back(u[i]);
    }

    for (int i=1;i<=n;i++)
        if (!bel[i]){
            cnt++;
            dfs(i,0);
        }
    for (int i=1;i<=n;i++) vec[i].clear();

    for (int i=1;i<n;i++){
        u[i]=bel[u[i]]; v[i]=bel[v[i]];
        if (u[i]!=v[i]){
            vec[u[i]].push_back(v[i]);
            vec[v[i]].push_back(u[i]);
        }
    }
    dis=-1; dfs(1,0,0);
    dis=-1; dfs(rt,0,0);
    printf("%d\n",(dis+1)>>1);
    return 0;
}