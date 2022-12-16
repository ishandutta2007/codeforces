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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 1000010;

ll t1, t2, x1, x2, t0;

ld opt_temp_num = 1;
ld opt_temp_dom = 0;
ll max_v = 0;
int ansa = -1 , ansb = -1;

int main(){

  scanf( "%lld %lld %lld %lld %lld" , &t1 , &t2 , &x1 , &x2 , &t0 );

  if( t1 == t2 ){
    printf( "%lld %lld\n" , x1 , x2 );
    return 0;
  }
  
  ansa = 0;
  ansb = x2;
  max_v = x2;
  opt_temp_num = t2 * x2 - t0 * x2;
  opt_temp_dom = x2;
  
  FOR( i , 1 , x1+1 ){
    ll lb = -1, ub = x2;
    while( ub - lb > 1 ){
      ll md = ( lb + ub ) / 2;
      if( t0 * ( i + md ) <= t1 * i + t2 * md ) ub = md;
      else lb = md;
    }
    ll res_num = t1 * i + t2 * ub - t0 * ( i + ub );
    ll res_dom = i + ub;
    if( res_num < 0 ) continue;
    if( opt_temp_num * res_dom > res_num * opt_temp_dom ){
      opt_temp_num = res_num; 
      opt_temp_dom = res_dom;
      max_v = i + lb;
      ansa = i;
      ansb = ub;
    } else if( opt_temp_num * res_dom == res_num * opt_temp_dom && max_v < i + lb ){
      max_v = i + lb;
      ansa = i;
      ansb = ub;
    }
  }

  printf( "%d %d\n" , ansa , ansb );

  return 0;
}