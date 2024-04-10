#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define pb emplace_back
#define mp make_pair
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
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

vl factor( ll x ){
  vl res;
  for( ll i = 1; i*i <= x; i++ ){
    if( x % i == 0 ){
      res.pb( i );
      if( i != x/i ) res.pb( x/i );
    }
  }
  return res;
}

const int MAX_P = 100010;

unordered_map<ll,vl> fa;

ll k;

ll cnt = 0;
vl ans;

void dfs( ll x , ll d ){
  if( ans.size() >= MAX_P ) return;
  
  if( d == k ){
    ans.pb( x );
    return;
  }

  if( fa[x].size() == 1 ){
    ans.pb( x );
    return;
  }

  if( fa[x].size() == 2 ){
    for( int i = 0; i < k-d && ans.size() < MAX_P; i++ ) ans.pb( fa[x][0] );
    ans.pb( fa[x][1] );
    return;
  }

  YYS( w , fa[x] ){
    dfs( w , d+1 );
  }
}

ll x;

int main(){

  cin >> x >> k;

  vl v = factor( x );
  SORT( v );
  fa[x] = v;

  YYS( w , v ){
    vl res(0);
    YYS( d , v ) if( w % d == 0 ) res.pb( d );
    fa[w] = res;
  }

  dfs( x , 0 );

  REP( i , ans.size() ){
    if( i == 100000 ) break;
    if( i != 0 ) printf( " " );
    printf( "%lld" , ans[i] );
  }
  printf( "\n" );

  return 0;
}