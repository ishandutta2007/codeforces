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

const int MAX_N = 5010;

int n;
int a[MAX_N];

int res[3];
vi ans[3];

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );

  while( 1 ){
    int cnt = 0;
    REP( i , 3 ) REP( j , n ) if( a[j] == i+1 ){
      res[i] = j;
      a[j] = 0;
      cnt++;
      break;
    }
    if( cnt < 3 ) break;
    REP( i , 3 ) ans[i].pb( res[i]+1 );
  }

  int m = ans[0].size();
  if( m == 0 ) return puts( "0" );

  printf( "%d\n" , m );
  REP( i , m ) printf( "%d %d %d\n" , ans[0][i] , ans[1][i] , ans[2][i] );
  
  return 0;
}