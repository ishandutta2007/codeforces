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

const int MAX_N = 100010;

int n;

vi v[MAX_N];

priority_queue<int,vi,greater<int> > que;

int sz, co;
vi cv;

int ans = INF;

bool cmp( int a , int b ){
  return SZ(v[a]) > SZ(v[b]);
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ){
    int a, b;
    scanf( "%d %d" , &a , &b ); a--;
    if( a != -1 ){
      v[a].pb( b );
      co += b;
      cv.pb( a );
    }
  }

  SORT( cv ); UNIQUE( cv );
  sort( ALL(cv) , cmp );

  YYS( w , cv ){
    SORT( v[w] );
    REVERSE( v[w] );
  }
  
  sz = n;

  REP( i , MAX_N ){
    if( sz > i ) chmin( ans , co );
    
    YYS( w , cv ){
      co -= v[w][i];
      que.push( v[w][i] );
      sz--;
    }
    while( !cv.empty() && SZ( v[ cv.back() ] ) == i+1 ) cv.pop_back();
    
    while( !que.empty() && sz <= i+1 ){
      co += que.top();
      que.pop();
      sz++;
    }
  }

  printf( "%d\n" , ans );

  return 0;
}