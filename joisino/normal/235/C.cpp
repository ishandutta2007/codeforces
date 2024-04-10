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

struct SuffixAutomaton{
  mi to;
  vi link, len;
  int last;
  const int s;
  SuffixAutomaton( int sigma = 26 ) : s(sigma){
    last = create();
  }
  int create( int le = 0, int li = 0, vi t = vi(0) ){
    len.pb( le );
    link.pb( li );
    if( SZ(t) == s ) to.pb( t );
    else to.pb( vi(s, 0) );
    return SZ(to)-1;
  }
  void append( int c ){
    int p = last;
    last = create( len[p] + 1 );
    
    for( ; to[p][c] == 0; p = link[p] ) to[p][c] = last;
    if( to[p][c] == last ) return;
    
    int q = to[p][c];
    if( len[q] == len[p] + 1 ){
      link[last] = q;
      return;
    }

    int t = create( len[p]+1, link[q], to[q] );
    link[last] = link[q] = t;
    for( ; to[p][c] == q; p = link[p] ) to[p][c] = t;
  }
};

SuffixAutomaton sa;

mi G( 2000010 );

int n;
char s[1000010];

int memo[2000010];
bool used[2000010];

int dfs( int x ){
  if( used[x] ) return memo[x];
  used[x] = true;
  YYS( w , G[x] ) memo[x] += dfs( w );
  return memo[x];
}

int main(){

  scanf( "%s" , s );
  int len = strlen(s);

  REP( i , len ) sa.append( s[i] - 'a' );

  REP( i , SZ(sa.to) ) REP( j , 26 ) if( sa.to[i][j] != 0 ) G[i].pb( sa.to[i][j] );

  int last = sa.last;
  while( 1 ){
    memo[last]++;
    if( last == 0 ) break;
    last = sa.link[last];
  }
  
  dfs( 0 );

  scanf( "%d" , &n );

  
  REP( i , n ){
    scanf( "%s" , s );
    len = strlen(s);
    int a = 0, b = 0;
    int cur = 0;
    vi acc(0);
    while( a < len ){
      int sh = sa.len[ sa.link[cur] ] + 1;
      // cout << a << " " << b << " " << cur << " " << ans << " " << sh << endl;
      if( b - a == len ){
	acc.pb( cur );
	if( sh == len ) cur = sa.link[cur];
	a++;
      } else if( sa.to[cur][s[b%len]-'a'] != 0 ){
	cur = sa.to[cur][s[b%len]-'a'];
	b++;
      } else if( a == b ){
	a++; b++;
      } else {
	if( sh == b-a ) cur = sa.link[cur];
	a++;
      }
    }
    SORT( acc );
    UNIQUE( acc );
    ll ans = 0;
    YYS( w , acc ) ans += memo[w];
    printf( "%lld\n" , ans );
  }
  
  
  return 0;
}