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

//const int INF=5e8;

int n;
int ar[105];

const int M=(1<<20);
int memo[M+5];

map<int,int> memo2;
int rec(int x){
  x&=(~1);
  if(x<M) return memo[x];
  if(memo2.count(x)) return memo2[x];
  int mark[35]={0};
  REPN(d,32,1){
    int rest=(x>>d);
    if(rest==0) break;
    int nxt=(rest|(x&((1<<d)-1)));
    nxt&=~(1);
    int a=rec(nxt);
    if(a<35) mark[a]=1;
  }
  int res=0;
  while(mark[res]) ++res;
  return memo2[x]=res;
}

int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif

  memo[1]=0;
  for(int i=2;i<=M;i+=2){
    set<int> S;
    int mark[35]={0};
    REPN(d,32,1){
      int rest=(i>>d);
      if(rest==0) break;
      int nxt=(rest|(i&((1<<d)-1)));
      nxt&=~(1);
      if(memo[nxt]<35) mark[memo[nxt]]=1;
    }
    while(mark[memo[i]]) ++memo[i];
  }

  cin>>n;
  REP(i,n) cin>>ar[i];

  set<int> prm;
  REP(i,n){
    int tmp=ar[i];
    for(int p=2;p*p<=tmp;++p) if(tmp%p==0){
        while(tmp%p==0) tmp/=p;
        prm.insert(p);
      }
    if(tmp>1) prm.insert(tmp);
  }

  int gru=0;
  for(auto p:prm){
    int bit=0;
    REP(i,n){
      int cnt=0;
      int tmp=ar[i];
      while(tmp%p==0){
        tmp/=p;
        ++cnt;
      }
      bit|=(1<<cnt);
    }
    bit&=(~1);
    gru^=rec(bit);
  }
  if(gru) puts("Mojtaba");
  else puts("Arpa");

  return 0;
}