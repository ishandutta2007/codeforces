#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
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
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 256;


template<class T> pair<vi,vector<T> > compress( vector<T> a ){
  vector<T> ord = a;
  vi res(0);
  SORT( ord );
  UNIQUE( ord );
  YYS( w , a ) res.pb( lower_bound( ALL(ord) , w ) - ord.begin() );
  return make_pair( res , ord );
}

char s[MAX_N], t[MAX_N], u[MAX_N];
int n;
vector<string> edge;
vi G[MAX_N];

int ans;
bool used[MAX_N];

void dfs( int x , int d ){
  used[x] = true;
  chmax( ans , d );
  YYS( w , G[x] ) if( !used[w] ) dfs( w , d+1 );
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    scanf( "%s %s %s" , s , t , u );
    REP( j , strlen(s) ) if( 'a' <= s[j] && s[j] <= 'z' ) s[j] = s[j] - 'a' + 'A';
    REP( j , strlen(u) ) if( 'a' <= u[j] && u[j] <= 'z' ) u[j] = u[j] - 'a' + 'A';
    edge.pb( s );
    edge.pb( u );
  }
  edge.pb( "POLYCARP" );

  vi es = compress( edge ).fi;
  REP( i , n ) G[es[i*2+1]].pb( es[i*2] );

  dfs( es[2*n] , 1 );

  printf( "%d\n" , ans );
  
  return 0;
}