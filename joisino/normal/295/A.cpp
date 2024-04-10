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

struct Bitran{
  Bit bita , bitb;
  void init( int n ){
    bita.init( n );
    bitb.init( n );
  }
  void addran( int a , int b , ll x ){
    bita.add( a , x );
    bita.add( b , -x );
    bitb.add( a , -(a-1)*x );
    bitb.add( b , (b-1)*x );
  }
  void add( int a , ll x ){
    bitb.add( a , x );
  }
  ll sum( int k ){
    return k*bita.sum(k) + bitb.sum(k);
  }
  ll get( int k ){
    return sum(k)-sum(k-1);
  }
};

Bitran bit1, bit2;

const int MAX_N = 100010;

int n, m, k;
ll a[MAX_N];
ll l[MAX_N], r[MAX_N] , d[MAX_N];
int x, y;

int main(){
  scanf( "%d %d %d" , &n , &m , &k );
  bit1.init( n );
  bit2.init( m );
  REP( i , n ) scanf( "%lld" , &a[i] );
  REP( i , m ) scanf( "%lld %lld %lld" , &l[i], &r[i], &d[i] );
  REP( i , k ){
    scanf( "%d %d" , &x , &y );
    bit2.addran( x-1 , y , 1 );
  }
  REP( i , m ) bit1.addran( l[i]-1 , r[i] , d[i]*bit2.get(i) );
  REP( i , n ) printf( "%lld%c" , bit1.get(i)+a[i] , i==n-1?'\n':' ' );
  
  
  return 0;
}