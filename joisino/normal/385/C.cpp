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

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ll MAX_N = 10000010;

ll ps[MAX_N];

ll n, m;
ll l, r, x;

ll sum[MAX_N];

int main(){

  FOR( i , 2 , MAX_N ){
    if( ps[i] == 0 ) for( ll j = i; j < MAX_N; j += i ) ps[j] = i;
  }
  
  scanf( "%lld" , &n );
  REP( i , n ){
    scanf( "%lld" , &x );
    while( x > 1 ){
      ll p = ps[x];
      sum[p]++;
      while( x % p== 0 ) x /= p;
    }
  }

  FOR( i , 1 , MAX_N ) sum[i] += sum[i-1];

  scanf( "%lld" , &m );
  REP( i , m ){
    scanf( "%lld %lld" , &l , &r );
    chmin( l , MAX_N-1 ); chmin( r , MAX_N-1 );
    printf( "%lld\n" , sum[r] - sum[l-1] );
  }

  return 0;
}