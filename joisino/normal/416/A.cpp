#include "stdio.h"
#include "string.h"
#include "algorithm"

using namespace std;

int main(){

  FILE *fp = stdin;//fopen( "input.txt" , "r" );

  int n;
  fscanf( fp , "%d" , &n );

  int lb = -2000000000 , ub = 2000000000;

  bool ok = true;


  for( int i = 0; i < n; i++ ){
    char s[5];
    int sign;
    int k;
    char a;
    fscanf( fp , "%s %d %c\n" , s , &k , &a );
    //printf( "%s %d %c" , s , k , a );
    if( strlen(s) == 2 && s[0] == '>' ){
      sign = 2;
    }
    if( strlen(s) == 1 && s[0] == '>' ){
      sign = 1;
    }
    if( strlen(s) == 2 && s[0] == '<' ){
      sign = -2;
    }
    if( strlen(s) == 1 && s[0] == '<' ){
      sign = -1;
    }
    if( a == 'N' ){
      if( sign == -2 ) sign = 1;
      else if( sign == -1 ) sign = 2;
      else if( sign == 1 ) sign = -2;
      else if( sign == 2 ) sign = -1;
    }

    if( sign == 1 ){
      sign = 2;
      k++;
    }
    if( sign == -1 ){
      sign = -2;
      k--;
    }

    if( sign == 2 ){
      if( ub < k ){
	printf( "Impossible\n" );
	ok = false;
	break;
      }
      lb = max( lb , k );
    }

    if( sign == -2 ){
      if( lb > k ){
	printf( "Impossible\n" );
	ok = false;
	break;
      }
      ub = min( ub , k );
    }
  }

  if( ok ) printf( "%d\n" , lb );

}