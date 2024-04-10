#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
vector<int>g[mn],gg[mn];
int dep[mn],anc[mn][17],o[mn],ct,a[mn],u[mn];
void dfs(int x,int p){
    dep[x]=dep[p]+1;
    anc[x][0]=p;
    o[x]=ct++;
    for(int y:g[x])if(y!=p)dfs(y,x);
}
void go(int&a,int b){
    for(int i=0;b;b>>=1,i++)if(b&1)a=anc[a][i];
}
int lca(int a,int b){
    if(dep[a]>dep[b])go(a,dep[a]-dep[b]);
    else go(b,dep[b]-dep[a]);
    for(int i=16;i>=0;i--)if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    if(a!=b)return anc[a][0];
    return a;
}
int dp[mn][2];
void dfs2(int x,int p){
    bool d=0;
    for(int y:gg[x])if(y!=p){
        dfs2(y,x);
        d=1;
    }
    if(!d){
        dp[x][0]=u[x];
        return;
    }
    int del=0x3f3f3f3f,s1=0,s0=0;
    for(int y:gg[x])if(y!=p){
        s0+=dp[y][0];
        s1+=dp[y][1];
        del=min(del,dp[y][1]-dp[y][0]);
    }
    if(u[x]){
        dp[x][1]=s0;
        dp[x][0]=s0+1;
    }
    else{
        dp[x][0]=min(s0,s1+1);
        dp[x][1]=min(s0+del,dp[x][0]);
    }
}
int main(){
   cin.tie(0);
   cin.sync_with_stdio(0);
   int n;
   cin>>n;
   for(int i=0;i<n-1;i++){
       int a,b;
       cin>>a>>b;
       g[a].push_back(b);
       g[b].push_back(a);
   }
   dfs(1,0);
   for(int i=1;i<17;i++)for(int j=0;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
   int q;
   cin>>q;
   while(q--){
       int m;
       cin>>m;
       for(int i=0;i<m;i++)cin>>a[i],u[a[i]]=1;
       bool ded=0;
       for(int i=0;i<m;i++)if(u[anc[a[i]][0]])ded=1;
       if(ded){
           for(int i=0;i<m;i++)u[a[i]]=0;
           printf("-1\n");
           continue;
       }
       sort(a,a+m,[](int a,int b){return o[a]<o[b];});
       stack<int>s;
       vector<int>v;
       for(int i=0;i<m;i++)v.push_back(a[i]);
       for(int i=0;i<m-1;i++)v.push_back(lca(a[i],a[i+1]));
       sort(v.begin(),v.end(),[](int a,int b){return o[a]<o[b];});
       v.erase(unique(v.begin(),v.end()),v.end());
       s.push(v[0]);
       for(int i=1;i<v.size();i++){
           while(lca(s.top(),v[i])!=s.top())s.pop();
           gg[s.top()].push_back(v[i]),gg[v[i]].push_back(s.top());
           s.push(v[i]);
       }
       dfs2(v[0],0);
       printf("%d\n",min(dp[v[0]][0],dp[v[0]][1]));
       for(int x:v)gg[x].clear(),u[x]=0,dp[x][0]=dp[x][1]=0;
   }
}