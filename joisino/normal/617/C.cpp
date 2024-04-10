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

const int MAX_N = 2010;

int n;
ll xa, ya, xb, yb;

ll x[MAX_N], y[MAX_N];

bool used[MAX_N];

ll norma( int i ){ return (x[i]-xa)*(x[i]-xa) + (y[i]-ya)*(y[i]-ya); }
ll normb( int i ){ return (x[i]-xb)*(x[i]-xb) + (y[i]-yb)*(y[i]-yb); }

int main(){
  
  scanf( "%d %lld %lld %lld %lld" , &n , &xa , &ya , &xb , &yb );
  REP( i , n ) scanf( "%lld %lld" , &x[i] , &y[i] );

  ll ans = INFLL;
  REP( i , n+1 ){
    ll rr = i==n?0:norma( i );
    REP( j , n ) used[j] = norma(j) <= rr;
    ll ss = 0;
    REP( j , n ) if( !used[j] ) chmax( ss , normb(j) );
    chmin( ans , rr + ss );
  }

  printf( "%lld\n" , ans );
  
  return 0;
}