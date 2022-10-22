#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=4e5+10;
int n,tpm,tot;vector<int>E[maxn],G[maxn];

int now,top,st[maxn],dfn[maxn],low[maxn];
void tarjan(int u){
  dfn[u]=low[u]=++now,st[++top]=u;
  for(int v:G[u]){
    if(!dfn[v]){
      tarjan(v);
      low[u]=min(low[u],low[v]);
      if(low[v]==dfn[u]){
        if(st[top]==v){
          E[u].push_back(v),E[v].push_back(u),top--;
        }else{
          for(tot++;st[top+1]!=v;top--){
            int x=st[top];E[tot].push_back(x),E[x].push_back(tot);
          }
          E[tot].push_back(u),E[u].push_back(tot);
        }
      }
    }else low[u]=min(low[u],dfn[v]);
  }
}

vector<pii>edg;

bool vis[maxn];
void run(vi&V){
  while(!V.empty()){
    int x=V.back();V.pop_back();
    int y=V.back();V.pop_back();
    edg.push_back({x,y});
  }
}
pii dfs(int u,int f){
  vi v1,v2;
  for(int v:E[u])if(!vis[v]&&v!=f){
    pii p=dfs(v,u);int x=p.second;
//    printf("(%d) %d %d\n",v,p.first,p.second);
    if(p.first==1)v1.push_back(x);
    else v2.push_back(x);
  }
  vis[u]=1;
  int sz1=v1.size(),sz2=v2.size();
  if(sz1%2==0&&sz2%2==0){
    run(v2);
    if(f&&sz1){
      int x=v1.back();v1.pop_back(),v1.pop_back(),run(v1);return{2,x};
    }else{
      run(v1);return{1,u};
    }
  }
  if(sz1%2==0&&sz2%2==1){
    if(sz1){
      int x=v1.back();v1.pop_back();
      int y=v2.back();v2.pop_back();
      edg.push_back({x,y}),sz1--,sz2--;
    }else{
      int x=v2.back();v2.pop_back(),run(v2);return{3,x};
    }
  }
  if(sz1%2==1&&sz2%2==0){
    run(v2);
    int x=v1.back();v1.pop_back(),run(v1);return{2,x};
  }
  if(sz1%2==1&&sz2%2==1){
    int y=v2.back();v2.pop_back(),v1.pop_back();
    run(v2),run(v1);return{3,y};
  }
  assert(0);return{-1,-1};
}

void solve(){
  tot=n;
  rep(_,1,tpm){
    int k,x,lst;cin>>k;
    rep(i,1,k){
      scanf("%d",&x);
      if(i>1)G[lst].push_back(x),G[x].push_back(lst);
      lst=x;
    }
  }
  tarjan(1);
  edg.clear();
  rep(i,n+1,tot)vis[i]=1;
  rep(i,1,n)if(!vis[i]){
    pii p=dfs(i,0);
    if(p.first>2)edg.push_back({p.second,i});
  }
  cout<<edg.size()<<endl;
  for(pii p:edg)printf("%d %d\n",p.first,p.second);
  rep(i,1,tot*2)G[i].clear(),E[i].clear(),dfn[i]=low[i]=st[i]=vis[i]=0;now=top=0;
}

signed main(){
  while(~scanf("%d %d",&n,&tpm)&&n){
    solve();
  }
  return 0;
}