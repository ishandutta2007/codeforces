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
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

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
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n, a, b, t;

string s;

int mov( int l , int r ){
  int x = n - l;
  int y = r - 1;
  return ( min( x , y ) * 2 + max( x , y ) ) * a;
}

int main(){

  n = in();
  a = in();
  b = in();
  t = in();

  s = stin();

  int cur = 0;
  if( s[0] == 'w' ){
    cur = b + 1;
  } else if( s[0] == 'h' ){
    cur = 1;
  }

  if( t < cur ){
    puts( "0" );
    return 0;
  }

  int all = cur;
  FOR( i , 1 , n ){
    if( s[i] == 'w' ){
      all += a + b + 1;
    } else if( s[i] == 'h' ){
      all += a + 1;
    }
  }

  if( t >= all ){
    printf( "%d\n" , n );
    return 0;
  }

  int r = 1;
  while( 1 ){
    int nex = cur;
    if( s[r] == 'w' ){
      nex += b + 1;
    } else if( s[r] == 'h' ){
      nex += 1;
    }
    if( t < nex + mov( n , r+1 ) ){
      break;
    }
    r++;
    cur = nex;
    assert( t >= cur + mov( n , r ) );
    // cout << n << " " << r << " " << cur << " " << mov( n , r ) << endl;
  }

  int ans = r;

  // cout << r << endl;

  for( int l = n-1; l >= 0; l-- ){
    int nex = cur;
    if( s[l] == 'w' ){
      nex += b + 1;
    } else if( s[l] == 'h' ){
      nex += 1;
    }
    while( r > 0 && t < nex + mov( l , r ) ){
      r--;
      if( s[r] == 'w' ){
        nex -= b + 1;
      } else if( s[r] == 'h' ){
        nex -= 1;
      }
    }
    if( r == 0 ){
      break;
    }
    chmax( ans , ( n - l ) + r );
    cur = nex;
    // cout << l << " " << r << " " << cur << " " << mov( l , r ) << endl;
    assert( t >= cur + mov( l , r ) );
  }

  printf( "%d\n" , ans );
  
  return 0;
}