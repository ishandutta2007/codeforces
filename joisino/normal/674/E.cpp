#include <bits/stdc++.h>
      
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

#define pb emplace_back
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
     
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n = 1;
int q;

ld res[500010][64];

int par[500010];

int main(){

  par[0] = -1;
  res[0][0] = 1.0;
  
  q = in();
  REP( qc , q ){
    int t = in();
    int v = in() - 1;
    if( t == 1 ){
      int cur = n++;
      par[cur] = v;
      res[cur][0] = 1.0;
      ld prv_cur = 0;
      
      FOR( i , 1 , 64 ){
        int p = par[cur];
        if( p == -1 ){
          break;
        }
        ld temp = res[par[cur]][i];
        res[p][i] = 1.0 - ( 1.0 - res[p][i] ) * ( 1.0 - res[cur][i-1] / 2.0 ) / ( 1.0 - prv_cur / 2.0 ) ;
        prv_cur = temp;
        cur = p;
      }
    } else if( t == 2 ){
      ld ans = 0.0;
      FOR( i , 1 , 64 ){
        ans += res[v][i];
        // if( i < 7 ) cout << res[v][i] << " ";
      }
      // cout << endl;
      printf( "%.18lf\n", (double)ans );
    }
  }
  
  return 0;
}