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

const int MAX_N = 100010;

int n;

vpl v[MAX_N*2];

unordered_set<ll> processed;

vpl ans;

ll p( ll x , ll y ){
  return x * MAX_N * 2 + y;
}

int no(){
  printf( "NO\n" );
  return 0;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    int x, y;
    scanf( "%d %d" , &x , &y );
    v[ y - x + MAX_N ].pb( x , y );
  }

  REP( i , MAX_N*2 ){
    SORT( v[i] );
    REVERSE( v[i] );
  }
  
  REP( i , n ){
    ll w;
    scanf( "%lld" , &w ); w += MAX_N;
    if( v[w].empty() ) return no();
    ll x = v[w].back().fi;
    ll y = v[w].back().se;
    v[w].pop_back();

    if( y > 0 && processed.find( p( x , y-1 ) ) == processed.end() ) return no();
    if( x > 0 && processed.find( p( x-1 , y ) ) == processed.end() ) return no();

    ans.pb( x , y );
    
    processed.insert( p( x , y ) );
  }

  printf( "YES\n" );
  YYS( w , ans ) printf( "%lld %lld\n" , w.fi , w.se );
  
  return 0;
}