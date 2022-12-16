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
typedef vector<pl> vpl;

const int INF = 1e9;
const ll INFLL = 1e18;
const double EPS = 1e-8;
 
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }


const int MAX_N = 100010;
int size;
int node[MAX_N*4][60];

void init( int n ){
  size = 1;
  while( size < n ) size *= 2;
  REP( i , size*2-1 )
    REP( j , 60 )
    node[i][j] = 0;
}
void update( int k , int x ){
  k += size-1;

  REP( i , 60 ){
    if( i % x == 0 ) node[k][i] = 2;
    else node[k][i] = 1;
  }
  
  while( k > 0 ){
    k = (k-1)/2;

    REP( i , 60 )
      node[k][i] = node[k*2+1][i] + node[k*2+2][(i+node[k*2+1][i])%60];
  }
}
int query( int a , int b , int t , int k , int l , int r ){
  if( a <= l && r <= b ){
    return node[k][t%60];
  } else if( b <= l || r <= a ){
    return 0;
  } else {
    int chl = query( a , b , t       , k*2+1 , l , (l+r)/2 );
    int chr = query( a , b , t + chl , k*2+2 , (l+r)/2 , r );
    return chl + chr;
  }
}
int query( int a , int b , int t ){
  return query( a , b , t , 0 , 0 , size );
}

int n;
int a[MAX_N];
int q;
char c;
int x, y;

int main(){

  scanf( "%d" , &n );
  REP( i , n )
    scanf( "%d" , &a[i] );

  init( n );
  REP( i , n )
    update( i , a[i] );
  
  scanf( "%d\n" , &q );
  REP( loop_cnt , q ){
    scanf( "%c %d %d\n" , &c , &x , &y );
    if( c == 'C' ){
      x--;
      update( x , y );
    } else if( c == 'A' ){
      x--; y--;
      printf( "%d\n" , query( x , y , 0 ) );
    }
  }
  
  return 0;
}