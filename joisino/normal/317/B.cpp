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

const int B = 1000;
const int dx[] = { 1 , 0 , -1 , 0 };
const int dy[] = { 0 , -1 , 0 , 1 };

int n, t;

int x[B*2][B*2];
queue<pi> que;

int* g( int a , int b ){
  return &x[a+B][b+B];
}
int *g( pi a ){
  return g( a.fi , a.se );
}

int main(){
  
  scanf( "%d %d" , &n , &t );
  *g(0,0) = n;
  if( n >= 4 ) que.push( pi( 0 , 0 ) );

  while( !que.empty() ){
    int y = que.front().fi;
    int x = que.front().se;
    que.pop();
    if( *g(y,x) < 4 ) continue;
    int p = *g(y,x)/4;
    *g(y,x) -= p*4;
    REP( i , 4 ){
      int ny = y+dy[i];
      int nx = x+dx[i];
      *g(ny,nx) += p;
      if( *g(ny,nx) >= 4 ) que.push( pi( ny , nx ) );
    }
  }
  
  REP( i , t ){
    int a, b;
    scanf( "%d %d" , &a , &b );
    if( a <= -B || a >= B || b <= -B || b >= B ) printf( "0\n" );
    else printf( "%d\n" , *g(a,b) );
  }
  
  return 0;
}