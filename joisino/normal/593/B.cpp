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

const int MAX_N = 100010;

int n;

ll x1, x2;
ll k[MAX_N], b[MAX_N];

pl p[MAX_N];

ll minv = INFLL;

stack<ll> st;

int main(){

  scanf( "%d" , &n );
  scanf( "%lld %lld" , &x1 , &x2 );

  REP( i , n ){
    scanf( "%lld %lld" , &k[i] , &b[i] );
    p[i] = pl( k[i] * x1 + b[i] , k[i] * x2 + b[i] );
  }

  sort( p , p+n );
  ll prev = -1;
  for( int i = n-1; i >= 0; i-- ){
    // printf( "%lld %lld\n" , p[i].fi , p[i].se );
    if( prev != p[i].fi ){
      while( !st.empty() ){
	chmin( minv , st.top() );
	st.pop();
      }
      prev = p[i].fi;
    }
    st.push( p[i].se );
    if( p[i].se > minv ){
      puts( "YES" );
      return 0;
    }
  }
 
  puts( "NO" );
  
  return 0;
}