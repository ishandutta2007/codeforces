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

int n, k;
int c[500010];

int a, b;

ll sum = 0;

bool checkub( int x ){
  int res = k;
  REP( i , n ){
    if( c[i] > x ){
      res -= c[i] - x;
    }
    if( res < 0 ){
      return false;
    }
  }
  return true;
}

bool checklb( int x ){
  int res = k;
  REP( i , n ){
    if( c[i] < x ){
      res -= x - c[i];
    }
    if( res < 0 ){
      return false;
    }
  }
  return true;
}

int main(){

  n = in();
  k = in();
  REP( i , n ){
    c[i] = in();
    sum += c[i];
  }

  int lb = 0, ub = INF;
  while( ub - lb > 1 ){
    int md = ( lb + ub ) / 2;
    if( checkub( md ) ){
      ub = md;
    } else {
      lb = md;
    }
  }
  b = ub;

  lb = 0, ub = INF;
  while( ub - lb > 1 ){
    int md = ( lb + ub ) / 2;
    if( checklb( md ) ){
      lb = md;
    } else {
      ub = md;
    }
  }
  a = lb;

  int ans = b - a;
  if( ans <= 0 ){
    if( sum % n == 0 ){
      ans = 0;
    } else {
      ans = 1;
    }
  }

  printf( "%d\n" , ans );
  
  return 0;
}