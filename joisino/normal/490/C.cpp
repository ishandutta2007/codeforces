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

const int MAX_N = 1000010;

char s[MAX_N];

ll a, b;

ll base[MAX_N];

ll le = 0;
ll ri[MAX_N];

int main(){

  scanf( "%s" , s );
  int n = strlen( s );
  scanf( "%lld %lld" , &a , &b );

  base[0] = 1;
  FOR( i , 1 , MAX_N ) base[i] = ( base[i-1] * 10 ) % b;
  
  for( int i = n-1; i >= 0; i-- ) ri[i] = ( ri[i+1] + ( s[i] - '0' ) * base[n-i-1] ) % b;

  REP( i , n-1 ){
    le = ( le * 10 + ( s[i] - '0' ) ) % a;
    if( le % a == 0 && ri[i+1] % b == 0 && s[0] != '0' && s[i+1] != '0' ){
      printf( "YES\n" );
      REP( j , i+1 ) printf( "%c" , s[j] );
      printf( "\n" );
      FOR( j , i+1 , n ) printf( "%c" , s[j] );
      printf( "\n" );
      return 0;
    }
  }
    
  puts( "NO" );
  
  return 0;
}