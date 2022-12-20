#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define REPR(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vi> mi;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
const ll MOD = 1000000007;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct Starry{
  vl node, add, val;
  int size;
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    val = vl( size*2-1 , -1 );
    node = add = vl( size*2-1 , 0 );
    REP( i , n ) val[size-1+i] = i+1;
  }
  void addren( int a , int b , ll x , int k , int l , int r ){
    if( a <= l && r <= b ){
      if( val[k] != -1 ){
	add[k] += abs( val[k] - x );
      } else {
	addren( a , b , x , k*2+1 , l , (l+r)/2 );
	addren( a , b , x , k*2+2 , (l+r)/2 , r );
      }
      if( r-l == 1 ) node[k] = add[k]*(r-l);
      else node[k] = node[k*2+1] + node[k*2+2] + add[k]*(r-l);
      val[k] = x;
    } else if( b <= l || r <= a ){
      return;
    } else {
      if( val[k] != -1 ){
	val[k*2+1] = val[k*2+2] = val[k];
	val[k] = -1;
      }
      addren( a , b , x , k*2+1 , l , (l+r)/2 );
      addren( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = node[k*2+1] + node[k*2+2] + add[k]*(r-l);
    }
  }
  void addren( int a , int b , ll x ){
    addren( a , b , x , 0 , 0 , size );
  }
  ll query( int a , int b , int k , int l , int r ){
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return 0;
    } else {
      ll chl = query( a , b , k*2+1 , l , (l+r)/2 );
      ll chr = query( a , b , k*2+2 , (l+r)/2 , r );
      return chl + chr + add[k]*(min(r,b)-max(l,a));
    }
  }
  ll query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
};

Starry seg;

int n, m;
int t, l, r, x;

int main(){

  scanf( "%d %d" , &n , &m );
  seg.init( n );

  REP( i , m ){
    scanf( "%d" , &t );
    if( t == 1 ){
      scanf( "%d %d %d" , &l , &r , &x ); l--;
      seg.addren( l , r , x );
    } else {
      scanf( "%d %d" , &l , &r ); l--;
      cout << seg.query( l , r ) << endl;
    }
  }
  
  return 0;
}