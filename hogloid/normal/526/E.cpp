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
int n,q;
lint B;

int ar[2000005];
lint sum[2000005];
int nxt[2000005],back[2000005];
int solve(){
  if(sum[n]<=B) return 1;
  int j=0;
  REP(i,n){
    while(j<n*2 && sum[j+1]-sum[i]<=B) ++j;
    nxt[i]=j;
  }
  j=n*2-1;
  for(int i=n*2-1;i>=n;--i){
    while(j>=0 && sum[i]-sum[j-1]<=B) --j;
    back[i-n]=j%n;
  }
  int cur=0,cnt=0;
  while(cur<n) cur=nxt[cur],++cnt;
  int pos=cur%n;

  cur%=n;
  REP(hoge,cnt-1) cur=back[cur];
  if(cur<=pos) return cnt-1;
  return cnt;
}

int main(){
  scanf("%d%d",&n,&q);
  REP(i,n) scanf("%d",&ar[i]);
  REP(i,n) ar[i+n]=ar[i];
  REP(i,n*2) sum[i+1]=sum[i]+ar[i];



  REP(hoge,q){
    B=readL();

    printf("%d\n",solve());
  }


  return 0;
}