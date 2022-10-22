#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,deg[maxn];
vector<int>E[maxn];

int main(){
  ios::sync_with_stdio(0);
  int T;cin>>T;while(T--){
    cin>>n;
    rep(i,1,n){
      deg[i]=0;
      E[i].clear();
    }
    rep(i,1,n){
      int t;cin>>t;
      while(t--){
        int x;cin>>x;
        E[x].push_back(i);
//        printf("(%d %d)\n",x,i);
        deg[i]++;
      }
    }
    static int dis[maxn];
    priority_queue<pii,vector<pii>,greater<pii>>Q;
    rep(i,1,n)dis[i]=0;
    int cnt=0,ans=1;
    rep(i,1,n)if(!deg[i])Q.push({1,i}),dis[i]=1;
    while(!Q.empty()){
      pii p=Q.top();
      int u=p.second;
      Q.pop(),cnt++;
      for(int v:E[u]){
        if(!--deg[v])Q.push({dis[v]=dis[u]+(v<u),v}),ans=max(ans,dis[v]);
      }
    }
    printf("%d\n",cnt==n?ans:-1);
  }
  return 0;
}