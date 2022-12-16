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

const int MAX_N = 2010;

int n;
pi h[MAX_N];

vi v[3];
int p = 0;

int main(){

  cin >> n;
  REP( i , n ) cin >> h[i].fi;
  REP( i , n ) h[i].se = i+1;
  sort( h , h+n );

  REP( i , n ) v[0].pb( h[i].se );
  v[1] = v[2] = v[0];

  REP( i , n ){
    if( i > 0 && h[i-1].fi == h[i].fi && p < 2 ){
      swap( v[p][i-1] , v[p][i] );
      p++;
    }
  }

  if( p < 2 ) return puts( "NO" );
  puts( "YES" );
  REP( i , 3 ) REP( j , n ) printf( "%d%c" , v[i][j] , j==n-1?'\n':' ' );
  
  return 0;
}