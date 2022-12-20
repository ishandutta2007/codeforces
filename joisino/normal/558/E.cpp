#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i = (a); i < (int)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

int in(){ int a; cin >> a; return a; }

#define fi first
#define se second

typedef pair<P,char> PC;

const int MAX_N = 100010;
const int RMQ_MAX_N = MAX_N*4;
template<typename T>
struct LazyBit{
  T node[RMQ_MAX_N];
  T lazy[RMQ_MAX_N];
  int size;
  inline void push( int k , int l , int r ){
    node[k] = (r-l) * lazy[k];
    if( k < size-1 )
      lazy[k*2+1] = lazy[k*2+2] = lazy[k];
    lazy[k] = INF;
  }
  void init( int n ){
    size = 1;
    while( size < n ) size *= 2;
    for( int i = 0; i < size*2-1; i++ ){
      lazy[i] = INF;
      node[i] = 0;
    }
  }
  void update( int a , int b , T x , int k , int l , int r ){
    if( lazy[k] != INF ) push( k , l , r );
    if( a <= l && r <= b ){
      lazy[k] = x;
      push( k , l , r );
    } else if( b <= l || r <= a ){

    } else {
      update( a , b , x , k*2+1 , l , (l+r)/2 );
      update( a , b , x , k*2+2 , (l+r)/2 , r );
      node[k] = node[k*2+1] + node[k*2+2];
    }
  }
  void update( int a , int b , T x ){
    update( a , b , x , 0 , 0 , size );
  }
  T query( int a , int b , int k , int l , int r ){
    if( lazy[k] != INF ) push( k , l , r );
    if( a <= l && r <= b ){
      return node[k];
    } else if( b <= l || r <= a ){
      return 0;
    } else {
      return query( a , b , k*2+1 , l , (l+r)/2 ) + query( a , b , k*2+2 , (l+r)/2 , r );
    }
  }
  T query( int a , int b ){
    return query( a , b , 0 , 0 , size );
  }
};

LazyBit<int> bit[26];


int main(){


  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  REP( i , 26 )
    bit[i].init( n );

  REP( i , n )
    bit[ s[i] - 'a' ].update( i , i+1 , 1 );

  
  REP( q_loop , q ){
    int a , b , c;
    cin >> a >> b >> c; a--;

    int p = a;
    REP( i , 26 ){
      int ch = (c == 1 ? i : 25-i);
      int cnt = bit[ch].query( a , b );
      bit[ch].update( a , b , 0 );
      bit[ch].update( p , p+cnt , 1 );
      p += cnt;
    }
  }

  REP( i , n )
    REP( j , 26 )
    if( bit[j].query( i , i+1 ) == 1 )
      cout << char('a' + j);
  cout << endl;
  
  return 0;
}