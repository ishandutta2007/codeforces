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

lint tri(lint x){
  lint lb=0,ub=1e6+5;
  while(ub-lb>1){
    lint md=(lb+ub)>>1;
    if(md*md*md>x) ub=md;
    else lb=md;
  }
  if(lb*lb*lb==x) return lb;
  return -1;
}
bool check(lint a,lint b){
  lint A=tri(a*b);
  if(A==-1) return false;
  if(a%A==0 && b%A==0) return true;
  return false;
}
int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  int n;cin>>n;
  while(n--){
    lint a,b;scanf("%lld%lld",&a,&b);
    puts(check(a,b)?"Yes":"No");
  }

  return 0;
}