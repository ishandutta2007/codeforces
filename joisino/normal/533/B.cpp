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

const int MAX_N = 200010;

int n;
vi G[MAX_N];
ll a[MAX_N];

ll ans = 0;

pl dfs( int x ){
  ll odd = -INFLL;
  ll eve = 0;
  YYS( w , G[x] ){
    pl res = dfs( w );
    ll oddres = max( odd + res.fi , eve + res.se );
    ll everes = max( eve + res.fi , odd + res.se );
    odd = oddres;
    eve = everes;
  }

  return pl( eve , max( eve + a[x] , odd ) );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    int x;
    scanf( "%d %lld" , &x , &a[i] ); x--;
    if( x >= 0 ) G[x].pb( i );
  }

  pl res = dfs( 0 );
  
  printf( "%lld\n" , max( res.fi , res.se ) );
  
  return 0;
}