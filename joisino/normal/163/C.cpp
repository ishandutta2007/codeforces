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
// typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

typedef pair<ld,int> st;

const int MAX_N = 100010;

vector<st> evs;

ld th;

int n, l, va, vb;

int res = 0;

ld p[MAX_N];

int main(){

  scanf( "%d %d %d %d" , &n , &l , &va , &vb );

  th = ld(l) * ld(vb) / ld( va + vb ) - EPSLD;

  REP( i , n ){
    int a;
    scanf( "%d" , &a );
    if( a < th ){
      res++;
      evs.pb( th - a , -1 );
    } else {
      evs.pb( th + 2 * l - a , -1 );
    }
    evs.pb( 2 * l - a , 1 );
  }

  evs.pb( 2 * l , 0 );
  
  SORT( evs );
  
  ld cur = 0;
  YYS( w , evs ){
    p[ res ] += w.fi - cur;
    cur = w.fi;
    res += w.se;
  }

  REP( i , n+1 ) printf( "%.18lf\n" , (double)p[i] / (double)( 2 * l ) );
  
  return 0;
}