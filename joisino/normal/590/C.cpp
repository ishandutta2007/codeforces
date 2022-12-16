#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }


const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , 1 , 0 , -1 };

int n, m;
char s[1024][1024];

typedef vector<vec> mat;
mat d[16];
ll sd[16][16];

bool isin( int y , int x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs( char c , mat &dist ){
  queue<P> que;
  
  REP( i , n ){
    REP( j , m ){
      dist[i][j] = INF;
      if( s[i][j] == c ){
	dist[i][j] = 0;
	que.push( P( i , j ) );
      }
    }
  }

  while( !que.empty() ){
    int y = que.front().fi;
    int x = que.front().se;
    que.pop();
    REP( i , 4 ){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if( isin( ny , nx ) && s[ny][nx] != '#' && dist[ny][nx] == INF ){
	dist[ny][nx] = dist[y][x] + 1;
	que.push( P( ny , nx ) );
      }
    }
  }
}

void statedist( int a ){
  REP( k , 3 )
    sd[a][k] = INF;

  REP( i , n )
    REP( j , m )
    REP( k , 3 )
    if( s[i][j] == ('1' + k) )
      chmin( sd[a][k] , d[a][i][j] );
}

int main(){

  scanf( "%d %d\n" , &n , &m );

  REP( i , n )
    scanf( "%s" , s[i] );

  REP( i , 3 ){
    d[i] = mat( n , vec( m ) );
    bfs( '1' + i , d[i] );
  }

  REP( i , 3 )
    statedist( i );

    
  ll ans = INF;
  REP( i , 3 ){
    ll res = 0;
    REP( k , 3 )
      if( i != k ) res += sd[i][k] - 1;
    chmin( ans , res );
  }

  REP( i , n ){
    REP( j , m ){
      ll res = 0;
      REP( k , 3 )
	res += d[k][i][j];
      chmin( ans , res - 2 );
    }
  }

  if( ans >= n*m*3 ) cout << -1 << endl;
  else cout << ans << endl;
    
  return 0;
}