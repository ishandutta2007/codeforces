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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head

const int MAX_N = 128;

int n;
int x[MAX_N], y[MAX_N], z[MAX_N];

double ansx, ansy, ansz;
double ansv = INF;

double calc( ld cx, ld cy, ld cz ){
  ld res = 0;
  REP( i , n ) chmax( res, sq(cx-x[i]) + sq(cy-y[i]) + sq(cz-z[i]) );
  if( res < ansv ){
    ansv = res;
    ansx = cx, ansy = cy, ansz = cz;
  }
  return res;
}

double getx( ld cy, ld cz ){
  double lb = -1e5, ub = 1e5;
  REP( i , 60 ){
    double mda = ( lb*2 + ub ) / 3;
    double mdb = ( lb + ub*2 ) / 3;
    // cout << mda << " " << calc( mda, cy, cz ) << ", " << mdb << " " << calc( mdb, cy, cz ) << endl;
    if( calc( mda, cy, cz ) < calc( mdb, cy, cz ) ) ub = mdb;
    else lb = mda;
  }
  return calc( lb, cy, cz );
}

double gety( ld cz ){
  double lb = -1e5, ub = 1e5;
  REP( i , 60 ){
    double mda = ( lb*2 + ub ) / 3;
    double mdb = ( lb + ub*2 ) / 3;
    if( getx( mda, cz ) < getx( mdb, cz ) ) ub = mdb;
    else lb = mda;
  }
  return getx( lb, cz );
}

double getz(){
  double lb = -1e5, ub = 1e5;
  REP( i , 60 ){
    double mda = ( lb*2 + ub ) / 3;
    double mdb = ( lb + ub*2 ) / 3;
    if( gety( mda ) < gety( mdb ) ) ub = mdb;
    else lb = mda;
  }
  return gety( lb );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d %d %d", &x[i], &y[i], &z[i] );
  
  getz();
  printf( "%.18lf %.18lf %.18lf\n", ansx, ansy, ansz );

  return 0;
}