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

const ll INF = 1e9+10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

const int MAX_N = 100010;

ll p;
int n;
int a[MAX_N];

ll ans;
int cnt[MAX_N];


bool check( int t ){
  REP( i , MAX_N ) cnt[i] = 0;
  FOR( i , p , t+1 ) cnt[ a[i] ]++;
  FOR( i , max(t+1,n-1-t) , n-p ) cnt[ a[i] ]--;
  FOR( i , t+1 , n-1-t ) if( a[i] != a[n-1-i] ) return false;
  REP( i , MAX_N ) if( cnt[i] < 0 ) return false;
  int odd = 0;
  REP( i , MAX_N ) if( cnt[i] % 2 == 1 ) odd++;
  return n % 2 >= odd;
}

ll bis(){
  ll lb = p, ub = n;
  while( ub - lb > 1 ){
    ll md = ( lb + ub ) / 2;
    if( check( md ) ) ub = md;
    else lb = md;
  }
  return ub;
}

int main(){

  scanf( "%d" , &n );
  REP( i , n ) scanf( "%d" , &a[i] );

  while( p < n && a[p] == a[n-1-p] ) p++;
  
  if( p == n ){
    printf( "%lld\n" , (ll)n*ll(n+1)/2 );
    return 0;
  }

  REP( rev , 2 ){
    ans += (p+1)*(n-bis());
    REP( i , n/2 ) swap( a[i] , a[n-1-i] );
  }
  if( ans > 0 ) ans -= (p+1)*(p+1);

  cout << ans << endl;
  
  return 0;
}