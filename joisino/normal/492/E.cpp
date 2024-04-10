#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1000010;

int n, m, dx, dy;
int x[MAX_N], y[MAX_N];

int a, b;
int xp[MAX_N];

int res[MAX_N];
int ans;

int main(){

  scanf( "%d %d %d %d" , &n , &m , &dx , &dy );
  REP( i , m ) scanf( "%d %d" , &x[i] , &y[i] );

  REP( i , n+1 ){
    xp[b] = a;
    a = ( a + dx ) % n;
    b = ( b + dy ) % n;
  }

  REP( i , m )
    res[ ( x[i] - xp[y[i]] + n ) % n ]++;

  REP( i , n ) if( res[i] > res[ans] ) ans = i;

  printf( "%d %d\n" , ans , 0 );
  
  return 0;
}