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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 512;

struct par{
  int in, out, w, s, v;
  par(){}
  par( int in , int out , int w , int s , int v ) : in(in) , out(out) , w(w) , s(s) , v(v) {}
  bool operator <( const par& a ) const{
    if( a.out != out ) return out < a.out;
    if( a.in != in ) return in > a.in;
  }
};

int n, s;
par p[MAX_N];

int dp[MAX_N][MAX_N*2];
int ans;

int main(){

  scanf( "%d %d" , &n , &s );
  REP( i , n ) scanf( "%d %d %d %d %d" , &p[i].in , &p[i].out , &p[i].w , &p[i].s , &p[i].v );
  p[n++] = par( 0 , 2*n , 0 , s , 0 );
  
  sort( p , p+n );

  REP( i , n ) REP( j , p[i].s + 1 ){
    vi d( MAX_N*2 , 0 );
    int q = 1;
    REP( k , i ) if( p[i].in <= p[k].in && p[k].w <= j ){
      int r = min( j - p[k].w , p[k].s );
      while( q <= p[k].in ){ chmax( d[q] , d[q-1] ); q++; }
      chmax( d[ p[k].out ] , d[ p[k].in ] + dp[k][r] );
    }
    while( q < MAX_N*2 ){ chmax( d[q] , d[q-1] ); q++; }
    dp[i][j] = d[q-1] + p[i].v;
  }

  REP( i , s+1 ) chmax( ans , dp[n-1][i] );

  cout << ans << endl;

  return 0;
}