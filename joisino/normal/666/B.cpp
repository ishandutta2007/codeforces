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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }
ll in(){ ll x; scanf( "%lld" , &x ); return x; }
 
// head

typedef pair<pi,pi> pipi;

int n, m;

vi G[3010];
int bd[3010];

queue<int> que;

void bfs( int s ){
  REP( i , n ){
    bd[i] = INF;
  }
  bd[s] = 0;
  que.push( s );
  while( !que.empty() ){
    int x = que.front();
    que.pop();
    YYS( w , G[x] ){
      if( bd[w] == INF ){
	bd[w] = bd[x] + 1;
	que.push( w );
      }
    }
  }
}

vpi td[3010];
vpi cd[3010];

int ans = -INF;
vl ansv;

int dist[3010][3010];

const pi NONE = pi( -INF , 0 );
pipi mint( const vpi &v , int a , int b ){
  vpi res(0);
  YYS( w , v ){
    if( w.se != a and w.se != b ){
      res.pb( w );
      if( SZ(res) >= 2 ){
	break;
      }
    }
  }
  if( SZ(res) == 0 ){
    return pipi( NONE , NONE );
  } else if( SZ(res) == 1 ){
    return pipi( res[0] , NONE );
  } else {
    return pipi( res[0] , res[1] );
  }
}

int main(){

  n = in();
  m = in();

  REP( i , m ){
    int a = in() - 1;
    int b = in() - 1;
    G[a].pb( b );
  }

  REP( i , n ){
    bfs( i );
    REP( j , n ){
      dist[i][j] = bd[j];
      if( bd[j] != INF ){
	td[i].pb( bd[j] , j );
	cd[j].pb( bd[j] , i );
      }
    }
  } 
  
  REP( i , n ){
    SORT( td[i] );
    REVERSE( td[i] );
    SORT( cd[i] );
    REVERSE( cd[i] );
  }

  REP( i , n ){
    if( SZ(cd[i]) == 0 ){
      continue;
    }
    REP( j , n ){
      if( SZ(td[j]) == 0 ){
	continue;
      }
      int cur = cd[i][0].fi + dist[i][j] + td[j][0].fi;
      if( i != j and dist[i][j] < INF and cur > ans){
	pipi a = mint( cd[i] , i , j );
	pipi b = mint( td[j] , i , j );
	if( a.fi.se == b.fi.se ){
	  cur = a.se.fi + dist[i][j] + b.fi.fi;
	  if( cur > ans ){
	    ans = cur;
	    ansv = { a.se.se , i , j , b.fi.se };
	  }
	  cur = a.fi.fi + dist[i][j] + b.se.fi;
	  if( cur > ans ){
	    ans = cur;
	    ansv = { a.fi.se , i , j , b.se.se };
	  }
	} else {
	  cur = a.fi.fi + dist[i][j] + b.fi.fi;
	  if( cur > ans ){
	    ans = cur;
	    ansv = { a.fi.se , i , j , b.fi.se };
	  }
	}
      }
    }
  }

  assert( SZ(ansv) == 4 );
  cout << ansv[0]+1 << " " << ansv[1]+1 << " " << ansv[2]+1 << " " << ansv[3]+1 << endl;
  
  return 0;
}