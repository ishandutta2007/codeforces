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

int n;
int ar[100005];
int br[100005];

bool vis[100005];
int main() {
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt", "r", stdin);
#endif
  cin >> n;
  REP(i, n) cin >> ar[i], br[i] = ar[i];
  sort(br, br + n);
  REP(i, n) ar[i] = lower_bound(br, br + n, ar[i]) - br;

  vector<vector<int> >ans;
  REP(i, n) if (!vis[i]) {
      int cur = i;
      vector<int> res;
      while (!vis[cur]) {
        vis[cur] = 1;
        res.pb(cur);
        cur = ar[cur];
      }
      ans.pb(res);
    }
  cout<<ans.size()<<endl;
  for(auto res:ans){
    sort(ALL(res));
      printf("%d",(int)res.size());
      for(auto e:res) printf(" %d",e+1);
      puts("");
    }
  return 0;
}