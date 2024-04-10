#include "stdio.h"
#include "string.h"
#include "algorithm"

using namespace std;

const int MAX_N = 1010;

char a[MAX_N];
char b[MAX_N];

int cnta[26] = {};
int cntb[26] = {};

int main(){

  //FILE *fp = fopen( "garland.in" , "r" );
  scanf( "%s\n" , a );
  scanf( "%s" , b );

  int lena = strlen( a );
  for( int i = 0; i < lena; i++ )
    cnta[ a[i]-'a' ]++;

  int lenb = strlen( b );
  for( int i = 0; i < lenb; i++ )
    cntb[ b[i]-'a' ]++;

  bool ok = true;

  int ans = 0;
  for( int i = 0; i < 26; i++ ){
    ans += min( cnta[i] , cntb[i] );
    if( cntb[i] != 0 && cnta[i] == 0 ) ok = false;
  }

  if( !ok ) printf( "-1\n" );
  else printf( "%d\n" , ans );

  return 0;
}