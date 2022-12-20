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

const int MAX_N = 500010;

int n, m;

char cs[MAX_N];
string s[MAX_N];

int cnt;
int mo = 1000003;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ){
    scanf( "%s" , cs );
    s[i] = cs;
  }

  REP( i , n ){
    int cur = -1;
    REP( j , m ){
      if( s[i][j] == '.' ) continue;
      int x = ( s[i][j] - '1' ) / 2;
      if( cur == -1 ) cur = x + j;
      else if( cur % 2 != ( x + j ) % 2 ){
	cur = -INF;
	break;
      }
    }
    if( cur == -1 ) cnt++;
    if( cur == -INF ){
      printf( "0\n" );
      return 0;
    }
  }

  REP( j , m ){
    int cur = -1;
    REP( i , n ){
      if( s[i][j] == '.' ) continue;
      int x = ( s[i][j] == '1' || s[i][j] == '4' ) ? 0 : 1;
      if( cur == -1 ) cur = x + i;
      else if( cur % 2 != ( x + i ) % 2 ){
	cur = -INF;
	break;
      }
    }
    if( cur == -1 ) cnt++;
    if( cur == -INF ){
      printf( "0\n" );
      return 0;
    }
  }

  int ans = 1;
  REP( i , cnt ) ans = ( ans * 2 ) % mo;

  printf( "%d\n" , ans );
  
  return 0;
}