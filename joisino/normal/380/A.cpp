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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;
typedef vector<vl> ml;

const int INF = 1e9;
const ll INFLL = 1e18;
const ld EPS = 1e-8;
const ld EPSLD = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_L = 100010;

int n, m;
vl a;
vpl v;
vl sum(1,0);
ll t, x, y;

int main(){

  scanf( "%d" , &m );
  REP( i , m ){
    scanf( "%lld %lld" , &t , &x );
    if( t == 1 ){
      v.pb( 0 , x );
      sum.pb( sum.back()+1 );
      if( a.size() <= MAX_L ) a.pb( x );
    } else {
      scanf( "%lld" , &y );
      v.pb( x , y );
      sum.pb( sum.back() + x*y );
      while( a.size() <= MAX_L && y-- )	REP( i , x ) a.pb( a[i] );
    }
  }

  scanf( "%d" , &n );
  REP( i , n ){
    if( i != 0 ) printf( " " );
    scanf( "%lld" , &x );
    int p = lower_bound( ALL(sum) , x ) - sum.begin(); p--;
    if( v[p].fi == 0 ) printf( "%lld" , v[p].se );
    else{
      int q = x - sum[p] - 1;
      //cerr << i << " " << q << endl;
      printf( "%lld" , a[q%v[p].fi] );
    }
  }
  printf( "\n" );

  return 0;
}