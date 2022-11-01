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


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
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

const int INF=5e8;
namespace SAIS{
  static const int MAX_N=2000005;
  typedef vector<int> vi;
  typedef vector<bool> vb;
  int bkt[MAX_N+1];
  void setBuckets(int* s, int n, int K,bool end){
    for(int i=0;i<=K;++i) bkt[i]=0;
    for(int i=0;i<n;++i) bkt[s[i]]++;
    int sum=0;
    for(int i=0;i<=K;++i){
      sum+=bkt[i];
      bkt[i]=(end?sum:sum-bkt[i]);
    }
  }
  void induceSAL(const vb& t,int* SA,int* s,int n,int K,bool end){
    setBuckets(s,n,K,end);
    int j;
    for(int i=0;i<n;++i){
      j=SA[i]-1;
      if(j>=0 && !t[j]) SA[bkt[s[j]]++]=j;
    }
  }
  void induceSAS(const vb& t,int* SA,int* s,int n,int K,bool end){
    setBuckets(s,n,K,end);
    int j;
    for(int i=n-1;i>=0;--i){
      j=SA[i]-1;
      if(j>=0 && t[j]) SA[--bkt[s[j]]]=j;
    }
  }
#define isLMS(i) (i>0 && t[i] && !t[i-1])
  void SA_IS(int* s,int *SA,int n,int K){
  //s[n-1] is assumed to be 0
  //each element of s[0...n-2] \in [1...K]
    vector<bool> t(n);

    t[n-1]=1;//1 for S
    t[n-2]=0;//0 for L
    for(int i=n-3;i>=0;--i){
      if(s[i]<s[i+1] || (s[i]==s[i+1] && t[i+1]==1)) t[i]=1;
      else t[i]=0;
    }
    setBuckets(s,n,K,true);
    for(int i=0;i<n;++i) SA[i]=-1;
    for(int i=1;i<n;++i) if(isLMS(i)) SA[--bkt[s[i]]]=i;

    induceSAL(t,SA,s,n,K,false);
    induceSAS(t,SA,s,n,K,true);

    int n1=0;
    for(int i=0;i<n;++i) if(isLMS(SA[i])) SA[n1++]=SA[i];

    for(int i=n1;i<n;++i) SA[i]=-1;
    int rank=0, prev=-1;
    for(int i=0;i<n1;++i){
      int pos=SA[i];
      bool dif=false;
      for(int d=0;d<n;++d){
        if(prev==-1 || s[pos+d]!=s[prev+d] || t[pos+d]!=t[prev+d]){
          dif=true;
          break;
        }else if(d>0 && (isLMS(pos+d) || isLMS(prev+d))) break;
      }
      if(dif){
        ++rank;
        prev=pos;
      }
      pos>>=1;
      SA[n1+pos]=rank-1;
    }
    for(int i=n-1,j=n-1;i>=n1;--i) if(SA[i]>=0) SA[j--]=SA[i];

    int *SA1=SA,*s1=SA+n-n1;
    if(rank<n1) SA_IS(s1,SA1,n1,rank-1);
    else for(int i=0;i<n1;++i) SA1[s1[i]]=i;


    setBuckets(s,n,K,true);
    for(int i=1,j=0;i<n;++i) if(isLMS(i)) s1[j++]=i;
    for(int i=0;i<n1;++i) SA1[i]=s1[SA1[i]];
    for(int i=n1;i<n;++i) SA[i]=-1;
    for(int i=n1-1,j;i>=0;--i){
      j=SA[i];
      SA[i]=-1;
      SA[--bkt[s[j]]]=j;
    }
    induceSAL(t,SA,s,n,K,false);
    induceSAS(t,SA,s,n,K,true);
  }
  int tmp[MAX_N];
  void SA_IS(char* s,int* SA,int n){
    REP(i,n) tmp[i]=s[i];
    SA_IS(tmp,SA,n,260);
  }
  void buildLCP(char* s,int* sa,int* rev,int* lcp,int n){
    int h=0;
    REP(i,n) rev[sa[i]]=i;
    REP(i,n){
      if(rev[i]==n) lcp[rev[i]]=0;
      else{
        for(int j=sa[rev[i]+1];j+h<=n && i+h<=n && s[i+h]==s[j+h];++h);
        lcp[rev[i]]=h;
      }
      if(h>0) --h;
    }
  }
};


namespace hld{
  const int MAXN=300005;
  int belong[MAXN];
  int dep[MAXN];
  int root[MAXN];
  vector<int> path[MAXN];
  int pcnt;
  vector<int>* g;

  int vis[MAXN],leave[MAXN],ord;
  int par[MAXN];

