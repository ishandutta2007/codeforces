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
const ld EPS = 1e-10;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

template<class T> inline T sq( T a ){ return a * a; }

// head

const int MAX_N = 18;

ll ans = INF;

ll ones[MAX_N];

void dfs( ll x , ll d , ll c ){
  if( c >= ans ) return;
  if( x == 0 ){
    chmin( ans , c );
    return;
  }
  if( d == 0 ) return;
  ll ne = x;
  while( ne - ones[d] >= 0 ) ne -= ones[d], c += d;
  dfs( ne , d-1 , c );
  dfs( ones[d] - ne , d-1 , c+d );
}

ll n;

int main(){

  scanf( "%lld" , &n );

  REP( i , MAX_N ){
    REP( j , i ) ones[i] = ones[i] * 10 + 1;
  }

  dfs( n , MAX_N-1 , 0 );

  printf( "%lld\n" , ans );
  
  return 0;
}