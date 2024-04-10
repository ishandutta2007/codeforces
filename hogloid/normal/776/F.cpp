#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}

const int INF=5e8;
int n,m;

typedef vector<int> vi;
vi g[100005];

pi mst2[100005];
pi es[100005];

int idx[100005],rev[100005];

vi g2[100005];

int res[100005];
bool cut[100005];

int size[100005],whole;
int gsize(int v,int p){
  size[v]=1;
  for(auto to:g2[v]){
    if(cut[to] || to==p) continue;
    size[v]+=gsize(to,v);
  }
  return size[v];
}
int root,cost;

void groot(int v,int p){
  int C=whole-size[v];
  for(auto to:g2[v]){
    if(cut[to] || to==p) continue;
    groot(to,v);
    chmax(C,size[to]);
  }
  if(cost>C){
    cost=C;
    root=v;
  }
}

void dfs(int v,int rank){
  whole=gsize(v,-1);
  cost=INF;
  groot(v,-1);

  v=root;
  res[v]=rank;
  if(whole==1) return;
  cut[v]=1;
  for(auto to:g2[v]){
    if(cut[to]) continue;
    dfs(to,rank+1);
  }
}
int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    if(a>b) swap(a,b);
    es[i]={a,b};
  }
  es[m++]={0,n-1};
  sort(es,es+m,[&](pi a,pi b){
    return a.sc-a.fr<b.sc-b.fr;
  });

  set<pair<pi,int> > range;
  int cnt=0;
  REP(i,m){
    int a=es[i].fr,b=es[i].sc;
    auto it=range.lower_bound({{a,-1},-1});
    pi last={-1,-1};
    while(it!=range.end() && it->fr.sc<=b){
      last=it->fr;
      g[cnt].pb(it->sc);
      g[it->sc].pb(cnt);
      range.erase(it++);
    }
    if(last.sc==b) mst2[cnt]={last.fr,b};
    else mst2[cnt]={b-1,b};
    range.insert({{a,b},cnt});
    ++cnt;
  }

  REP(i,cnt) if(mst2[i].sc>mst2[i].fr) swap(mst2[i].fr,mst2[i].sc);

  REP(i,cnt) idx[i]=i;
  sort(idx,idx+cnt,[&](int a,int b){
    return mst2[a]<mst2[b];
  });
  REP(i,cnt) rev[idx[i]]=i;

  REP(i,cnt) for(auto to:g[i]) g2[rev[i]].pb(rev[to]);

  dfs(0,0);

  REP(i,cnt) printf("%d\n",res[i]+1);
  return 0;
}