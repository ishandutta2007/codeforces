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

bool G[512][512];
bool cGb[512][512];
vi cG[512];

int col[512];

int cnt = 0;
bool ng;

vi v[2];

void dfs( int x , int d ){
  col[x] = d;
  v[d].pb( x );
  YYS( w , cG[x] ){
    if( col[w] == -1 ){
      dfs( w , 1 - d );
    } else if( col[w] != 1 - d ){
      ng = true;
    }
  }
}

int main(){

  n = in();
  m = in();

  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;

    G[a][b] = true;
    G[b][a] = true;
  }

  REP( i , n ){
    REP( j , n ){
      if( i != j && !G[i][j] ){
        cG[i].pb( j );
        cGb[i][j] = true;
      }
    }
  }

  REP( i , n ){
    col[i] = -1;
  }

  REP( i , n ){
    if( col[i] == -1 && SZ(cG[i]) >= 1 ){
      dfs( i , 0 );
      cnt++;
    }
  }

  if( cnt >= 2 ){
    ng = true;
  }

  YYS( a , v[0] ){
    YYS( b , v[1] ){
      if( !cGb[a][b] ){
        ng = true;
      }
    }
  }

  if( ng ){
    puts( "No" );
  } else {
    puts( "Yes" );
    REP( i , n ){
      if( col[i] == 0 ){
        printf( "a" );
      } else if( col[i] == -1 ){
        printf( "b" );
      } else if( col[i] == 1 ){
        printf( "c" ); 
      } else {
        assert( false );
      }
    }
    printf( "\n" );
  }

  return 0;
}