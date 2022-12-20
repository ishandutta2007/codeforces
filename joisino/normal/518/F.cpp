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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct Bit{
  vl bit;
  ll size;
  void init( ll n ){
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size , 0 );
    FOR( i , 1 , size+1 ) bit[i-1] = i & -i;
  }
  void add( ll k , ll v ){
    for( ll i = k+1; i <= size; i += i & -i ) bit[i-1] += v;
  }
  ll sum( ll k ){ // [0,k)
    ll res = 0;
    for( ll i = k; i > 0; i -= i & -i ) res += bit[i-1];
    return res;
  }
  ll sum( ll l , ll r ){ // [l,r)
    return sum( r ) - sum( l );
  }
  ll get( ll k ){
    return sum( k+1 ) - sum( k );
  }
  ll update( ll k , ll x ){
    add( k , x - get(k) );
  }
};


const int MAX_N = 2010;

ll n, m;
char s[MAX_N][MAX_N];

ll tol[MAX_N], tot[MAX_N], tob[MAX_N];
ll ans;

vl sweep[MAX_N];

Bit bit;

void sw(){
  REP( i , max(n,m) ) REP( j , i ) swap( s[i][j] , s[j][i] );
  swap( n , m );
}
void fl(){
  REP( i , n ) REP( j , m/2 ) swap( s[i][j] , s[i][m-1-j] );
}
void rot(){
  sw();
  fl();
}

int main(){

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) scanf( "%s" , s[i] );

  REP( rot_rot , 4 ){
    REP( i , n ) tol[i] = m;
    REP( i , n ) REP( j , m ) if( s[i][j] == '#' ){ tol[i] = j; break; }
    REP( j , m ) tot[j] = n;
    REP( j , m ) REP( i , n ) if( s[i][j] == '#' ){ tot[j] = i; break; }
    
    FOR( i , 1 , n-1 ) FOR( j , 1 , m-1 ) if( tol[i] > j && tot[j] > i ) ans++;

    FOR( i , 1 , n-1 ){
      bit.init( m );
      
      REP( j , m ) if( tot[j] == i-1 ){
	tot[j] = n;
	FOR( k , i , n ) if( s[k][j] == '#' ){ tot[j] = k; break; }
      }

      REP( i , n+1 ) sweep[i].clear();
      REP( j , m ) sweep[ tot[j] ].pb( j );

      FOR( j , i , i+2 ) YYS( w , sweep[j] ) bit.add( w , -1 );
      
      FOR( j , i+2 , n-1 ){
	YYS( w , sweep[j] ) bit.add( w , -1 );
	ans += bit.sum( 1 , min( min( tol[i] , tol[j] ) , m-1 ) );
      }
    }
    
    rot();
  }

  REP( swap_swap , 2 ){
    REP( j , m ) tot[j] = n;
    REP( j , m ) REP( i , n ) if( s[i][j] == '#' ){ tot[j] = i; break; }
    REP( j , m ) tob[j] = 0;
    REP( j , m ) for( int i = n-1; i >= 0; i-- ) if( s[i][j] == '#' ){ tob[j] = i; break; }
    
    FOR( i , 1 , m-1 ) if( tot[i] == n ) ans++;

    REP( flip_flip , 2 ){
      REP( i , n ) tol[i] = m;
      REP( i , n ) REP( j , m ) if( s[i][j] == '#' ){ tol[i] = j; break; }
      
      FOR( j , 1 , m-1 ){
	bit.init( n );

	REP( i , n ) if( tol[i] == j-1 ){
	  tol[i] = m;
	  FOR( k , j , m ) if( s[i][k] == '#' ){ tol[i] = k; break; }
	}

	REP( i , m+1 ) sweep[i].clear();
	REP( i , n ) sweep[ tol[i] ].pb( i );

	YYS( w , sweep[j] ) bit.add( w , -1 );
	
	FOR( k , j+1 , m-1 ){
	  YYS( w , sweep[k] ) bit.add( w , -1 );
	  if( tot[j]-1 >= tob[k]+1 ) ans += bit.sum( tob[k]+1 ,  min( tot[j] , n-1 ) );
	}
      }
      fl();
      REP( j , m/2 ){
	swap( tot[j] , tot[m-1-j] );
	swap( tob[j] , tob[m-1-j] );
      }
    }
    
    sw();
  }

  printf( "%lld\n" , ans );
  
  return 0;
}