#include "stdio.h"
#include "algorithm"
#include "functional"

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

char str[100010];
int cnt[4] = {};


int main(){

  int n;
  scanf( "%d\n" , &n );

  scanf( "%s" , str );


  for( int i = 0; i < n; i++ ){
    if( str[i] == 'A' ) cnt[0]++;
    if( str[i] == 'G' ) cnt[1]++;
    if( str[i] == 'C' ) cnt[2]++;
    if( str[i] == 'T' ) cnt[3]++;
  }

  sort( cnt , cnt+4 , greater<int>() );

  ll ty;
  if( cnt[0] == cnt[1] && cnt[0] == cnt[2] && cnt[0] == cnt[3] ) ty = 4;
  else if( cnt[0] == cnt[1] && cnt[0] == cnt[2] ) ty = 3;
  else if( cnt[0] == cnt[1] ) ty = 2;
  else ty = 1;

  ll ans = 1;
  for( int i = 0; i < n; i++ )
    ans = (ans*ty)%MOD;

  printf( "%I64d\n" , ans );

  return 0;
}