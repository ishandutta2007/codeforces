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

const ll MAX_N = 4010;
const ll MAX_S = 100010;

ll n, m, k, s;

ll a[MAX_N][MAX_N];
ll b[MAX_S];

ll to[72], bo[72], ri[72], le[72];
ll dist[72][72];

ll ans;

int main(){

  scanf( "%lld %lld %lld %lld" , &n , &m , &k , &s );
  REP( i , n ) REP( j , m ) scanf( "%lld" , &a[i+j][i-j+m-1] );
  REP( i , s ) scanf( "%lld" , &b[i] );
  
  REP( i , k+1 ) to[i] = le[i] = INFLL, bo[i] = ri[i] = -INFLL;
  REP( i , n+m ) REP( j , n+m ){
    chmin( to[ a[i][j] ] , i );
    chmax( bo[ a[i][j] ] , i );
    chmin( le[ a[i][j] ] , j );
    chmax( ri[ a[i][j] ] , j );
  }

  REP( i , k+1 ) REP( j , k+1 ){
    chmax( dist[i][j] , bo[i] - to[j] );
    chmax( dist[i][j] , bo[j] - to[i] );
    chmax( dist[i][j] , ri[i] - le[j] );
    chmax( dist[i][j] , ri[j] - le[i] );
  }

  REP( i , s-1 ) chmax( ans , dist[ b[i] ][ b[i+1] ] );

  printf( "%lld\n" , ans );
  
  return 0;
}