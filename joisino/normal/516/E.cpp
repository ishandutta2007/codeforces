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

const ll MAX_N = 200010;

ll n, m;
ll b, c;
ll x[MAX_N], y[MAX_N];
set<ll> xs[MAX_N], ys[MAX_N];

ll g;

ll ans;

ll extgcd( ll a , ll b , ll &x , ll &y ){
  ll d = a;
  if( b != 0 ){
    d = extgcd( b , a % b , y , x );
    y -= a / b * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}

set<ll> used;
set<pl> ss;
pl nex( set<pl>::iterator ite ){
  ite++;
  if( ite == ss.end() ) return *ss.begin();
  return *ite;
}

ll solve( ll p ){
  ll res = -1;

  if( xs[p].empty() && ys[p].empty() ) return INFLL;

  REP( swap_swap , 2 ){
    ll nn = n / g;
    ll nm = m / g;

    ll s, t;
    extgcd( nn , nm , s , t );
  
    // self
    ss.clear();
    used.clear();
    YYS( w , xs[p] ) ss.insert( pl( ( t * w % nn + nn ) % nn , w ) );
    YYS( w , ys[p] ) if( xs[p].find( w % nn ) == xs[p].end() && used.find( w % nn ) == used.end() ) ss.insert( pl( ( t * w % nn + nn ) % nn , w+INF ) ), used.insert( w % nn );    
    for( auto ite = ss.begin(); ite != ss.end(); ite++ ){
      ll u = nex( ite ).fi - ( *ite ).fi - 1;
      if( u < 0 ) u += nn;
      if( u == 0 && (*ite).se < INF ) continue;
      chmax( res , u * nm + ( (*ite).se < INF ? (*ite).se : (*ite).se - INF ) );
    }

    swap( n , m );
    swap( xs[p] , ys[p] );
  }

  return res;
}

int ng(){
  printf( "-1\n" );
  return 0;
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  scanf( "%lld" , &b );
  REP( i , b ) scanf( "%lld" , &x[i] );
  scanf( "%lld" , &c );
  REP( i , c ) scanf( "%lld" , &y[i] );

  g = __gcd( n , m );

  if( g > b + c ) return ng();

  REP( i , b ) xs[x[i]%g].insert( x[i] / g );
  REP( i , c ) ys[y[i]%g].insert( y[i] / g );

  REP( i , g ){
    ll res = solve( i );
    if( res == INFLL ) return ng();
    if( res == -1 ) continue;
    chmax( ans , res * g + i );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}