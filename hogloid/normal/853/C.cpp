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
static const int MAXN=200005;
struct BIT{
  int val[MAXN*2+2];
  int n;
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n+1) val[i]=0;
  }
  void add(int k,int a){
    ++k;
    while(k<=n){
      val[k]+=a;
      k+=k&-k;
    }
  }
  int query(int k){ //[0,k)
    int res=0;
    while(k>0){
      res+=val[k];
      k-=k&-k;
    }
    return res;
  }
};

BIT bit;


int n,q;
int ctor[200005],rtoc[200005];
pi ps[200005];

pair<pi,pi> rect[200005];
lint ans[200005];

lint c2(int x){
  return x*(lint)(x-1)/2;
}


pair<pi,int> task[200005];

void rotate(pi& A){
  A={A.sc,n-1-A.fr};
}

void doit(){
  REP(i,n){
    ctor[ps[i].fr]=ps[i].sc;
    rtoc[ps[i].sc]=ps[i].fr;
  }
  sort(task,task+q);
  bit.init(n);

  int j=0;
  REP(i,n){
    while(j<q && task[j].fr.fr==i){
      int c=bit.query(task[j].fr.sc);
      ans[task[j].sc]+=c2(c);
      ++j;
    }
    bit.add(ctor[i],1);
  }
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n>>q;
  REP(i,n){
    scanf("%d",&ctor[i]);--ctor[i];
    rtoc[ctor[i]]=i;
    ps[i]={i,ctor[i]};
  }
  REP(i,q){
    int l,d,r,u;scanf("%d%d%d%d",&l,&d,&r,&u);
    --l;--d;
    rect[i]={{l,d},{r,u}};
    ans[i]=c2(n)-c2(l)-c2(d)-c2(n-r)-c2(n-u);
  }

  REP(t,4){
    REP(i,q){
      task[i]={rect[i].fr,i};
    }
    doit();
    REP(i,n){
      rotate(ps[i]);
    }
    REP(i,q){
      pi A={rect[i].sc.fr-1,rect[i].fr.sc};
      pi B={rect[i].fr.fr,rect[i].sc.sc-1};
      rotate(A);
      rotate(B);
      rect[i]={A,{B.fr+1,B.sc+1}};
    }
  }
  REP(i,q) printf("%lld\n",ans[i]);
  return 0;
}