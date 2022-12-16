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

int n, m;

bool used[100010];
int dep[100010];

vi G[100010];

bool ok = true;

void dfs( int x , int d ){
  dep[x] = d;
  used[x] = true;
  YYS( w , G[x] ){
    if( !used[w] ){
      dfs( w , 1 - d );
    } else if( dep[w] != 1 - d ){
      ok = false;
    }
  }
}

int main(){

  n = in();
  m = in();
  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
  }

  REP( i , n ){
    if( !used[i] ){
      dfs( i , 0 );
    }
  }
  
  if( !ok ){
    puts( "-1" );
    return 0;
  }

  vi a(0);
  vi b(0);

  REP( i , n ){
    if( dep[i] == 0 ){
      a.pb( i );
    } else if( dep[i] == 1 ){
      b.pb( i );
    } else {
      assert( false );
    }
  }

  printf( "%lld\n" , SZ(a) );
  REP( i , SZ(a) ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%d" , a[i]+1 );
  }
  printf( "\n" );

  printf( "%lld\n" , SZ(b) );
  REP( i , SZ(b) ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%d" , b[i]+1 );
  }
  printf( "\n" );
  
  return 0;
}