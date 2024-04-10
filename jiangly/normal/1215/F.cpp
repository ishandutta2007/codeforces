#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=1e18;
const int MAX_N=400000;
const int MAX_V=2*MAX_N;
vector<int> g[2*MAX_V];
int low[2*MAX_V],dfn[2*MAX_V];
int L[MAX_N],R[MAX_N];
int s[MAX_N];
int tot;
int cnt;
int belong[2*MAX_V];
vector<int> stk;
void tarjan(int u){
    stk.push_back(u);
    dfn[u]=tot++;
    low[u]=dfn[u];
    for(int v:g[u]){
        if(dfn[v]==-1){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(belong[v]==-1){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        belong[u]=cnt;
        while(stk.back()!=u){
            belong[stk.back()]=cnt;
            stk.pop_back();
        }
        stk.pop_back();
        ++cnt;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dfn,-1,sizeof(dfn));
    memset(low,-1,sizeof(low));
    memset(belong,-1,sizeof(belong));
    int n,p,M,m;
    cin>>n>>p>>M>>m;
    for(int i=0;i<n;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        g[u].push_back(v+MAX_V);
        g[v].push_back(u+MAX_V);
    }
    for(int i=0;i<p;++i){
        cin>>L[i]>>R[i];
        s[i]=i;
    }
    sort(s,s+p,[&](int a,int b){
        return L[a]<L[b];
    });
    for(int i=0;i<p;++i){
        g[i+MAX_N].push_back(s[i]);
        g[s[i]+MAX_V].push_back(i+MAX_N+MAX_V);
        if(i<p-1){
            g[i+MAX_N].push_back(i+1+MAX_N);
            g[i+1+MAX_N+MAX_V].push_back(i+MAX_N+MAX_V);
        }
    }
    for(int i=0;i<p;++i){
        s[i]=L[s[i]];
    }
    for(int i=0;i<p;++i){
        int x=upper_bound(s,s+p,R[i])-s;
        if(x!=p){
            g[i+MAX_V].push_back(x+MAX_N);
            g[x+MAX_N+MAX_V].push_back(i);
        }
    }
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        g[u+MAX_V].push_back(v);
        g[v+MAX_V].push_back(u);
    }
    for(int i=0;i<2*MAX_V;++i){
        if(dfn[i]==-1){
            tarjan(i);
        }
    }
    for(int i=0;i<p;++i){
        if(belong[i]==belong[i+MAX_V]){
            cout<<-1<<endl;
            return 0;
        }
    }
    int f=0,k=0;
    for(int i=0;i<p;++i){
        if(belong[i]>belong[i+MAX_V]){
            f=max(f,L[i]);
            ++k;
        }
    }
    cout<<k<<' '<<f<<endl;
    for(int i=0;i<p;++i){
        if(belong[i]>belong[i+MAX_V]){
            cout<<i+1<<' ';
        }
    }
    cout<<endl;
    return 0;
}