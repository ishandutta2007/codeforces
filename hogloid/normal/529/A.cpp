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

//const int INF=5e8;

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
static const int MAX_N=2000005;
int sa[MAX_N];

char s[2000005];
int n;

int hei[2000005],nxt[2000005];
int main(){
  scanf("%s",s);
  n=strlen(s);
  REP(i,n) s[i+n]=s[i];

  int n2=n*2;
  hei[0]=0;
  REP(i,n2){
    hei[i+1]=hei[i]+(s[i]=='('?1:-1);
  }

  priority_queue<pi> pq;
  REP(i,n2) nxt[i]=n2;
  int d=hei[n];
  int dif;
  if(d>=0) dif=0;
  else dif=-d;
  REP(i,n2){
    while(!pq.empty() && pq.top().fr>hei[i]+dif){
      nxt[pq.top().sc]=i;
      pq.pop();
    }
    pq.push(mp(hei[i],i));
  }

  SAIS::SA_IS(s,sa,n*2+1);

  string res;
  int p=-1;
  REP(i,n2+1){
    if(sa[i]<n && nxt[sa[i]]>=sa[i]+n){
      p=sa[i];
      break;
    }
  }
  if(d<0) REP(i,-d) res+='(';
  REP(i,n) res+=s[p+i];
  if(d>0) REP(i,d) res+=')';
  printf("%s\n",res.c_str());
  return 0;
}