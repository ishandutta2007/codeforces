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
ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

int n;
int cnt;

char ask( int i , int j ){
  cnt++;
  cout << "? " << i + 1 << " " << j + 1 << endl;
  fflush( stdout );
  char x;
  cin >> x;
  return x;
}

vi bg( vi v ){
  vi b(0);
  REP( i , SZ(v)/2 ){
    char r = ask( v[i*2] , v[i*2+1] );
    if( r == '>' ){
      b.pb( v[i*2] );
    } else if( r == '<' ){
      b.pb( v[i*2+1] );
    } else {
      b.pb( v[i*2] );
    }
  }
  if( SZ(v) % 2 == 1 ){
    b.pb( v.back() );
  }
  return b;
}

vi sm( vi v ){
  vi s(0);
  REP( i , SZ(v)/2 ){
    char r = ask( v[i*2] , v[i*2+1] );
    if( r == '>' ){
      s.pb( v[i*2+1] );
    } else if( r == '<' ){
      s.pb( v[i*2] );
    } else {
      s.pb( v[i*2] );
    }
  }
  if( SZ(v) % 2 == 1 ){
    s.pb( v.back() );
  }
  return s;
}

void ans( int i , int j ){
  cout << "! " << i+1 << " " << j+1 << endl;
}

int f( int n ){
  return ( 3 * n + 1 ) / 2 - 2;
}

int nc = 1;

void solve(){
  cin >> n;
  cnt = 0;

  
  vi b, s;
  REP( i , n/2 ){
    char r = ask( i*2 , i*2+1 );
    if( r == '>' ){
      b.pb( i * 2 );
      s.pb( i * 2 + 1 );
    } else if( r == '<' ){
      s.pb( i * 2 );
      b.pb( i * 2 + 1 );
    } else {
      s.pb( i * 2 );
      b.pb( i * 2 );
    }
  }
  if( n % 2 == 1 ){
    b.pb( n-1 );
    s.pb( n-1 );
  }

  while( SZ(b) > 1 ){
    b = bg( b );
  }
  while( SZ(s) > 1 ){
    s = sm( s );
  }

  // cout << f(n) << " " << cnt << endl;
  
  assert( f(n) >= cnt );
  
  ans( s.back() , b.back() );
}

int main(){

  int t;
  cin >> t;
  while( t-- ){
    solve();
  }

  return 0;
}