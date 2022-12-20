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

int n;
int to[200010];

int sz = -1;

int de[200010];
int used[200010];
vi ax;

void dfs( int x, int d ){
  used[x] = 1;
  de[x] = d;
  if( used[ to[x] ] == 0 ){
    dfs( to[x] , d + 1 );
  } else if( used[ to[x] ] == 1 ){
    ax.pb( x );
    sz = d - de[ to[x] ];
  }
  used[x] = 2;
}

int main(){

  n = in();
  REP( i , n ){
    to[i] = in() - 1;
  }

  int root = -1;
  REP( i , n ){
    if( used[i] == 0 ){
      sz = -1;
      dfs( i, 0 );
      if( sz != -1 ){
        if( sz == 0 ){
          root = ax.back();
        }
      }
    }
  }

  int ans = SZ(ax);
  if( root != -1 ){
    assert( to[root] == root );
    ans--;
  } else {
    root = ax.back();
    ax.pop_back();
    to[root] = root;
  }

  YYS( w , ax ){
    to[w] = root;
  }

  printf( "%d\n", ans );
  REP( i , n ){
    if( i != 0 ){
      printf( " " );
    }
    printf( "%d" , to[i] + 1 );
  }
  printf( "\n" );
  
  return 0;
}