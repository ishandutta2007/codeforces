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

const int MAX_N = 100010;

int n, k;

char s[MAX_N];
pair<int,char> cnt[7272];

bool use[7272];

int main(){

  REP( i , 26 ) cnt[i].se = 'a'+i;
  
  scanf( "%s" , s );
  scanf( "%d" , &k );

  n = strlen( s );
  REP( i , n ) cnt[ s[i] - 'a' ].fi++;

  sort( cnt , cnt+26 );
  reverse( cnt , cnt+26 );

  int res = n;
  int ans = 0;
  REP( i , 26 ){
    if( res <= k ) break;
    use[ cnt[i].se ] = true;
    ans++;
    res -= cnt[i].fi;
  }

  printf( "%d\n" , ans );
  REP( i , n ) if( use[ s[i] ] ) printf( "%c" , s[i] );
  printf( "\n" );
  
  return 0;
}