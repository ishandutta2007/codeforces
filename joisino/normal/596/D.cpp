#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 2048;

int n, h;
double p;

int x[MAX_N];
int fl[MAX_N], fr[MAX_N];

double memo[MAX_N][MAX_N][2][2];
bool used[MAX_N][MAX_N][2][2];

double rec( int l , int r , int dl , int dr ){
  if( r < l ) return 0;

  if( used[l][r][dl][dr] ) return memo[l][r][dl][dr];
  used[l][r][dl][dr] = true;

  double res = 0, add = 0;
  
  // select left, fall left
  if( dl == 0 ) add = x[l] - max( x[l-1]      , x[l] - h );
  if( dl == 1 ) add = x[l] - max( x[l-1] + h  , x[l] - h );

  res += 0.5 * p * ( rec( l+1 , r , 0 , dr ) + add );
  
  // select left, fall right
  if( fr[l] >= r ){
    if( dr == 0 ) add = min( x[r] + h , x[r+1] - h ) - x[l];
    if( dr == 1 ) add = min( x[r] + h , x[r+1]     ) - x[l];
    res += 0.5 * ( 1 - p ) * add;
  } else {
    add = x[ fr[l] ] + h - x[l];

    res += 0.5 * ( 1 - p ) * ( rec( fr[l]+1 , r , 1 , dr ) + add );
  }
  
  // select right, fall left
  if( fl[r] <= l ){
    if( dl == 0 ) add = x[r] - max( x[l-1]     , x[l] - h );
    if( dl == 1 ) add = x[r] - max( x[l-1] + h , x[l] - h );
    res += 0.5 * p * add;
  } else {
    add = x[r] - ( x[ fl[r] ] - h );
  
    res += 0.5 * p * ( rec( l , fl[r]-1 , dl , 0 ) + add );
  }

  // select right, fall right
  if( dr == 0 ) add = min( x[r] + h , x[r+1] - h ) - x[r];
  if( dr == 1 ) add = min( x[r] + h , x[r+1]     ) - x[r];

  res += 0.5 * ( 1 - p ) * ( rec( l , r-1 , dl , 1 ) + add );
  
  return memo[l][r][dl][dr] = res;
}

int main(){

  scanf( "%d %d %lf" , &n , &h , &p );
  REP( i , n ) scanf( "%d" , &x[i] );
  x[n] = -INF; x[n+1] = INF; n += 2;
  sort( x , x+n );

  FOR( i , 1 , n-1 ){
    if( x[i-1] > x[i]-h ) fl[i] = fl[i-1];
    else fl[i] = i;
  }
  
  for( int i = n-2; i >= 1; i-- ){
    if( x[i+1] < x[i]+h ) fr[i] = fr[i+1];
    else fr[i] = i;
  }
  
  printf( "%.18lf\n" , rec( 1 , n-2 , 0 , 0 ) );
  
  return 0;
}