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

const ll MAX_N = 1024;

const ll dx[] = { 1 , 0 , -1 , 0 };
const ll dy[] = { 0 , -1 , 0 , 1 };

const string t = "DIMADIMA";
ll it[256];

ll n, m;
char s[MAX_N][MAX_N];

ll deg[MAX_N*MAX_N];
ll len[MAX_N*MAX_N];
vl G[MAX_N*MAX_N];

queue<ll> que;

ll p( ll y , ll x ){
  return y * m + x;
}

bool isin( ll y , ll x ){
  return 0 <= y && y < n && 0 <= x && x < m;
}

int main(){

  it['D'] = 0, it['I'] = 1, it['M'] = 2, it['A'] = 3;

  scanf( "%lld %lld" , &n , &m );
  REP( i , n ) scanf( "%s" , s[i] );

  REP( i , n ) REP( j , m ) REP( k , 4 ){
    ll ny = i + dy[k];
    ll nx = j + dx[k];
    if( isin( ny , nx ) && s[ny][nx] == t[it[s[i][j]]+1] ){
      G[p(ny,nx)].pb( p(i,j) );
      deg[p(i,j)]++;
    }
  }

  REP( i , n*m ) len[i] = -1;
  
  REP( i , n*m ) if( deg[i] == 0 ) que.push( i );

  while( !que.empty() ){
    ll x = que.front(); que.pop();
    chmax( len[x] , 1LL );
    YYS( w , G[x] ){
      chmax( len[w] , len[x]+1 );
      deg[w]--;
      if( deg[w] == 0 ) que.push( w );
    }
  }

  ll ans = 0;
  REP( i , n ) REP( j , m ){
    if( len[p(i,j)] == -1 ){
      printf( "Poor Inna!\n" );
      return 0;
    }
    if( s[i][j] == 'D' ) chmax( ans , len[p(i,j)] );
  }

  if( ans/4 == 0 ) printf( "Poor Dima!\n" );
  else printf( "%lld\n" , ans/4 );
  
  return 0;
}