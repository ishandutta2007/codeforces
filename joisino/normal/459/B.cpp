#include "stdio.h"
#include "algorithm"
#include "math.h"

using namespace std;


typedef long long int ll;
const int INF = 1000000010;

int n;
int b;

int bv = -INF;
int bn = 0;

int sv = INF;
int sn = 0;

int main(){

  scanf( "%d" , &n );
  for( int i = 0; i < n; i++ ){
    scanf( "%d" , &b );

    if( b > bv ){
      bv = b;
      bn = 1;
    } else if( b == bv ){
      bn++;
    }

    if( b < sv ){
      sv = b;
      sn = 1;
    } else if( b == sv ){
      sn++;
    }
  }

  ll pat = (ll)bn*(ll)sn;

  if( bv == sv ){
    pat = (ll)bn*((ll)bn-1)/2;
  }

  printf( "%d %I64d\n" , bv-sv , pat );



  return 0;
}