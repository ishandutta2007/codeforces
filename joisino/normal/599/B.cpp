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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

int n, m;
int f[MAX_N], b[MAX_N];
int invf[MAX_N];

int ans[MAX_N];

bool impossible, ambiguity;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &f[i] );
  REP( i , m ) scanf( "%d" , &b[i] );

  REP( i , n ){
    if( invf[ f[i] ] == 0 ) invf[ f[i] ] = i+1;
    else invf[ f[i] ] = -1;
  }

  REP( i , m ){
    if( invf[ b[i] ] > 0 ) ans[i] = invf[ b[i] ];
    if( invf[ b[i] ] == 0 ) impossible = true;
    if( invf[ b[i] ] == -1 ) ambiguity = true;
  }

  if( impossible ) printf( "Impossible\n" );
  else if( ambiguity ) printf( "Ambiguity\n" );
  else{
    printf( "Possible\n" );
    REP( i , m ) printf( "%d%c" , ans[i] , i==n-1?'\n':' ' );
  }
  
  return 0;
}