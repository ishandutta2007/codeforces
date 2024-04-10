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


#ifdef ONLINE_JUDGE
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

const int INF=5e8;

int n;
lint x,y;

int ar[500005],cnt[2100005];
lint cnt2[2100005];
lint sum[2100015],sum2[2100015];
const int MAXN=1000005,MAXM=200005;
bool table[MAXN];
int pr[MAXM],m;

const int M=1000093,M2=M*2;
void makepr(){
  memset(table,1,sizeof(table));
  table[0]=table[1]=false;
  for(int i=2;i*i<=M;++i) if(table[i]){
      for(int j=i*i;j<=M;j+=i) table[j]=false;
    }
  REP(i,M+1) if(table[i]) pr[m++]=i;
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n>>x>>y;
  makepr();

  int wid=x/y;//>wid -> delete
  REP(i,n){
    scanf("%d",&ar[i]);
    ++cnt[ar[i]];
    cnt2[ar[i]]+=ar[i];
  }
  REP(i,M2){
    sum[i+1]=sum[i]+(cnt[i]);
    sum2[i+1]=sum2[i]+cnt2[i];
  }

  lint res=1e18;
  REP(i,m) {
    int g = pr[i];
    lint cost=0;
    for (int j = 0; j * g <= M; ++j) {
      int S=j*g+1,T=(j+1)*g;
      int S2=max(S,T-wid);
      cost+=(T*(sum[T]-sum[S2])-(sum2[T]-sum2[S2]))*y;
      cost+=(sum[S2]-sum[S])*x;
    }
    chmin(res,cost);
  }
  cout<<res<<endl;


  return 0;
}