#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int mn=1e6+10;
const ll mod=998244353;
vector<int>g[mn];
bool vis[mn],ins[mn];
int o[mn],scc[mn],l[mn],sct,ct,gud[mn];
stack<int>s;
void dfs(int x){
    vis[x]=ins[x]=1;
    s.push(x);
    o[x]=l[x]=ct++;
    for(int y:g[x]){
        if(!vis[y])dfs(y),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(l[x]==o[x]){
        while(s.top()!=x)ins[s.top()]=0,scc[s.top()]=sct,s.pop();
        ins[x]=0,scc[x]=sct++,s.pop();
    }
}
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        sct=ct=0;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)g[i].clear(),vis[i]=ins[i]=o[i]=scc[i]=l[i]=0;
        while(s.size())s.pop();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
        }
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
        if(sct==1){
            printf("No\n");
            continue;
        }
        for(int i=0;i<sct;i++)gud[i]=1;
        for(int i=1;i<=n;i++)for(int j:g[i])if(scc[i]!=scc[j])gud[scc[i]]=0;
        int tar=-1;
        for(int i=0;i<sct;i++)if(gud[i])tar=i;
        vector<int>a,b;
        for(int i=1;i<=n;i++){
            if(scc[i]==tar)a.push_back(i);
            else b.push_back(i);
        }
        printf("Yes\n%d %d\n",a.size(),b.size());
        for(int x:a)printf("%d ",x);
        printf("\n");
        for(int x:b)printf("%d ",x);
        printf("\n");
    }
}