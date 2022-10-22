#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=998244353;
const int mn=1e6+10;
vector<int>g[mn];
int dep[mn],o[mn], bo[mn],ct,anc[mn][20];
set<int>s;
inline auto nxt(set<int>::iterator it){return ++it==s.end()?s.begin():it;}
inline auto pre(set<int>::iterator it){return it==s.begin()?--s.end():--it;}
void ord(int x,int p){
    bo[ct]=x;
    o[x]=ct++;
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        anc[y][0]=x;
        ord(y,x);
    }
}
inline int go(int a,int b){
    for(int i=0;b;i++,b>>=1)if(b&1)a=anc[a][i];
    return a;
}
inline int lca(int a,int b){
    if(dep[a]>dep[b])a=go(a,dep[a]-dep[b]);
    else b=go(b,dep[b]-dep[a]);
    for(int i=19;i>=0;i--){
        if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    }
    if(a==b)return a;
    return anc[a][0];
}
inline int dist(int a,int b){
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
int dtn[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    m=n-m;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ord(1,0);
    anc[1][0]=1;
    for(int i=1;i<20;i++)for(int j=1;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    int dis=2;
    s.insert(o[n]);
    dist(5,2);
    for(int i=n-1;i>=0;i--){
        auto itl=pre(s.lower_bound(o[i]));
        auto itr=nxt(itl);
        int a,b;
        int del=(a=dist(bo[*itl],i))+(b=dist(i,bo[*itr]))-dtn[bo[*itl]];
        if(dis+del<=m*2)s.insert(o[i]),dis+=del,dtn[bo[*itl]]=a,dtn[i]=b;
    }
    for(int i=1;i<=n;i++)if(s.find(o[i])==s.end())printf("%d ",i);
}