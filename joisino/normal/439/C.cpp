#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
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

const int MAX_N = 100010;

int n, k, p;
ll a[MAX_N];
ll sum;
int od, ev;

vi ans[MAX_N];
int cnt;
int cnt2;
int cnt3;
int r = 0;

bool used[MAX_N];

int main(){

  scanf( "%d %d %d" , &n , &k , &p );
  REP( i , n ) scanf( "%lld" , &a[i] );
  
  REP( i , n ) sum += a[i];
  REP( i , n ){
    if( a[i] % 2 == 1 ) od++;
    else ev++;
  }

  if( k-p > od ) return puts( "NO" );
  if( p > ev + (od-(k-p))/2 ) return puts( "NO" );
  if( sum % 2 != (k-p) % 2 ) return puts( "NO" );

  cnt3 = k-1;
  REP( i , n ){
    if( a[i] % 2 == 1 ){
      if( cnt < k-p ){
	ans[cnt].pb( a[i] );
	cnt++;
      } else {
	ans[cnt3].pb( a[i] );
	r++;
	if( r == 2 ){
	  r = 0;
	  cnt3--;
	  if( cnt3 == -1 ) cnt3 = k-1;
	}
      }
    } else {
      if( k-p+cnt2 < k-1 ){
	ans[k-p+cnt2].pb( a[i] );
	cnt2++;
      } else {
	ans[k-1].pb( a[i] );
      }
    }
  }

  printf( "YES\n" );
  REP( i , k ){
    printf( "%d" , ans[i].size() );
    YYS( w , ans[i] ) printf( " %d" , w );
    printf( "\n" );
  }
  
  return 0;
}