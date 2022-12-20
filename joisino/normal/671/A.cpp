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
#define SHOW(x) cout << #x << " = " << x << endl
 
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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

typedef pair<ld,int> st;

ld dist( ld ax , ld ay , ld bx , ld by ){
  return sqrtl( sq(ax-bx) + sq(ay-by) );
}

ld ax, ay;
ld bx, by;
ld cx, cy;

ld x[100010];
ld y[100010];

int n;

ld ad[100010];
ld bd[100010];
ld cd[100010];

vector<st> ads, bds;

int main(){

  ax = in();
  ay = in();
  bx = in();
  by = in();
  cx = in();
  cy = in();

  n = in();
  REP( i , n ){
    x[i] = in();
    y[i] = in();
  }

  ld sum = 0;
  REP( i , n ){
    ad[i] = dist( ax , ay , x[i] , y[i] );
    bd[i] = dist( bx , by , x[i] , y[i] );
    cd[i] = dist( cx , cy , x[i] , y[i] );

    ads.pb( ad[i] - cd[i] , i );
    bds.pb( bd[i] - cd[i] , i );

    sum += cd[i] * 2;
  }

  SORT( ads );
  SORT( bds );

  ld ans = min( sum + ads[0].fi , sum + bds[0].fi );

  if( ads[0].se != bds[0].se ){
    chmin( ans , sum + ads[0].fi + bds[0].fi );
  } else if( n >= 2 ){
    chmin( ans , sum + ads[0].fi + bds[1].fi );
    chmin( ans , sum + ads[1].fi + bds[0].fi );
  }

  printf( "%.18lf\n" , (double)ans );
  
  return 0;
}