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

const int MAX_N = 500010;

ld dp[MAX_N];
ld sub;

ld ans;

char s[MAX_N];

bool is_vowel( char c ){
  return c == 'I' || c == 'E' || c == 'A' || c == 'O' || c == 'U' || c == 'Y';
}

int main(){

  scanf( "%s" , s );
  int n = strlen( s );

  REP( i , n ) sub += 1.0 / (ld)( i + 1 );
  dp[0] = sub;
  REP( i , (n-1)/2 ){
    sub -= 1.0 / (ld)( i + 1 );
    sub -= 1.0 / (ld)( n - i );
    dp[i+1] = dp[i] + sub;
  }

  REP( i , n ) if( is_vowel( s[i] ) ) ans += dp[min(i,n-1-i)];

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}