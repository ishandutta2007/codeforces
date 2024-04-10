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

const ll MAX_N = 200010;

ll n, m, s, g;
ll t[MAX_N], l[MAX_N], r[MAX_N];

int main(){

  scanf( "%lld %lld %lld %lld" , &n , &m , &s , &g );
  REP( i , m ) scanf( "%lld %lld %lld" , &t[i] , &l[i] , &r[i] );

  ll p = 0, c = 0;
  while( s != g ){
    c++;
    ll to = ( s < g ? s + 1 : s - 1 );
    if( p < m && c == t[p] ){
      if( ( l[p] <= s && s <= r[p] ) || ( l[p] <= to && to <= r[p] ) ){
	p++;
	printf( "X" );
	continue;
      } else {
	p++;
      }
    }
    
    if( s < to ) printf( "R" );
    else printf( "L" );

    s = to;
  }

  printf( "\n" );
  
  return 0;
}