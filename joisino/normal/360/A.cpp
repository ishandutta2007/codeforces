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

const int MAX_N = 5010;

int n, m;
int t[MAX_N], l[MAX_N], r[MAX_N], x[MAX_N];

int a[MAX_N];
int ans[MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) a[i] = 5*1e8;
  REP( i , m ) scanf( "%d %d %d %d" , &t[i] , &l[i] , &r[i] , &x[i] );
  for( int i = m-1; i >= 0; i-- ){
    if( t[i] == 1 ) FOR( j , l[i]-1 , r[i] ) a[j] -= x[i];
    else FOR( j , l[i]-1 , r[i] ) chmin( a[j] , x[i] );
  }
  REP( i , n ) ans[i] = a[i];
  REP( i , m ){
    if( t[i] == 1 ) FOR( j , l[i]-1 , r[i] ) a[j] += x[i];
    else{
      int res = -INF;
      FOR( j , l[i]-1 , r[i] ) chmax( res , a[j] );
      if( res != x[i] ) return puts( "NO" );
    }
  }

  printf( "YES\n" );
  REP( i , n ) printf( "%d%c" , ans[i] , i==n-1?'\n':' ' );
  
  return 0;
}