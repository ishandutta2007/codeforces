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
typedef unsigned long long int ull;
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
const ll MOD2 = 1e9+9;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n;
int c[300010];

string s;

vi G[300010];

int ansv;
int ansc;

int sz[300010];

int it = 1;
int trie[1000010][26];

int ans[1000010];
int root[300010];

int upd( int x ){
  if( x > ansv ){
    ansv = x;
    ansc = 1;
  } else if( x == ansv ){
    ansc++;
  }
}

void merge( int a, int b ){
  REP( i , 26 ){
    if( trie[b][i] != 0 ){
      if( trie[a][i] == 0 ){
        trie[a][i] = trie[b][i];
      } else {
        merge( trie[a][i], trie[b][i] );
      }
    }
  }
  ans[a] = 0;
  REP( i , 26 ){
    if( trie[a][i] != 0 ){
      ans[a] += ans[ trie[a][i] ] + 1;
    }
  }
}

int dfs( int x , int p ){
  sz[x] = 1;
  int use = -1;
  YYS( w , G[x] ){
    if( w != p ){
      sz[x] += dfs( w , x );
      if( use == -1 || sz[use] < sz[w] ){
        use = w;
      }
    }
  }
  if( use == -1 ){
    upd( 1 + c[x] );
    ans[it] = 1;
    root[x] = it++;
    trie[ root[x] ][ s[x] - 'a' ] = it++;
    return root[x];
  }
  YYS( w , G[x] ){
    if( w != p && w != use ){
      merge( root[use], root[w] );
      // cout << x << " " << use << " " << w << " " << ans[ root[use] ] << endl;
    }
  }
  root[x] = it++;
  trie[ root[x] ][ s[x] - 'a' ] = root[use];
  ans[ root[x] ] = ans[ root[use] ] + 1;
  upd( ans[ root[x] ] + c[x] );
  return sz[x];
}

int main(){

  n = in();
  REP( i , n ){
    c[i] = in();
  }
  s = stin();
  REP( i , n-1 ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
    G[b].pb( a );
  }

  dfs( 0 , -1 );
  
  printf( "%d\n" , ansv );
  printf( "%d\n" , ansc );
  
  return 0;
}