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
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
 
template<class T> inline T sq( T a ){ return a * a; }
 
// head


template<class T> pair<vi,vector<T> > compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return make_pair( res , ord );
}


typedef deque<set<int> > ds;

int n, m;

vi xs;

vi roots;

vpi qs[100010];
int ans[100010];

vector<string> ss;
mi G( 100010 );

int sz[100010];
ds dqs[100010];

int dfs( int x ){
  int cur = x;  
  YYS( w , G[x] ){
    int nex = dfs( w );
    if( sz[cur] < sz[nex] ) swap( cur, nex );
    sz[cur] += sz[nex];
    dqs[cur].resize( max( SZ(dqs[cur]) , SZ(dqs[nex]) ), set<int>() );
    REP( i , SZ(dqs[nex]) ){
      dqs[cur][i].insert( ALL(dqs[nex][i]) );
    }
    dqs[nex].clear();
    dqs[nex].shrink_to_fit();
  }
  dqs[cur].push_front( { xs[x] } );
  sz[cur]++;
  YYS( w , qs[x] ){
    int temp;
    if( SZ( dqs[cur] ) <= w.se ) temp = 0;
    else temp = SZ( dqs[cur][w.se] );
    ans[w.fi] = temp;
  }
  return cur;
}

int main(){

  scanf( "%d" , &n );

  REP( i , n ){
    char s[72];
    int p;
    scanf( "%s %d" , s , &p ); p--;
    ss.pb( s );
    if( p == -1 ) roots.pb( i );
    else G[p].pb( i );
  }

  xs = compress( ss ).fi;

  scanf( "%d" , &m );
  REP( i , m ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--;
    qs[a].pb( i , b );
  }

  YYS( r , roots ) dfs( r );

  REP( i , m ) printf( "%d\n" , ans[i] );
  
  return 0;
}