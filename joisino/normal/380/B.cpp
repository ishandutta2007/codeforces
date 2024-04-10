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

const int MAX_N = 7272;

int n, m;

vi t, l, r, x;

int u[MAX_N], v[MAX_N];

int beki( int a ){
  int res = 0;
  while( a > 0 ){
    res++;
    a /= 2;
  }
  return res;
}

int main(){

  scanf( "%d %d" , &n , &m );
  REP( query_cnt , m ){
    int a, b, c, d, e;
    scanf( "%d" , &a );
    if( a == 1 ){
      scanf( "%d %d %d %d" , &b , &c , &d , &e );
      t.pb( b );
      l.pb( c );
      r.pb( d );
      x.pb( e );
    } else if( a == 2 ){
      scanf( "%d %d" , &b , &c );
      REP( i , MAX_N ){
	u[i] = 0;
	v[i] = -1;
      }
      u[b] = v[b] = c;
      FOR( i , b , n ){
	u[i+1] = u[i] + beki( u[i] - 1 );
	v[i+1] = v[i] + beki( v[i] );
      }
      vi ans;
      REP( i , t.size() ){
	int lv = t[i];
	if( u[lv] <= r[i] && l[i] <= v[lv] ) ans.pb( x[i] );
      }
      SORT( ans );
      UNIQUE( ans );
      printf( "%d\n" , (int)ans.size() );
    }
  }
  
  return 0;
}