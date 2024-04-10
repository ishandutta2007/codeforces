#include "stdio.h"
#include "vector"
#include "algorithm"
#include "math.h"

using namespace std;

struct city{
  int x , y , p;
  city(){}
  city( int x , int y , int p ) : x(x) , y(y) , p(p) {}
  bool operator < ( const city a ) const {
    return (x*x)+(y*y) < (a.x*a.x)+(a.y*a.y);
  }
};

vector<city> cs;

int main(){

  FILE *fp = stdin;//fopen( "input.txt" , "r" );

  int n , k;
  fscanf( fp , "%d %d" , &n , &k );

  for( int i = 0; i < n; i++ ){
    int x , y , p;
    fscanf( fp , "%d %d %d" , &x , &y , &p );
    cs.push_back( city( x , y , p ) );
  }

  sort( cs.begin() , cs.end() );

  double ans = 0.0;
  for( int i = 0; i < n; i++ ){
    if( k >= 1000000 ) break;
    k += cs[i].p;
    ans = sqrt( (cs[i].x*cs[i].x)+(cs[i].y*cs[i].y) );
  }

  if( k >= 1000000 ) printf( "%.7lf\n" , ans );
  else printf( "-1\n" );


  return 0;
}