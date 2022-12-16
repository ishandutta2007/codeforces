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

const int MAX_N = 128;

ll a, b;
char cs[MAX_N];
string s;
int n;
ll x, y;
ll ny, nx;

bool check(){
  ll tx = 0, ty = 0;
  if( x != 0 ) tx = (a-nx)/x;
  if( y != 0 ) ty = (b-ny)/y;
  if( x == 0 ) tx = ty;
  if( y == 0 ) ty = tx;
  return tx >= 0 && ty >= 0 && nx + tx * x == a && ny + ty * y == b && tx == ty;
}

int main(){

  scanf( "%lld %lld" , &a , &b );
  scanf( "%s" , cs ); s = cs; n = s.length();

  YYS( w , s ){
    if( w == 'U' ) y++;
    if( w == 'D' ) y--;
    if( w == 'L' ) x--;    
    if( w == 'R' ) x++;
  }

  if( check() ) return puts( "Yes" );
  YYS( w , s ){
    if( w == 'U' ) ny++;
    if( w == 'D' ) ny--;
    if( w == 'L' ) nx--;    
    if( w == 'R' ) nx++;
    if( check() ) return puts( "Yes" );
  }

  puts( "No" );
  
  return 0;
}