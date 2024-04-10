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

const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

typedef pair<int,pi> st;

int n, m, p;

int a[310][310];
int dist[310][310];

vpi c[100010];

int d[310][310];

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs( int l ){
  REP( i , n ){
    REP( j , m ){
      d[i][j] = INF;
    }
  }
  priority_queue<st,vector<st>,greater<st> > que;
  while( !que.empty() ){
    que.pop();
  }
  YYS( w , c[l] ){
    que.emplace( dist[w.fi][w.se], w );
    d[w.fi][w.se] = dist[w.fi][w.se];
    // cout << l << " " << w.fi << " " << w.se << endl;
  }
  while( !que.empty() ){
    int y = que.top().se.fi;
    int x = que.top().se.se;
    // cout << l << " " << y << " " << x << endl;
    que.pop();
    REP( i , 4 ){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if( isin( ny , nx ) && d[ny][nx] == INF ){
        d[ny][nx] = d[y][x] + 1;
        que.emplace( d[ny][nx], pi( ny , nx ) );
      }
    }
  }
  YYS( w , c[l+1] ){
    dist[w.fi][w.se] = d[w.fi][w.se];
  }
}

int main(){

  n = in();
  m = in();
  p = in();

  REP( i , n ){
    REP( j , m ){
      a[i][j] = in() - 1;
      c[ a[i][j] ].pb( i , j );
    }
  }

  REP( i , n ){
    REP( j , m ){
      dist[i][j] = INF;
    }
  }
  
  YYS( s , c[0] ){
    dist[s.fi][s.se] = abs(s.fi) + abs(s.se);
  }

  REP( i , p-1 ){
    if( SZ(c[i]) <= 1000 ){
      YYS( s , c[i] ){
        YYS( t , c[i+1] ){
          int ad = abs( s.fi - t.fi ) + abs( s.se - t.se );
          chmin( dist[t.fi][t.se], dist[s.fi][s.se] + ad );
        }
      }
    } else {
      bfs( i );
    }
  }

  assert( SZ(c[p-1]) == 1 );

  printf( "%d\n", dist[ c[p-1][0].fi ][ c[p-1][0].se ] );
  
  return 0;
}