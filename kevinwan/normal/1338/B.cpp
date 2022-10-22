#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=1e5+10;
vector<int>g[mn];
int nu[mn],dep[mn];
void dfs(int x,int p){
    for(int y:g[x])if(y!=p){
        dep[y]=dep[x]+1;
        if(g[y].size()==1)nu[x]++;
        dfs(y,x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(g[i].size()>=2){
        dfs(i,0);
        break;
    }
    int ansa=1,st=-1,ansb=n-1;
    for(int i=1;i<=n;i++)if(g[i].size()==1){
        if(st==-1)st=dep[i]%2;
        else if(st!=dep[i]%2)ansa=3;
    }
    for(int i=1;i<=n;i++)if(nu[i]>1)ansb-=nu[i]-1;
    printf("%d %d",ansa,ansb);
}