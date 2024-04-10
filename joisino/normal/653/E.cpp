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


int n, m, k;

vi G[300010];

list<int> unused;

bool zero[300010];
vb adj;


vi bfs( int s ){
  vi v(0);
  queue<int> que;
  que.push( s );
  while( not que.empty() ){
    int x = que.front();
    que.pop();
    v.pb( x );
    YYS( w , G[x] ){
      adj[w] = true;
    }
    for( auto ite = unused.begin(); ite != unused.end(); ){
      if( not adj[*ite] ){
        que.push( *ite );
        ite = unused.erase( ite );
      } else {
        adj[*ite] = false;
        ite++;
      }
    }
  }
  return v;
}

bool check(){
  adj.assign( n , false );
  FOR( i , 1 , n ){
    unused.pb( i );
  }
  int cnt = 0;
  while( !unused.empty() ){
    auto it = unused.begin();
    int s = *it;
    unused.erase( it );
    vi v = bfs( s );
    bool ok = false;
    YYS( w , v ){
      if( !zero[w] ){
        ok = true;
      }
    }
    if( !ok ){
      return false;
    }
    cnt++;
  }
  if( cnt > k ){
    return false;
  }
  return true;
}

int main(){

  n = in();
  m = in();
  k = in();

  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    if( a > b ){
      swap( a , b );
    }
    if( a == 0 ){
      zero[b] = true;
    } else {
      G[a].pb( b );
      G[b].pb( a );
    }
  }

  if( !check() ){
    puts( "impossible" );
    return 0;
  }

  int cnt = 0;
  FOR( i , 1 , n ){
    if( !zero[i] ){
      cnt++;
    }
  }

  if( cnt >= k ){
    puts( "possible" );
  } else {
    puts( "impossible" );
  }
  
  return 0;
}