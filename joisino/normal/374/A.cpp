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

ll n, m, i, j, a, b;
ll ans = INFLL;

ll go( ll h , ll w ){
  if( h % a == 0 && w % b == 0 ){
    ll maxv = max( h/a , w/b );
    ll minv = min( h/a , w/b );
    if( maxv == minv ) return maxv;
    if( n <= a || m <= b ) return INFLL;
    if( ( maxv - minv ) % 2 == 0 ) return maxv;
  }
  return INFLL;
}

int main(){

  scanf( "%lld %lld %lld %lld %lld %lld" , &n , &m , &i , &j , &a , &b );

  chmin( ans , go( i-1 , j-1 ) );
  chmin( ans , go( i-1 , m-j ) );
  chmin( ans , go( n-i , j-1 ) );
  chmin( ans , go( n-i , m-j ) );

  if( ans == INFLL ) printf( "Poor Inna and pony!\n" );
  else printf( "%lld\n" , ans );
  
  return 0;
}