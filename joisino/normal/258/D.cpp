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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

int n, m;
int a[1024];
ld p[1024][1024];


int main(){

  scanf( "%d %d" , &n , &m );
  
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , n ) REP( j , n ) p[i][j] = ( a[i] > a[j] ? 1 : 0 );
  
  REP( qs , m ){
    int x, y;
    scanf( "%d %d" , &x , &y ); x--; y--;
    p[x][y] = p[y][x] = 0.5;
    REP( i , n ) if( i != x && i != y ){
      p[i][x] = p[i][y] = ( p[i][x] + p[i][y] ) / 2;
      p[x][i] = p[y][i] = ( p[x][i] + p[y][i] ) / 2;
    }
  }

  ld ans = 0;
  REP( i , n ) FOR( j , i+1 , n ) ans += p[i][j];

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}