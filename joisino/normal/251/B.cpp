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

int n, k;
vi p, q, s;

vi id(){
  vi res;
  REP( i , n ) res.pb( i );
  return res;
}

vi dot( vi a , vi b ){
  vi res = a;
  REP( i , n ) res[i] = a[b[i]];
  return res;
}

int main(){

  scanf( "%d %d" , &n , &k );
  p = q = s = vi(n);
  REP( i , n ) scanf( "%d" , &p[i] );
  REP( i , n ) p[i]--;
  REP( i , n ) scanf( "%d" , &s[i] );
  REP( i , n ) s[i]--;
  REP( i , n ) q[ p[i] ] = i;

  if( s == id() ) return puts( "NO" );

  REP( loop_cnt , 2 ){
    vi x = id();
    int cnt = 0;
    while( 1 ){
      cnt++;
      x = dot( x , p );
      if( x == s ) break;
      if( cnt > k ) break;
    }
    if( p == q ){
      if( cnt == 1 && k == 1 ) return puts( "YES" );
    } else if( cnt <= k && (k-cnt)%2 == 0 ) return puts( "YES" );
    swap( p , q );
  }
  
  return puts( "NO" );
  
  return 0;
}