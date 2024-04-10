#define DEB
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

//const int INF=5e8;
int n,K;
int ar[40005];


struct SBT{
  int n;
  int val[20][70000];
  int nxt[20][70000],nxt2[20][70000];
  pi seq[70000];
  void build(int l,int r,int dep){
    int p=l,md=(l+r)>>1,p2=md;
    for(int i=l;i<r;++i){
      if(val[dep][i]<md){
        val[dep+1][p++]=val[dep][i];
      }else val[dep+1][p2++]=val[dep][i];
      nxt[dep][i]=p;
      nxt2[dep][i]=p2;
    }
    if(r-l>1){
      build(l,md,dep+1);
      build(md,r,dep+1);
    }
  }
  void init(int len,pi* seq2){
    n=1;
    while(n<len) n<<=1;
    REP(i,len) seq[i]=seq2[i];
    REPN(i,n,len) seq[i]={i,n+1};
    for(int i=0;i<len;++i) val[0][seq2[i].second]=i;
    for(int i=len;i<n;++i) val[0][i]=i;
    build(0,n,0);
  }
  int find(int a,int b,int l,int r,int dep,int k){
    if(r-l==1) return l;
    int md=(l+r)>>1;
    int suma=a==l?l:nxt[dep][a-1],sumb=nxt[dep][b],toleft=sumb-suma;
    if(toleft>=k) return find(a==l?l:nxt[dep][a-1],nxt[dep][b]-1,l,md,dep+1,k);
    else return find(a==l?md:nxt2[dep][a-1],nxt2[dep][b]-1,md,r,dep+1,k- toleft);
  }
  int count(int a,int b,int l,int r,int dep,int K){//count greater than or equal to K
    if(r-l==1){
      if(seq[val[dep][l]].fr>=K && b-a>=0) return 1;
      return 0;
    }
    int md=(l+r)>>1;
    int suma=a==l?l:nxt[dep][a-1],sumb=nxt[dep][b],toleft=sumb-suma;
    if(seq[md].fr>=K) return (b-a+1)-toleft+count(a==l?l:nxt[dep][a-1],nxt[dep][b]-1,l,md,dep+1,K);
    return count(a==l?md:nxt2[dep][a-1],nxt2[dep][b]-1,md,r,dep+1,K);
  }
  int query(int l,int r){
    int tmp=count(l,r-1,0,n,0,r);
    return tmp;
  }
};
SBT sbt;
pi seq[70005];
vector<int> pos[40005];
int dp[55][40005];

int prof(int l,int r){
  return sbt.query(l,r);
}

void rec(int k,int l,int r,int lb,int ub){
  if(r-l<=0) return;
  if(r-l==1){
    for(int i=lb;i<ub;++i) if(dp[k-1][i]!=-1) chmax(dp[k][l],prof(i,l)+dp[k-1][i]);
    return;
  }
  int md=(l+r)>>1;

  int best=-1,pos=-1;
  for(int i=min(md-1,ub-1);i>=lb;--i) {
    if(dp[k-1][i]!=-1) {
      int val2 = dp[k - 1][i] + prof(i,md);
      if (best < val2) {
        best = val2;
        pos = i;
      }
    }
  }

  dp[k][md]=best;
  rec(k,l,md,lb,pos+1);
  rec(k,md+1,r,pos,ub);
}

int nxt[40005];
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n>>K;
  REP(i,n){
    scanf("%d",&ar[i]);
    --ar[i];
    pos[ar[i]].pb(i);
  }

  REP(i,n) pos[i].pb(n+1);
  REP(i,n){
    int p=lower_bound(ALL(pos[ar[i]]),i)-pos[ar[i]].begin();
    if(p+1<pos[ar[i]].size()){
      nxt[i]=pos[ar[i]][p+1];
    }
  }
  REP(i,n) seq[i]={nxt[i],i};
  sort(seq,seq+n);
  sbt.init(n,seq);

  memset(dp,-1,sizeof(dp));
  dp[0][0]=0;
  REP(k,K) {
    rec(k+1,0,n+1,0,n+1);
  }
  int res=dp[K][n];
  cout<<res<<endl;
  return 0;
}