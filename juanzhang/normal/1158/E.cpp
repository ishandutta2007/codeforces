#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

int n;

vi query(vi d){
  printf("? ");
  rep(i,0,n-1)printf("%d%c",d[i],"\n "[i<iend]);
  fflush(stdout);
  vi res(n);
  rep(i,0,n-1)scanf("%1d",&res[i]);
  return res;
}

struct one{
  int sz;
  vi cho,ans;
  void init(int n,const vi&can){
    cho=vi(n,0);
    int cnt=0;
    rep(i,0,n-1)cnt+=can[i];
    rep(_,1,min(cnt,sz)){
      int u;
      do{
        u=Rnd()%n;
      }while(cho[u]||!can[u]);
      cho[u]=1;
    }
    rep(_,1,sz-cnt){
      int u;
      do{
        u=Rnd()%n;
      }while(cho[u]);
      cho[u]=1;
    }
    ans=query(cho);
  }
  bool ask(int u,int v){
    return u!=v&&(!cho[u]||ans[v]);
  }
};

vector<vi>E;
vi onc,vis,fa,val;
void dfs(int u,int f){
  vis[u]=1,fa[u]=f;
  rep(v,0,n-1)if(E[u][v]){
    if(!vis[v]){
      dfs(v,u);
      val[u]+=val[v];
    }else if(v!=f){
      val[u]++;
      if(fa[v]!=-1)val[fa[v]]--;
    }
  }
  if(!val[u])onc[u]=0;
}

vector<pii>solve(int n){
  fa.resize(n);
  E=vector<vi>(n,onc=vi(n,1));
  rep(_,1,80){
    int cnt=0;
    rep(i,0,n-1)cnt+=onc[i];
    if(!cnt)break;
    one A;
    A.sz=max(1,cnt/5);
    A.init(n,onc);
    rep(u,0,n-1){
      rep(v,0,n-1){
        if(E[u][v]&&!A.ask(u,v))E[u][v]=E[v][u]=0;
      }
    }
    vis=val=vi(n,0);
    dfs(0,-1);
  }
  vector<pii>ans;
  rep(u,0,n-1)rep(v,u+1,n-1)if(E[u][v])ans.pb({u+1,v+1});
  return ans;
}

int main(){
  cin>>n;
  auto ans=solve(n);
  puts("!");
  for(pii p:ans)printf("%d %d\n",p.first,p.second);
  fflush(stdout);
  return 0;
}