#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;
const int B = 765;

int n, m, q;

bool is_heavy[MAX_N];
ll ans[MAX_N];
ll added[MAX_N];
vl intersect[MAX_N];
ll a[MAX_N];
vi s[MAX_N];

vi heavys;

bool used[MAX_N];

int main(){

  scanf( "%d %d %d" , &n , &m , &q );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , m ){
    int size = 0;
    scanf( "%d" , &size );
    REP( j , size ){
      int x;
      scanf( "%d" , &x ); x--;
      s[i].pb( x );
    }
    if( s[i].size() >= B ){
      is_heavy[i] = true;
      heavys.pb( i );
    }
  }
  
  YYS( i , heavys ){
    intersect[i].resize( m );
    REP( j , n ) used[j] = false;
    YYS( w , s[i] ) used[w] = true;
    REP( j , m ) YYS( w , s[j] ) if( used[w] ) intersect[i][j]++;

    YYS( w , s[i] ) ans[i] += a[w];
  }

  scanf( "\n" );
  REP( query_cnt , q ){
    char t;
    int x;
    ll y;
    scanf( "%c" , &t );
    if( t == '?' ){
      scanf( "%d\n" , &x ); x--;
      ll p = 0;
      YYS( w , heavys ) p += added[w] * intersect[w][x];
      if( is_heavy[x] ){
	printf( "%lld\n" , ans[x] + p );
      } else {
	ll res = 0;
	YYS( w , s[x] ) res += a[w];
	printf( "%lld\n" , res + p );
      }
    } else if( t == '+' ){
      scanf( "%d %lld\n" , &x , &y ); x--;
      if( is_heavy[x] ){
	added[x] += y;
      } else {
	YYS( w , s[x] ) a[w] += y;
	YYS( w , heavys ) ans[w] += y * intersect[w][x];
      }
    }
  }
  
  return 0;
}