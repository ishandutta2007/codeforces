#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }

double sx, sy, gx, gy;
double v, t;

double dirx, diry;
double edirx, ediry;

double dist;

double wvx[2], wvy[2];

double vel[2];

double len( double ax , double ay ){
  return sqrt( ax * ax + ay * ay );
}

double eval( double md , int ind ){
  double vx = cos( md ) * v;
  double vy = sin( md ) * v;
  double svx = vx + wvx[ind];
  double svy = vy + wvy[ind];
  double lensv = len( svx , svy );
  svx /= lensv;
  svy /= lensv;
  double resx = svx - edirx;
  double resy = svy - ediry;
  return len( resx , resy );
}

const double PI = 3.14159265358979323846;

double sanbun( int ind ){
  double lb = atan2( ediry , edirx ) - PI / 2 , ub = atan2( ediry , edirx ) + PI / 2;
  REP( loop , 100 ){
    double md1 = ( lb * 2 + ub ) / 3;
    double md2 = ( lb + ub * 2 ) / 3;
    if( eval( md1 , ind ) > eval( md2 , ind ) ) lb = md1;
    else ub = md2;
  }
  return lb;
}

int main(){

  cin >> sx >> sy >> gx >> gy;

  dirx = gx - sx;
  diry = gy - sy;

  dist = len( dirx , diry );

  edirx = dirx / dist;
  ediry = diry / dist;

  cin >> v >> t;

  REP( i , 2 )
    cin >> wvx[i] >> wvy[i];

  double lb = 0.0, ub = INFLL;
  REP( loop , 1000 ){
    double md = ( lb + ub ) / 2;
    double ngx = gx, ngy = gy; 
    if( md > t ){
      ngx -= wvx[0] * t;
      ngy -= wvy[0] * t;
      ngx -= wvx[1] * ( md - t );
      ngy -= wvy[1] * ( md - t );
    } else {
      ngx -= wvx[0] * md;
      ngy -= wvy[0] * md;
    }
    dist = len( ngx - sx , ngy - sy );
    if( dist < v * md ) ub = md;
    else lb = md;
  }

  cout << setprecision( 16 ) << lb << endl;
  
  return 0;
}