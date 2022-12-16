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


const int MAX_N = 512;

int n, m, r;
int a[MAX_N][MAX_N];
int rsum[MAX_N][MAX_N];

int sum[MAX_N][MAX_N];

int lmax[MAX_N][MAX_N], rmax[MAX_N][MAX_N];
int lcnt[MAX_N][MAX_N], rcnt[MAX_N][MAX_N];

bool intersect[MAX_N][MAX_N];

int ans;
ll comb;

int sq( int x ){ return x * x; }

inline void update( int res , int cnt ){
  if( ans < res ){
    ans = res;
    comb = cnt;
  } else if( ans == res ){
    comb += cnt;
  }
}

inline void calc_pair( int y , int x ){
  int p = 0, res, q;
  FOR( i , r , y+1 ){
    while( p < m-2*r && intersect[abs(y-i)][p] ) p++;
    if( x-p >= r ){
      res = sum[y][x] + lmax[i][x-p+1]; 
      if( res >= ans ) update( res , lcnt[i][x-p+1] );
    }
    if( x+p < m-r ){
      q = x + (p==0?1:p);
      res = sum[y][x] + rmax[i][q];
      if( res >= ans ) update( res , rcnt[i][q] );
    }
  }
  
  p = 0;
  for( int i = n-1-r; i > y; i-- ){
    while( p < m-2*r && intersect[abs(y-i)][p] ) p++;
    if( x-p >= r ){
      res = sum[y][x] + lmax[i][x-p+1]; 
      if( res >= ans ) update( res , lcnt[i][x-p+1] );
    }
    if( x+p < m-r ){
      q = x + (p==0?1:p);
      res = sum[y][x] + rmax[i][q];
      if( res >= ans ) update( res , rcnt[i][q] );
    }
  }
  
}

void calc_sum( int y , int x ){
  int res = 0;

  int p = 0;
  FOR( i , y-r , y+1 ){
    while( sq(y-i)+sq(p+1) <= sq(r) ) p++;
    res += rsum[i][x+p+1] - rsum[i][x-p];
  }

  p = 0;
  for( int i = y+r; i > y; i-- ){
    while( sq(y-i)+sq(p+1) <= sq(r) ) p++;
    res += rsum[i][x+p+1] - rsum[i][x-p];
  }

  sum[y][x] = res;
}

void calc_intersection(){
  REP( y , n-2*r ) REP( x , m-2*r ){
    int p = 0;
    FOR( i , y-r , y+1 ){
      while( sq(y-i)+sq(p+1) <= sq(r) ) p++;
      if( sq(i)+sq(x-p) <= sq(r) ) intersect[y][x] = true;
    }
  }
}

void calc_max(){
  FOR( i , r , n-r ) FOR( j , r , m-r ){
    if( lmax[i][j] < sum[i][j] ){
      lmax[i][j+1] = sum[i][j];
      lcnt[i][j+1] = 1;
    } else if( lmax[i][j] == sum[i][j] ){
      lmax[i][j+1] = lmax[i][j];
      lcnt[i][j+1] = lcnt[i][j] + 1;
    } else if( lmax[i][j] > sum[i][j] ){
      lmax[i][j+1] = lmax[i][j];
      lcnt[i][j+1] = lcnt[i][j];
    }
  }
  
  FOR( i , r , n-r ) for( int j = m-r-1; j >= r; j-- ){
    if( rmax[i][j+1] < sum[i][j] ){
      rmax[i][j] = sum[i][j];
      rcnt[i][j] = 1;
    } else if( rmax[i][j+1] == sum[i][j] ){
      rmax[i][j] = rmax[i][j+1];
      rcnt[i][j] = rcnt[i][j+1] + 1;
    } else if( rmax[i][j+1] > sum[i][j] ){
      rmax[i][j] = rmax[i][j+1];
      rcnt[i][j] = rcnt[i][j+1];
    }
  }
}

int main(){

  scanf( "%d %d %d" , &n , &m , &r );
  REP( i , n ) REP( j , m ) scanf( "%d" , &a[i][j] );

  REP( i , n ) REP( j , m ) rsum[i][j+1] = rsum[i][j] + a[i][j];

  FOR( i , r , n-r ) FOR( j , r , m-r ) calc_sum( i , j );
  
  calc_max();

  calc_intersection();

  FOR( i , r , n-r ) FOR( j , r , m-r ) calc_pair( i , j );

  printf( "%d %lld\n" , ans , comb/2 );
  
  return 0;
}