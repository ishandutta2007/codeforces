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

const int MAX_N = 128;

ll n, m, k;

ll a[MAX_N][MAX_N];
ll core_locked[MAX_N];
bool memory_locked[MAX_N];

bool used[MAX_N];

int main(){

  scanf( "%lld %lld %lld" , &n , &m , &k );
  REP( i , n ) REP( j , m ) scanf( "%lld" , &a[i][j] ), a[i][j]--;

  REP( j , m ){
    REP( i , k ) used[i] = memory_locked[i];
    REP( i , n ) if( core_locked[i] == 0 && a[i][j] != -1 ){
      if( used[ a[i][j] ] ) core_locked[i] = j+1, memory_locked[ a[i][j] ] = true;
      used[ a[i][j] ] = true;
    }
    REP( i , n ) if( core_locked[i] == 0 && a[i][j] != -1 && memory_locked[ a[i][j] ] ) core_locked[i] = j+1;
  }

  REP( i , n ) printf( "%lld\n" , core_locked[i] );
  
  return 0;
}