#include <bits/stdc++.h>
 
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

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
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-8;
const ld EPSLD = 1e-18;
const ll MOD = 1e9+7;

template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }

struct st{
  int x, y, id, t;
  st(){}
  st( int x , int y , int id , int t ) : x(x) , y(y) , id(id) , t(t) {}
};

bool cmpx( const st &a , const st &b ){
  return a.x < b.x;
}

bool cmpy( const st &a , const st &b ){
  return a.y < b.y;
}

struct rt{
  st a, b;
  int d;
  rt(){}
  rt( st a , st b , int d ) : a(a) , b(b) , d(d) {}
};

const int MAX_N = 100010;

int n;

st v[MAX_N*4];

inline int sq( int a ){ return a*a; }

rt closest_pair( st *a , int s ){
  if( s <= 1 ) return rt( st() , st() , INF );
  int t = s / 2;
  int x = a[t].x;
  rt resa = closest_pair( a , t );
  rt resb = closest_pair( a+t , s-t );
  rt res = resa.d < resb.d ? resa : resb;
  inplace_merge( a , a+t , a+s , cmpy );

  vector<st> b;
  REP( i , s ){
    if( sq( a[i].x - x ) >= res.d ) continue;

    REP( j , SZ(b) ){
      st &bj = b[SZ(b)-1-j];
      int dx = a[i].x - bj.x;
      int dy = a[i].y - bj.y;
      if( dy * dy >= res.d ) break;
      if( a[i].id != bj.id && dx * dx + dy * dy < res.d ) res = rt( a[i] , bj , dx * dx + dy * dy );
    }

    b.pb( a[i] );
  }

  return res;
}

int main(){

  FILE *fp = fopen( "input.txt" , "r" );
  
  fscanf( fp , "%d" , &n );
  REP( i , n ){
    int x, y;
    fscanf( fp , "%d %d" , &x , &y );
    v[i*4+0] = st(  x ,  y , i , 1 );
    v[i*4+1] = st( -x ,  y , i , 2 );
    v[i*4+2] = st(  x , -y , i , 3 );
    v[i*4+3] = st( -x , -y , i , 4 );
  }

  sort( v , v + 4*n , cmpx );

  rt res = closest_pair( v , 4*n );

  if( res.b.t == 1 ) res.b.t = 4;
  else if( res.b.t == 2 ) res.b.t = 3;
  else if( res.b.t == 3 ) res.b.t = 2;
  else if( res.b.t == 4 ) res.b.t = 1;

  FILE *ofp = fopen( "output.txt" , "w" );
  
  fprintf( ofp , "%d %d %d %d\n" , res.a.id+1 , res.a.t , res.b.id+1 , res.b.t );
  
  return 0;
}