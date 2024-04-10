#include <bits/stdc++.h>
using namespace std;

const int NMAX=500010;


const int INF=1000000010;

struct edge{
  int a,b;
  int w;
  edge(){}
  edge(int _a,int _b,int _w){
    a=_a,b=_b,w=_w;
  }
};

bool operator<(edge e1,edge e2)
{
  return e1.w<e2.w;
}

class union_find{
public:
  int c;
  int uf[NMAX];
  union_find(int n){
    c=0;
    for(int i=0;i<n;i++){
      uf[i]=-1;
    }
  }
  int root(int i)
  {
    return uf[i]<0?i:uf[i]=root(uf[i]);
  }
  bool unite(int i,int j)
  {
    i=root(i),j=root(j);
    if(i!=j){
      c++;
      if(-uf[i]<-uf[j]){
	uf[i]=j;
      }
      else if(-uf[i]>-uf[j]){
	uf[j]=i;
      }
      else{
	uf[i]=j;
	uf[j]--;
      }
      return 1;
    }
    return 0;
  }
};

vector<vector<int> > e;
vector<vector<bool> > tp;

const int BS=19;
static int par[NMAX],dep[NMAX],db[NMAX][BS];
static bool type[NMAX];
static int dbmin[NMAX][BS];

void dfs(int i,int p)
{
  dep[i]=(p==i?0:dep[p]+1);
  par[i]=p;
  db[i][0]=p;
  for(int t=1;t<BS;t++){
    db[i][t]=db[db[i][t-1]][t-1];
  }
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    type[j]=tp[i][x];
    dfs(j,i);
  }
}

int main()
{
  int n,k,m;
  scanf("%d%d%d",&n,&k,&m);
  vector<int> ga(k),gb(k);
  e=vector<vector<int> >(n);
  tp=vector<vector<bool> >(n);
  union_find uf(n);
  for(int i=0;i<k;i++){
    scanf("%d%d",&ga[i],&gb[i]);
    ga[i]--,gb[i]--;
    e[ga[i]].push_back(gb[i]);
    tp[ga[i]].push_back(true);
    e[gb[i]].push_back(ga[i]);
    tp[gb[i]].push_back(true);
    uf.unite(ga[i],gb[i]);
  }
  vector<edge> E(m);
  for(int i=0;i<m;i++){
    int a,b;
    int w;
    scanf("%d%d%d",&a,&b,&w);
    a--,b--;
    E[i]=edge(a,b,w);
  }
  sort(E.begin(),E.end());
  vector<bool> use(m,false);
  for(int i=0;i<m;i++){
    int a=E[i].a,b=E[i].b;
    if(uf.unite(a,b)){
      //printf("%d %d\n",a+1,b+1);
      use[i]=true;
      e[a].push_back(b);
      tp[a].push_back(false);
      e[b].push_back(a);
      tp[b].push_back(false);
    }
  }
  for(int i=0;i<n;i++)par[i]=-1;
  for(int i=0;i<n;i++){
    if(par[i]==-1){
      dfs(i,i);
    }
  }
  for(int i=0;i<n;i++){
    for(int t=0;t<BS;t++){
      dbmin[i][t]=INF;
    }
  }
  for(int i=0;i<m;i++){
    if(use[i])continue;
    int a=E[i].a,b=E[i].b;
    int w=E[i].w;
    if(dep[a]<dep[b]){
      swap(a,b);
    }
    if(dep[a]>dep[b]){
      for(int t=BS-1;t>=0;t--){
	if(dep[a]-(1<<t)>dep[b]){
	  dbmin[a][t]=min(dbmin[a][t],w);
	  a=db[a][t];
	}
      }
      dbmin[a][0]=min(dbmin[a][0],w);
      a=db[a][0];
    }
    if(a!=b){
      for(int t=BS-1;t>=0;t--){
	if(db[a][t]!=db[b][t]){
	  dbmin[a][t]=min(dbmin[a][t],w);
	  a=db[a][t];
	  dbmin[b][t]=min(dbmin[b][t],w);
	  b=db[b][t];
	}
      }
      dbmin[a][0]=min(dbmin[a][0],w);
      a=db[a][0];
      dbmin[b][0]=min(dbmin[b][0],w);
      b=db[b][0];
    }
    assert(a==b);
  }
  for(int t=BS-1;t>0;t--){
    for(int i=0;i<n;i++){
      dbmin[i][t-1]=min(dbmin[i][t-1],dbmin[i][t]);
      dbmin[db[i][t-1]][t-1]=min(dbmin[db[i][t-1]][t-1],dbmin[i][t]);
    }
  }
  //seg.eval_all();
  long long ans=0ll;
  for(int i=0;i<n;i++){
    long long w=dbmin[i][0];
    //printf("%d %lld\n",i+1,w);
    if(par[i]==i||!type[i])continue;
    if(w==INF){
      ans=-1;
      break;
    }
    //printf("%d %d %lld\n",RX[i]+1,par[RX[i]]+1,w);
    ans+=w;
  }
  printf("%lld\n",ans);
  return 0;
}