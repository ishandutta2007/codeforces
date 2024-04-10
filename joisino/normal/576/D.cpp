#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto x:arr)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> P;
//typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
ll in(){ ll a; cin >> a; return a; }



int n, m;

const int MAX_N = 160;

typedef pair<ll,P> IP;
vector<IP> es;

typedef bitset<MAX_N> vec;
typedef vector<vec> mat;

void init( mat &a ){
  REP( i , n )
    REP( j , n )
    a[i][j] = 0;
  REP( i , n )
    a[i][i] = 1;
}

mat T( mat &a ){
  mat res( MAX_N );
  REP( i , n )
    REP( j , n )
    res[i][j] = a[j][i];
  return res;
}

mat times( mat &a , mat b ){
  mat res( MAX_N );
  b = T( b );
  REP( i , n )
    REP( j , n )
    res[i][j] = (a[i]&b[j]).any();
  return res;
}

mat pow( mat a , ll k ){
  mat res( MAX_N );
  init( res );
  while( k > 0 ){
    if( k % 2 == 1 ) res = times( res , a );
    a = times( a , a );
    k /= 2;
  }
  return res;
}

bool used[MAX_N];
vector<P> AG[MAX_N];

int main(){

  mat G( MAX_N );
  
  cin >> n >> m;
  REP( i , m ){
    ll a , b , c;
    cin >> a >> b >> c; a--; b--;
    es.pb( IP( c , P( a , b ) ) );
    AG[a].pb( P( b , c ) );
  }
  es.pb( IP( INFLL , P( n-1 , n-1 ) ) );

  sort( ALL( es ) );
  
  G[n-1][n-1] = 1;

  mat np( MAX_N );
  init( np );
  
  ll nt = 0;

  REP( i , es.size() ){
    ll c = es[i].fi;
    ll x = es[i].se.fi;
    ll y = es[i].se.se;

    mat powg = pow( G , c - nt );
    mat nep = times( powg , np );
    
    if( nep[n-1][0] ){
      queue<P> que;
      REP( i , n )
	if( np[i][0] ) que.push( P( i , nt ) ), used[i] = true;
      while( !que.empty() ){
	ll x = que.front().fi;
	ll t = que.front().se;
	que.pop();
	if( x == n-1 ){
	  cout << t << endl;
	  return 0;
	}
	REP( i , AG[x].size() ){
	  int to = AG[x][i].fi;
	  int co = AG[x][i].se;
	  if( co <= t && !used[to] )
	    que.push( P( to , t+1 ) );
	}
      }
    }
    
    np = nep;
    G[y][x] = 1;
    nt = c;
  }

  cout << "Impossible" << endl;
  
  return 0;
}