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

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 5010;

int n, m;
char a[MAX_N][MAX_N];
int b[MAX_N][MAX_N];
vi v[MAX_N];
int ans = 0;

int main(){

  scanf( "%d %d\n" , &n , &m );
  REP( i , n ) scanf( "%s\n" , a[i] );

  REP( i , n ) REP( j , m ) if( a[i][j] == '1' ) b[i][j] = 1;
  REP( i , n ) for( int j = m-1; j >= 0; j-- ) if( b[i][j] == 1 ) b[i][j] += b[i][j+1];
  REP( i , n ) REP( j , m ) v[j].pb( b[i][j] );
  REP( j , m ){ SORT( v[j] ); REVERSE( v[j] ); }
  
  REP( j , m ) REP( i , n ) chmax( ans , (i+1)*v[j][i] );

  printf( "%d\n" , ans );
  
  return 0;
}