  int size[MAXN];
  int prep(int v,int p,int d){
    par[v]=p;
    vis[v]=ord;++ord;
    dep[v]=d;
    size[v]=1;
    for(auto to:g[v]) if(to!=p){
      size[v]+=prep(to,v,d+1);
    }
    leave[v]=ord;++ord;
    return size[v];
  }
  vector<int> curpath;
  void dfs(int v,int p){
    curpath.pb(v);
    int nxt=-1;
    for(auto to:g[v]) if(to!=p){
      if(nxt==-1 || size[nxt]<size[to]) nxt=to;
    }
    if(nxt==-1){
      for(auto u:curpath) belong[u]=pcnt,root[u]=curpath[0];
      path[pcnt].swap(curpath);
      assert(curpath.empty());
      ++pcnt;
    }else{
      dfs(nxt,v);
    }
    for(auto to:g[v]) if(to!=p && to!=nxt){
      dfs(to,v);
    }
  }
  void init(vector<int>* g_,int n,int R){
    g=g_;
    pcnt=0;
    REP(i,n) path[i].clear();
    curpath.clear();
    CLR(size);
    prep(R,-1,0);

    dfs(R,-1);
  }
  bool upper(int u,int v){//R -- u -- v ?
    return vis[u]<=vis[v] && leave[v]<=leave[u];
  }
  pi climb[30],des[30];
  int getpath(int u,int v,pi* ar){
    int c1=0,c2=0;
    while(!upper(root[u],v)){
      climb[c1++]=mp(u,root[u]);
      u=par[root[u]];
    }
    while(!upper(root[v],u)){
      des[c2++]=mp(root[v],v);
      v=par[root[v]];
    }
    assert(belong[u]==belong[v]);

    if(dep[u]<dep[v]){
      climb[c1++]=mp(u,v);
    }else{
      des[c2++]=mp(u,v);
    }
    int cnt=0;
    REP(i,c1) ar[cnt++]=climb[i];
    for(int i=c2-1;i>=0;--i) ar[cnt++]=des[i];
    return cnt;
  }


  //end library

  pi stpos[MAXN];
  char s[MAXN*2];
  int sa[MAXN*2],lcp[MAXN*2],rev[MAXN*2];
  struct RMQ{
    static const int MAX_N=MAXN*2,MAX_LOG_N=20;
    int val[MAX_LOG_N][MAX_N];
    int log2[MAX_N];
    int n;
    void init(int n_,int *a){
      n=n_;
      REP(i,n) val[0][i]=a[i];
      REP(i,MAX_LOG_N-1) REP(j,n){
        if(j+(1<<i)>=n) val[i+1][j]=val[i][j];
        else val[i+1][j]=min(val[i][j],val[i][j+(1<<i)]);
      }
      REP(i,n+1){
        while((1<<(log2[i]+1))<=i) ++log2[i];
      }
    }
    int query(int a,int b){
      if(a>b) swap(a,b);
      if(a==b) return INF;
      int len=b-a,l=log2[len];
      return min(val[l][a],val[l][b-(1<<l)]);
    }
  };
  RMQ rmq;
  void buildSA(char* label){
    int cnt=0;
    REP(i,pcnt){
      stpos[i]=mp(cnt,cnt+path[i].size());
      for(auto u:path[i]) s[cnt++]=label[u];
      reverse(ALL(path[i]));
      for(auto u:path[i]) s[cnt++]=label[u];
      reverse(ALL(path[i]));
    }
    s[cnt++]='\0';
    dump(s);
    SAIS::SA_IS(s,sa,cnt);
    SAIS::buildLCP(s,sa,rev,lcp,cnt);

    rmq.init(cnt-1,lcp);
  }

  pi getspos(int u,int v){
    int id=belong[u];
    if(upper(u,v)){
      int d=dep[path[id][0]];
      return mp(stpos[id].fr+dep[u]-d,stpos[id].fr+dep[v]-d+1);
    }else{
      int d=dep[path[id].back()];
      return mp(stpos[id].sc+d-dep[u],stpos[id].sc+d-dep[v]+1);
    }
  }

  int query(int a,int b,int c,int d){
    pi ar1[35],ar2[35];
    int c1=getpath(a,b,ar1),c2=getpath(c,d,ar2);
    debug(ar1,ar1+c1);
    debug(ar2,ar2+c2);

    int i=0,j=0,off1=0,off2=0;
    int sum=0;
    while(i<c1 && j<c2){
      pi r1=getspos(ar1[i].fr,ar1[i].sc),r2=getspos(ar2[j].fr,ar2[j].sc);
      r1.fr+=off1;
      r2.fr+=off2;
      dump(r1);dump(r2);
      int len=min(r1.sc-r1.fr,r2.sc-r2.fr);

      debug(s+r1.fr,s+r1.fr+len);
      debug(s+r2.fr,s+r2.fr+len);

      int len2=rmq.query(rev[r1.fr],rev[r2.fr]);
      dump(len2);
      chmin(len2,len);
      sum+=len2;
      if(len2<len) return sum;
      if(r1.sc-r1.fr==len2) ++i,off1=0;
      else off1+=len2;
      if(r2.sc-r2.fr==len2) ++j,off2=0;
      else off2+=len2;
    }
    return sum;
  }
}
char s[300005];
int n,m;
vector<int> g[300005];
int main(){
  cin>>n;
  scanf("%s",s);
  REP(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);--u;--v;
    g[u].pb(v);
    g[v].pb(u);
  }
  hld::init(g,n,0);
  hld::buildSA(s);
  
  int q;cin>>q;
  while(q--){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    --a;--b;--c;--d;
    int res=hld::query(a,b,c,d);
    printf("%d\n",res);
  }
  return 0;
}