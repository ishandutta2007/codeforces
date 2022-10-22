#include <bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
vector<int> v;
bool vis[mn];
vector<int> g[mn];
void dfs(int x){
    vis[x]=1;
    v.push_back(x);
    for(int y:g[x]){
        if(!vis[y]){
            dfs(y);
            v.push_back(x);
        }
    }
}
int main()
{
    int n,m,k,i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int num=(2*n+k-2)/k;
    while(v.size()<num*k)v.push_back(g[v[v.size()-1]][0]);
    for(i=0;i<k;i++){
        printf("%d ",num);
        for(int j=i*num;j<i*num+num;j++)printf("%d ",v[j]);
        printf("\n");
    }
}