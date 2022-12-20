#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define PW(x) (1LL<<(x))
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
typedef vector<vi> mi;
typedef vector<vl> ml;
typedef vector<vd> md;

const int INF = 1e9+10;
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct edge{
  int to, co, id;
  edge(){}
  edge( int to , int co , int id ) : to(to) , co(co) , id(id) {}
};

const int MAX_N = 100010;

int n, m;

vector<edge> G[MAX_N];

typedef pair<pi,int> pii;
pii es[MAX_N];

int dist[MAX_N];
int cost[MAX_N];
int from[MAX_N];
int usedid[MAX_N];

bool used[MAX_N];

vector<pii> ans;

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , m ){
    int x, y, z;
    scanf( "%d %d %d" , &x , &y , &z ); z = 1 - z;
    es[i] = pii( pi( x , y ) , z );
    G[x].pb( y , z , i );
    G[y].pb( x , z , i );
  }

  REP( i , MAX_N ) dist[i] = cost[i] = INF;
  dist[1] = cost[1] = 0;
  
  queue<int> que;
  que.push( 1 );
  while( !que.empty() ){
    int x = que.front();
    que.pop();
    YYS( w , G[x] ){
      if( dist[ w.to ] > dist[x] + 1 ){
	dist[ w.to ] = dist[x] + 1;
	cost[ w.to ] = cost[x] + w.co;
	from[ w.to ] = x;
	usedid[ w.to ] = w.id;
	que.push( w.to );
      } else if( dist[w.to] == dist[x] + 1 && cost[ w.to ] > cost[x] + w.co ){
	cost[ w.to ] = cost[x] + w.co;
	from[ w.to ] = x;
	usedid[ w.to ] = w.id;
      }
    }
  }

  int p = n;
  while( p != 1 ){
    used[ usedid[p] ] = true;
    p = from[p];
  }

  REP( i , m ){
    if( es[i].se == 1 && used[i] ) ans.pb( es[i].fi , 1 );
    if( es[i].se == 0 && !used[i] ) ans.pb( es[i].fi , 0 );
  }

  printf( "%d\n" , (int)ans.size() );
  YYS( w , ans ){
    printf( "%d %d %d\n" , w.fi.fi , w.fi.se , w.se );
  }
  
  return 0;
}