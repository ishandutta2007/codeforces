#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int n[2];
int k;
vi v;
vi a[2];

int cnt[2];
int p[2];

int main(){
  
  scanf( "%d %d %d" , &n[0] , &n[1] , &k );
  REP( l , 2 ) a[l].resize( n[l] );
  REP( l , 2 ) REP( i , n[l] ) scanf( "%d" , &a[l][i] );
  REP( l , 2 ) YYS( w , a[l] ) v.pb( w );
  REP( l , 2 ) { SORT( a[l] ); REVERSE( a[l] ); }
  SORT( v ); REVERSE( v ); v.erase( unique( ALL(v) ) , v.end() );

  YYS( w , v ){
    REP( l , 2 ) while( p[l] < n[l] && a[l][p[l]] == w ) p[l]++, cnt[l]++;
    if( cnt[0] > cnt[1] ) return puts( "YES" );
    // cout << w << " " << cnt[0] << " " << cnt[1] << endl; 
  }

  puts( "NO" );
  
  return 0;
}