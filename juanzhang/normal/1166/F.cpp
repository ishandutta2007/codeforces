#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int n,m,c,q;

map<int,int>ce[maxn];
set<int>S[maxn];
int par[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y){
  if((x=find(x))!=(y=find(y))){
    if(S[x].size()<S[y].size())swap(x,y);
    par[y]=x;
    for(int tp:S[y])S[x].insert(tp);
    S[y].clear();
  }
}

void add(int u,int v,int c){
  int tp=ce[u][c];
  if(tp)unite(v,tp);
  else ce[u][c]=v;
  tp=ce[v][c];
  if(tp)unite(u,tp);
  else ce[v][c]=u;
  S[find(u)].insert(v);
  S[find(v)].insert(u);
}

void solve(){
  cin>>n>>m>>c>>q;
  rep(i,1,n)par[i]=i;
  rep(i,1,m){
    int u=read(),v=read();add(u,v,read());
  }
  while(q--){
    char ch;int u,v;scanf("%s%d%d",&ch,&u,&v);
    if(ch=='+')add(u,v,read());
    else puts(find(u)==find(v)||S[find(u)].count(v)?"Yes":"No");
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}