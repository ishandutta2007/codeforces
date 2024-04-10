#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef vector<double> vec;
typedef vector<vec> mat;
typedef pair<int,int> II;

template<typename T> T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T> T chmax( T &a , T b ){ return a = max( a , b ); }

//const int dx[] = { 0 , 0 , 1 , -1 };
//const int dy[] = { -1 , 1 , 0 , 0 };
const int dx[] = { 1 , 1 , 0 , -1 , -1 , -1 , 0 , 1 };
const int dy[] = { 0 , -1 , -1 , -1 , 0 , 1 , 1 , 1 };
const ll LLINF = 1e16;
const int INF = 1e9;
const double EPS = 1e-2;

int n , m;
char field[2048][2048];

void dfs( int y , int x ){
  if( !( 0 <= y && y < n && 0 <= x && x < m ) ) return;

  int s = 0;
  for( int i = 0; i < 2; i++ )
    for( int j = 0; j < 2; j++ )
      if( field[y+i][x+j] == '.' ) s++;

  if( s == 3 ){
    for( int i = 0; i < 2; i++ )
      for( int j = 0; j < 2; j++ )
	field[y+i][x+j] = '.';

    for( int i = 0; i < 8; i++ )
      dfs( y+dy[i] , x+dx[i] );
  }
}

int main(){

  scanf( "%d %d" , &n , &m );

  for( int i = 0; i < n; i++ )
    scanf( "%s" , field[i] );

  for( int i = 0; i < n; i++ )
    for( int j = 0; j < m; j++ )
      dfs( i , j );

  for( int i = 0; i < n; i++ )
    printf( "%s\n" , field[i] );
      
  return 0;
}