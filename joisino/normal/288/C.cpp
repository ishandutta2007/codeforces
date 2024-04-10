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

const int MAX_N = 1000010;

int n;
int a[MAX_N*2];
int size = 1;
ll ans;

void rec( int l , int r ){
  if( r-l == 1 ) return;
  int m = (l+r)/2;
  REP( i , (r-l)/2 ) if( m + i <= n ) swap( a[l+i] , a[m+i] );
  rec( l , m );
  rec( m , r );
}

int main(){

  cin >> n;
  while( size <= n ) size *= 2;
  REP( i , n+1 ) a[i] = i;
  rec( 0 , size );
  REP( i , n+1 ) ans += a[i]^i;
  printf( "%lld\n" , ans );
  REP( i , n+1 ) printf( "%d%c" , a[i] , i==n?'\n':' ' );

  
  return 0;
}