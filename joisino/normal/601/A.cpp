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
int G[410][410];

int dist[410];

int main(){

  n = in();
  m = in();
  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    G[a][b] = G[b][a] = 1;
  }

  if( G[0][n-1] ){
    REP( i , n ){
      REP( j , n ){
        if( i != j ){
          G[i][j] = 1 - G[i][j];
        }
      }
    }
  }
  
  queue<int> que;
  que.push( 0 );

  REP( i , n ){
    dist[i] = INF;
  }
  dist[0] = 0;

  while( !que.empty() ){
    int x = que.front();
    que.pop();
    REP( i , n ){
      if( G[x][i] && dist[i] == INF ){
        dist[i] = dist[x] + 1;
        que.push( i );
      }
    }
  }

  int ans = dist[n-1];
  if( ans == INF ){
    ans = -1;
  }

  printf( "%d\n" , ans );
  
  return 0;
}