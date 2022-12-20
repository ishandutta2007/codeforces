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

int n, m;
vl a, b;

vl v;

ll res[MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  a.resize( n );
  REP( i , n ) scanf( "%lld" , &a[i] );
  b.resize( m );
  REP( i , m ) scanf( "%lld" , &b[i] );  

  REP( i , n ) v.pb( a[i] );
  REP( i , m ) v.pb( b[i] );

  int si = v.size();
  SORT( v );

  SORT( a );
  ll p = 0;
  ll sum = 0;
  REP( i , si ){
    ll w = v[i];
    while( p < n && a[p] < w ){
      sum += a[p];
      p++;
    }
    res[i] = w * p - sum;
  }

  SORT( b );
  REVERSE( b );
  p = 0;
  sum = 0;
  for( int i = si-1; i >= 0; i-- ){
    ll w = v[i];
    while( p < m && b[p] > w ){
      sum += b[p];
      p++;
    }
    res[i] += sum - w * p;
  }

  ll ans = INFLL;
  REP( i , si ) chmin( ans , res[i] );

  printf( "%lld\n" , ans );
  
  return 0;
}