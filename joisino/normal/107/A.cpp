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
const ll INFLL = 1e18+10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-14;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

typedef pair<pi,int> pii;

const int MAX_N = 1010;

int n, p;

pi to[MAX_N];
bool from[MAX_N];

vector<pii> ans;

int main(){

  REP( i , MAX_N ) to[i] = pi( -1 , -1 );
  
  scanf( "%d %d" , &n , &p );
  REP( i , p ){
    int a, b, c;
    scanf( "%d %d %d" , &a , &b , &c ); a--; b--;
    to[a] = pi( b , c );
    from[b] = true;
  }

  REP( i , n ){
    if( !from[i] && to[i] != pi( -1 , -1 ) ){
      int cur = i;
      int val = INF;
      while( to[cur] != pi( -1 , -1 ) ){
	chmin( val , to[cur].se );
	cur = to[cur].fi;
      }
      ans.pb( pi( i , cur ) , val );
    }
  }

  SORT( ans );

  printf( "%d\n" , (int)ans.size() );
  YYS( w , ans ) printf( "%d %d %d\n" , w.fi.fi+1 , w.fi.se+1 , w.se );
  
  return 0;
}