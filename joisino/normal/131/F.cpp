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

const int MAX_N = 512;
const int dx[] = { 1 , 0 , -1 , 0 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 , 0 };

int n, m, k;
char a[MAX_N][MAX_N];
int sum[MAX_N][MAX_N];

ll ans;

int check( int y , int x ){
  REP( i , 5 ) if( a[ y + dy[i] ][ x + dx[i] ] == '0' ) return 0;
  return 1;
}

int main(){

  scanf( "%d %d %d" , &n , &m , &k );
  REP( i , n ) scanf( "%s" , a[i] );
  FOR( i , 1 , n-1 ) FOR( j , 1 , m-1 ) sum[i][j] = sum[i][j-1] + check( i , j );

  REP( i , m ) FOR( j , i+2 , m ){
    int t = 0;
    int cur = 0;
    REP( s , n ){
      while( t < n && cur < k ){
	if( s <= t-1 ) cur += sum[t-1][j-1] - sum[t-1][i];
	t++;
      }
      if( cur >= k ) ans += n - t + 1;
      if( s+1 < t ) cur -= sum[s+1][j-1] - sum[s+1][i];
    }
  }

  printf( "%lld\n" , ans );
  
  return 0;
}