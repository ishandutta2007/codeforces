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

template<class T> pair<vi,vector<T> > compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return make_pair( res , ord );
}

struct BIT{
  vi node;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    node = vi( size , 0 );
  }
  void add( int k , int x ){
    for( int i = k+1; i <= size; i += i & -i ) node[i-1] += x;
  }
  int sum( int k ){
    int res = 0;
    for( int i = k+1; i > 0; i -= i & -i ) res += node[i-1];
    return res;
  }
};

const int MAX_N = 100010;

BIT ls, rs;
int l;

ll inv, ans;
ll n, k;
vi a, ca;

int diff( int x ){
  return ls.sum( n-1 ) - ls.sum( x ) + rs.sum( x - 1 );
}

int main(){

  scanf( "%lld %lld" , &n , &k );
  a.resize( n );
  REP( i , n ) scanf( "%d" , &a[i] );
  ca = compress( a ).fi;

  ls.init( n );
  rs.init( n );
  
  for( ll i = n-1; i >= 0; i-- ){
    inv += diff( ca[i] );
    rs.add( ca[i] , 1 );
  }

  REP( r , n ){
    while( l < r && inv + diff( ca[l] ) <= k ){
      inv += diff( ca[l] );
      ls.add( ca[l] , 1 );
      l++;
    }
    ans += l;
    rs.add( ca[r] , -1 );
    inv -= diff( ca[r] );
  }

  printf( "%lld\n" , ans );

  return 0;
}