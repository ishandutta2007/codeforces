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

//const int INF=5e8;

typedef vector<int> vec;
vec subt(const vec& A,const vec&B){
  vec res(A.size());
  REP(i,A.size()) res[i]=A[i]-B[i];
  return res;
}
bool acute(const vec& A,const vec& B,const vec& C){
  vec X=subt(B,A),Y=subt(C,A);
  lint sum=0;
  REP(i,X.size()) sum+=X[i]*Y[i];
  return sum>0;
}
int n;
const int M=200;
vec ar[1005];
bool bad[1005];
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n;
  if(n>M){
    puts("0");
    return 0;
  }
  REP(i,n){
    ar[i].resize(5);
    REP(j,5){
      cin>>ar[i][j];
    }
  }
  REP(i,n) if(!bad[i]) REP(j,n) REP(k,j) if(j!=i && k!=i){
          if(acute(ar[i],ar[j],ar[k])){
            bad[i]=true;
          }
      }
  vector<int> ans;
  REP(i,n) if(!bad[i]) ans.pb(i);
  cout<<ans.size()<<endl;
  for(auto e:ans) printf("%d\n",e+1);


  return 0;
}