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


struct Bit{
  vl bit;
  int size;
  void init( int n ){
    n++;
    size = 1;
    while( size < n ) size *= 2;
    bit = vl( size+1 , 0 );
  }
  void add( int k , ll x ){
    k++;
    while( k <= size ){
      bit[k] += x;
      k += k & -k;
    }
  }
  ll sum( int k ){
    k++;
    ll res = 0;
    while( k > 0 ){
      res += bit[k];
      k -= k & -k;
    }
    return res;
  }
  ll get( int k ){
    return sum(k)-sum(k-1);
  }
  ll update( int k , ll x ){
    add( k , x-get(k) );
  }
};


const int MAX_N = 200010;

int n, m;
int a[MAX_N];
int pos[MAX_N];

Bit bit;

vi v[MAX_N];
vpi q[MAX_N];

int ans[MAX_N];

int main(){

  scanf( "%d %d" , &n , &m );
  REP( i , n ) scanf( "%d" , &a[i] );
  REP( i , n ) pos[ a[i] ] = i;

  FOR( i , 1 , n+1 ){
    for( ll j = i; j <= n; j += i ){
      if( pos[i] < pos[j] ) v[pos[i]].pb( pos[j] );
      else v[pos[j]].pb( pos[i] );      
    }
  }

  bit.init( n+1 );

  REP( i , m ){
    int x , y;
    scanf( "%d %d" , &x , &y ); x--; y--;
    q[x].pb( y , i );
  }

  for( int i = n; i >= 0; i-- ){
    YYS( w , v[i] ) bit.add( w , 1 );
    YYS( w , q[i] ) ans[ w.se ] = bit.sum( w.fi );
  }

  REP( i , m ) cout << ans[i] << endl;
  
  return 0;
}