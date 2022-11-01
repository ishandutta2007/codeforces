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
namespace SAIS{
  static const int MAX_N=4000005;
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
char s[400005];
int n,q;
int sa[400005];
int rev[400005],lcp[400005];

int spos[200005],len[200005],belong[400005],belong2[400005];
pi range[200005];
struct min_handler{
  typedef int node;
  min_handler(){}
  static node def_node() { return INF; }
  static node merge(const node& a,const node& b){
    return min(a,b);
  }
};
template<class Handler>
struct segtree{
  typedef typename Handler::node node;
  static const int MAX_N=1100000;
  node val[MAX_N];
  int n;
  Handler hdl;
  void init(int n_,node *a=NULL){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=hdl.def_node();
    if(a!=NULL){
      REP(i,n_) val[i+n-1]=a[i];
      for(int i=n-2;i>=0;--i) val[i]=hdl.merge(val[i*2+1],val[i*2+2]);
    }
  }
  void set(int k,node a){
    k+=n-1;
    val[k]=a;
    while(k>0){
      k=(k-1)/2;
      val[k]=hdl.merge(val[k*2+1],val[k*2+2]);
    }
  }
  void update(int k,node a){
    k+=n-1;
    val[k]=hdl.merge(val[k],a);
    while(k>0){
      k=(k-1)/2;
      val[k]=hdl.merge(val[k*2+1],val[k*2+2]);
    }
  }
  node query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b) return val[i];
    if(b<=l || r<=a) return hdl.def_node();
    int md=(l+r)>>1;
    return hdl.merge(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
  }
  node query(int a,int b){
    return query(a,b,0,0,n);
  }
  node get(int k){
    return val[k+n-1];
  }
};
segtree<min_handler> seg2;
struct segtree_array{
  int n;
  vector<int> val[1150005];
  void init(int n_,int* ar){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n_) val[i+n-1].pb(ar[i]);
    for(int i=n-2;i>=0;--i){
      val[i].resize(val[i*2+1].size()+val[i*2+2].size());
      merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
    }
  }
  int query(int a,int b,int i,int l,int r,int lb,int ub){
    if(a<=l && r<=b) return lower_bound(ALL(val[i]),ub)-lower_bound(ALL(val[i]),lb);
    if(r<=a || b<=l) return 0;
    int md=(l+r)>>1;
    return query(a,b,i*2+1,l,md,lb,ub)+query(a,b,i*2+2,md,r,lb,ub);
  }
};
segtree_array seg;
int main(){
  cin>>n>>q;
  int m=0;
  memset(belong,-1,sizeof(belong));
  REP(i,n){
    scanf("%s",s+m);
    spos[i]=m;
    while(s[m]!='\0'){
      belong[m]=i;
      ++m;
    }
    len[i]=m-spos[i];
    s[m]='$';
    ++m;
  }
  ++m;
  SAIS::SA_IS(s,sa,m);
  SAIS::buildLCP(s,sa,rev,lcp,m);

  seg2.init(m,lcp);

  REP(i,n){
    int p=rev[spos[i]],L=len[i];
    range[i]=mp(p,p);

    int lb=-1,ub=p;
    while(ub-lb>1){
      int md=(lb+ub)>>1;
      if(seg2.query(md,p)>=L) ub=md;
      else lb=md;
    }
    range[i].fr=ub;
    lb=p;ub=m+1;
    while(ub-lb>1){
      int md=(lb+ub)>>1;
      if(seg2.query(p,md)>=L) lb=md;
      else ub=md;
    }
    range[i].sc=lb;
  }
  REP(i,m) belong2[i]=belong[sa[i]];
  REP(i,m) dump(s+sa[i]);
  debug(sa,sa+m);
  debug(belong2,belong2+m);

  seg.init(m,belong2);

  REP(hoge,q){
    int l,r,k;scanf("%d%d%d",&l,&r,&k);--l;--k;
    dump(range[k]);
    int res=seg.query(range[k].fr,range[k].sc+1,0,0,seg.n,l,r);
    printf("%d\n",res);
  }
  return 0;
}