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
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


struct st{
  int x, t, p;
  st(){}
  st( int x , int t , int p ) : x(x) , t(t) , p(p) {}
  const bool operator < ( const st &a ) const {
    if( x != a.x ) return x < a.x;
    return t < a.t;
  }
};

const int MAX_N = 100010;

int n, m;

vector<st> l, r;

int b[MAX_N], z[MAX_N];
ld p[MAX_N];

ld ans = 0.0;

void yuyu( vector<st> v ){
  ld res = 0;
  int zero_cnt = 0;
  YYS( w , v ){
    if( w.t == 0 || w.t == 4 ){
      if( w.p == 0 ) zero_cnt++;
      else res += log( (ld)w.p / 100.0 );
    } else if( w.t == 1 || w.t == 3 ){
      if( w.p == 0 ) zero_cnt--;
      else res -= log( (ld)w.p / 100.0 );
    } else if( w.t == 2 ){
      if( zero_cnt > 0 ) p[w.p] = -INFLL;
      else p[w.p] += res;
    }
  }
}


int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ){
    int a, b, c, d;
    scanf( "%d %d %d %d" , &a , &b , &c , &d );
    l.pb( a - b , 0 , 100 - c );
    l.pb( a , 1 , 100 - c );
    r.pb( a + b , 4 , 100 - d );
    r.pb( a , 3 , 100 - d );
  }

  REP( i , m ){
    scanf( "%d %d" , &b[i] , &z[i] );
    l.pb( b[i] , 2 , i );
    r.pb( b[i] , 2 , i );
  }

  SORT( l );
  yuyu( l );
  
  SORT( r ); REVERSE( r );
  yuyu( r );

  REP( i , m ) ans += z[i] * exp( p[i] );

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}