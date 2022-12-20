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

const int MAX_N = 2048;

int n;
int a[MAX_N], b[MAX_N], posb[MAX_N], c[MAX_N];

ll ansv;
vpi ans;

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] ), a[i]--;
  REP( i , n ){
    scanf( "%d" , &b[i] ); b[i]--;
    posb[ b[i] ] = i;
  }
  REP( i , n ) c[i] = posb[ a[i] ];

  while( 1 ){
    int p = 0;
    while( p < n && c[p] >= p ) p++;
    if( p == n ) break;
    while( 1 ){
      int curp = p;
      p--;
      while( c[p] == p && p != c[curp] ) p--;
      ans.pb( p , curp );
      ansv += curp - p;
      swap( c[p] , c[curp] );
      if( p == c[p] ) break;
    }
  }

  printf( "%lld\n" , ansv );
  printf( "%d\n" , (int)ans.size() );
  YYS( w , ans ) printf( "%d %d\n" , w.fi+1 , w.se+1 );
  
  return 0;
}