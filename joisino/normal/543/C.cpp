#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
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

const int MAX_N = 32;

int dp[PW(21)];
vpi v[MAX_N];

int n, m;
char s[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%s" , s[i] );
  REP( i , n ) REP( j , m ) scanf( "%d" , &a[i][j] );

  REP( j , m ) REP( k , 26 ){
    char c = 'a' + k;
    vi ss;
    REP( i , n ) if( s[i][j] == c ) ss.pb( i );
    int sum = 0;
    int mask = 0;
    int maxv = 0;
    YYS( w , ss ){
      sum += a[w][j];
      chmax( maxv , a[w][j] );
      mask |= PW( w );
    }
    int co = sum - maxv;
    YYS( w , ss ){
      v[w].pb( PW(w) , a[w][j] );
      v[w].pb( mask , co );
    }
  }

  REP( i , PW(n) ) dp[i] = INF;
  dp[0] = 0;

  REP( i , PW(n)-1 ){
    int pos = 0;
    while( i & PW(pos) ) pos++;
    YYS( w , v[pos] ){
      chmin( dp[i|w.fi] , dp[i] + w.se );
    }
  }

  printf( "%d\n" , dp[PW(n)-1] );
  

  return 0;
}