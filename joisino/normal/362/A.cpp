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
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const ll dy[] = { -2 , -2 , 2 , 2 };
const ll dx[] = { 2 , -2 , -2 , 2 };

char s[72][72];

ll t;

ll dist[72][72][72];

bool isin( ll y , ll x ){
  return 0 <= y && y < 8 && 0 <= x && x < 8;
}

void bfs( ll sy , ll sx , ll c ){
  REP( i , 8 ) REP( j , 8 ) dist[c][i][j] = INFLL;
  dist[c][sy][sx] = 0;
  
  queue<pl> que;
  que.push( pl( sy , sx ) );
  while( !que.empty() ){
    ll y = que.front().fi;
    ll x = que.front().se;
    que.pop();
    REP( i , 4 ){
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if( isin( ny , nx ) && dist[c][ny][nx] == INFLL){
	dist[c][ny][nx] = dist[c][y][x] + 1;
	que.push( pl( ny , nx ) );
      }
    }
  }
}

int main(){

  scanf( "%lld" , &t );
  REP( test_case , t ){
    REP( i , 8 ) scanf( "%s" , s[i] );

    ll cnt = 0;
    REP( i , 8 ) REP( j , 8 ) if( s[i][j] == 'K' ) bfs( i , j , cnt++ );

    bool ans = false;
    REP( i , 8 ) REP( j , 8 ) if( dist[0][i][j] < INFLL && dist[1][i][j] < INFLL && dist[0][i][j] % 2 == dist[1][i][j] % 2 && s[i][j] != '#' ) ans = true;

    if( ans ) puts( "YES" );
    else puts( "NO" );
  }

  return 0;
}