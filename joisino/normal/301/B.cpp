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

const int MAX_N = 128;

int n, d;
int a[MAX_N];
int x[MAX_N], y[MAX_N];

int dist[MAX_N];

bool check( int md ){
  REP( i , n ) dist[i] = -INF;
  dist[0] = md;
  
  REP( loop_cnt , n ){
    REP( i , n ) REP( j , n ) if( i != j ){
      int t = abs(x[i]-x[j]) + abs(y[i]-y[j]);
      if( dist[i] >= t*d ) chmax( dist[j] , dist[i]-t*d+a[j] );
    }
  }
  
  return dist[n-1] >= 0;
}

int main(){

  scanf( "%d %d" , &n , &d );
  FOR( i , 1 , n-1 ) scanf( "%d" , &a[i] );
  REP( i , n ) scanf( "%d %d" , &x[i] , &y[i] );

  int lb = -1, ub = INF;
  while( ub - lb > 1 ){
    int md = ( lb + ub ) / 2;
    if( check( md ) ) ub = md;
    else lb = md;
  }

  printf( "%d\n" , ub );
  
  return 0;
}