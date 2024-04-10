#include "stdio.h"
#include "algorithm"
#include "utility"
#include "vector"

using namespace std;

typedef pair<int,int> P;

const int MAX_N = 100010;

int a[MAX_N];
int b[MAX_N];
vector<P> vec;

int main(){

  int n;
  scanf( "%d" , &n );

  for( int i = 0; i < n; i++ ){
    scanf( "%d %d" , &a[i] , &b[i] );
    vec.push_back( P( a[i] , b[i] ) );
  }

  sort( vec.begin() , vec.end() );

  bool f = true;
  for( int i = 0; i < n-1; i++ ){
    if( vec[i].second > vec[i+1].second ){
      f = false;
    }
  }

  if( f ){
    printf( "Poor Alex\n" );
  } else {
    printf( "Happy Alex\n" );
  }

  return 0;
}