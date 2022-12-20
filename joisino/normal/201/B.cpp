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

const int MAX_N = 1010;

int n, m;
ll c[MAX_N][MAX_N];

ll sumc, sumcx, sumcy;

ll ans;
int ansx, ansy;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) REP( j , m ) scanf( "%lld" , &c[i][j] );

  REP( i , n ) REP( j , m ) sumc += c[i][j];
  REP( i , n ) REP( j , m ) sumcx += c[i][j] * (ll)( j * 4 + 2 );
  REP( i , n ) REP( j , m ) sumcy += c[i][j] * (ll)( i * 4 + 2 );

  ll df = 16 * sumc - 8 * sumcx;
  while( df < 0 ){
    ansx++;
    df += 32 * sumc;
  }

  df = 16 * sumc - 8 * sumcy;
  while( df < 0 ){
    ansy++;
    df += 32 * sumc;
  }

  REP( i , n ) REP( j , m ) ans += ( ( 4 * i + 2 - ansy * 4 ) * ( 4 * i + 2 - ansy * 4 ) + ( 4 * j + 2 - ansx * 4 ) * ( 4 * j + 2 - ansx * 4 ) ) * c[i][j];

  printf( "%lld\n" , ans );
  printf( "%d %d\n" , ansy , ansx );
  
  return 0;
}