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
ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head


struct Mod{
  unsigned n;
  Mod(){}
  Mod( ll x ){
    if( x < 0 ) n = x%MOD+MOD;
    else n = x%MOD;
  }
};
Mod operator + ( Mod a  , Mod b ){ return Mod( a.n + b.n ); }
Mod operator +=( Mod &a , Mod b ){ return a = a + b; }
Mod operator - ( Mod a  , Mod b ){ return Mod( a.n + MOD - b.n ); }
Mod operator -=( Mod &a , Mod b ){ return a = a - b; }
Mod operator * ( Mod a  , Mod b ){ return Mod( (ll)a.n * b.n ); }
Mod operator *=( Mod &a , Mod b ){ return a = a * b; }
Mod modpow( Mod x , ll k ){
  Mod res = 1;
  while( k ){
    if( k & 1 ) res *= x;
    k /= 2;
    x *= x;
  }
  return res;
}
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
Mod inv( Mod a ){ ll x, y; assert( extgcd( a.n , MOD , x , y ) == 1 ); return Mod( x ); }
// Mod inv( Mod a ){ return modpow( a , MOD-2 ); }
Mod operator / ( Mod a  , Mod b ){ return Mod( (ll)a.n * inv(b).n ); }
Mod operator /=( Mod &a , Mod b ){ return a = a / b; }


ll MO;

vpi G[100010];

bool centroid[100010];
ll subtree_size[100010];

ll ans;

vpl va;
vl vb;

ll compute_subtree_size( ll v , ll p ){
  ll c = 1;
  YYS( w , G[v] ){
    if( w.fi == p || centroid[w.fi] ) continue;
    c += compute_subtree_size( w.fi , v );
  }
  return subtree_size[v] = c;
}

pl search_centroid( ll v , ll p , ll t ){
  pl res = pi( INF , -1 );
  ll s = 1, m = 0;
  YYS( w , G[v] ){
    if( w.fi == p || centroid[w.fi] ) continue;

    res = min( res , search_centroid( w.fi , v , t ) );

    chmax( m , subtree_size[w.fi] );
    s += subtree_size[w.fi];
  }

  chmax( m , t-s );
  chmin( res , pl( m , v ) );
  return res;
}

void dfs( ll x , ll p , ll d , ll cura , ll curb , ll mul ){
  va.pb( cura , d );
  vb.pb( curb );
  YYS( w , G[x] ){
    if( centroid[w.fi] || w.fi == p ) continue;

    dfs( w.fi , x , d+1 , (cura*10+w.se)%MO , (curb+w.se*mul)%MO , (mul*10)%MO );
  }
}

void solve_subproblem( ll v ){
  compute_subtree_size( v , -1 );
  ll s = search_centroid( v , 1 , subtree_size[v] ).se;
  centroid[s] = true;

  YYS( w , G[s] ){
    if( centroid[w.fi] ) continue;
    solve_subproblem( w.fi );
  }

  vpl ava(0);
  vl avb(0);

  ava.pb( 0 , 0 );
  avb.pb( 0 );

  ans--;
  
  YYS( w , G[s] ){
    if( centroid[w.fi] ) continue;

    va.clear();
    vb.clear();
    dfs( w.fi , s , 1 , w.se % MO , w.se % MO , 10 );

    SORT( vb );

    YYS( w , va ){
      ll b = ( Mod(-1) *  Mod(w.fi) / modpow( 10 , w.se ) ).n;
      ans -= upper_bound( ALL(vb) , b ) - lower_bound( ALL(vb) , b );
    }

    YYS( w , vb ) avb.pb( w );
    YYS( w , va ) ava.pb( w );
  }

  SORT(avb);
  
  //cout << "v : " << v << ", ans : " << ans << endl;
  //YYS( w , avb ) cout << w << endl;

  YYS( w , ava ){
    ll b = ( Mod(-1) *  Mod(w.fi) / modpow( 10 , w.se ) ).n;
    // cout << w.fi << " " << w.se << " " << b << " " << upper_bound( ALL(avb) , b ) - lower_bound( ALL(avb) , b ) << endl;
    ans += upper_bound( ALL(avb) , b ) - lower_bound( ALL(avb) , b );
  }

  // cout << "v : " << v << ", centroid : " << s << ", ans : " << ans << endl;
  
  centroid[s] = false;
}

ll n;

int main(){

  scanf( "%lld %lld" ,  &n , &MO );
  MOD = MO;
  REP( i , n-1 ){
    int a, b, c;
    scanf( "%d %d %d" , &a , &b , &c );
    G[a].pb( b , c );
    G[b].pb( a , c );
  }

  solve_subproblem( 0 );

  printf( "%lld\n" , ans );
  
  return 0;
}