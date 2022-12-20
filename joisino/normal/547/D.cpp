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

template<class T> pair<vi,vector<T> > compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return make_pair( res , ord );
}

const int MAX_N = 400010;

typedef pair<int,pi> st;

const string s = "br";

int n;

vi xs, ys, cx, cy;

set<int> odd;
set<pi> es[MAX_N];

int rs[MAX_N], bs[MAX_N];

vector<st> ep;

int ans[MAX_N];

void dfs( int x ){
  while( !es[x].empty() ){
    int to = (*es[x].begin()).fi;
    int id = (*es[x].begin()).se;
    es[x].erase( pi( to , id ) );
    es[to].erase( pi( x , id ) );
    dfs( to );
    ep.pb( st( id , pi( x , to ) ) );
  }
}

void rec(){
  if( odd.empty() ){
    REP( i , 2*n ) dfs( i );
    int cur = 0;
    YYS( w , ep ){
      ans[ w.fi ] = cur;
      if( cur == 0 ){
	bs[ w.se.fi ]++;
	bs[ w.se.se ]++;
      } else {
	rs[ w.se.fi ]++;
	rs[ w.se.se ]++;
      }
      cur = 1 - cur;
    }
    return;
  }

  int a = *odd.begin();
  odd.erase( a );
  
  int b = (*es[a].begin()).fi;
  int id = (*es[a].begin()).se;
  
  es[a].erase( pi( b , id ) );
  es[b].erase( pi( a , id ) );
  
  if( SZ(es[b]) % 2 == 1 ) odd.insert( b );
  else odd.erase( b );
  
  rec();
  
  if( bs[b] > rs[b] ){
    ans[id] = 1;
    rs[a]++;
    rs[b]++;
  } else {
    ans[id] = 0;
    bs[a]++;
    bs[b]++;
  }
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    int x, y;
    scanf( "%d %d" , &x , &y );
    xs.pb( x ); ys.pb( y );
  }

  cx = compress( xs ).fi;
  cy = compress( ys ).fi;

  REP( i , n ){
    es[ cx[i] ].emplace( cy[i] + n , i );
    es[ cy[i] + n ].emplace( cx[i] , i );
  }

  REP( i , 2*n ) if( SZ( es[i] ) % 2 == 1 ) odd.insert( i );

  rec();

  REP( i , n ) printf( "%c" , s[ ans[i] ] );
  printf( "\n" );
  
  return 0;
}