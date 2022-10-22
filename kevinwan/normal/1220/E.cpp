#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll w[mn],ww[mn];
int o[mn],l[mn],scc[mn],num[mn];
bool vis[mn],ins[mn];
int ct,sct;
stack<int>st;
vector<int>g[mn],gs[mn];
void dfs(int x,int p){
    o[x]=l[x]=ct++;
    ins[x]=vis[x]=1;
    st.push(x);
    for(int y:g[x]){
        if(y==p)continue;
        if(vis[y]){
            if(ins[y])l[x]=min(l[x],o[y]);
        }
        else{
            dfs(y,x);
            l[x]=min(l[x],l[y]);
        }
    }
    if(l[x]==o[x]){
        while(st.size()&&st.top()!=x)scc[st.top()]=sct,ins[st.top()]=0,st.pop();
        scc[x]=sct++,ins[x]=0,st.pop();
    }
}
ll ans,dep[mn];
bool gud[mn];
void dfs2(int x,int p){
    if(num[x]>1)gud[x]=1;
    for(int y:gs[x]){
        if(y==p)continue;
        dfs2(y,x);
        gud[x]|=gud[y];
    }
}
ll es;
void dfs3(int x,int p){
    if(gud[x])dep[x]=0,ans+=ww[x];
    es=max(es,dep[x]);
    for(int y:gs[x]){
        if(y==p)continue;
        dep[y]=dep[x]+ww[y];
        dfs3(y,x);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",w+i);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,0);
    }
    for(int i=1;i<=n;i++){
        ww[scc[i]]+=w[i];
        num[scc[i]]++;
        for(int j:g[i]){
            if(scc[i]!=scc[j])gs[scc[i]].push_back(scc[j]);
        }
    }
    for(int i=0;i<sct;i++)sort(gs[i].begin(),gs[i].end()),gs[i].erase(unique(gs[i].begin(),gs[i].end()),gs[i].end());
    int x;
    scanf("%d",&x);
    dep[scc[x]]=ww[scc[x]];
    dfs2(scc[x],-1);
    dfs3(scc[x],-1);
    printf("%lld",ans+es);
}