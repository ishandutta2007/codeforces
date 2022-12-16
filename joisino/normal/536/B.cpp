#include "bits/stdc++.h"

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)

#define pb push_back

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

const ll MOD = 1000000007;
const ll RHMOD = 87687691;
const ll B = 727272727;


int n, m;

char str[1000010];
int len;

int a[1000010];

ll e[1000010];
ll lrh[1000010], rrh[1000010];

bool ok;
ll sum[1000010];

void construct_RH(){
  e[0] = 1;
  FOR( i , 1 , len )
    e[i] = ( e[i-1] * B ) % RHMOD;
  
  lrh[0] = str[0];
  FOR( i , 1 , len )
    lrh[i] = ( lrh[i-1] * B + ll(str[i]) ) % RHMOD;

  rrh[len-1] = lrh[len-1];
  for( int i = len-2; i >= 0; i-- )
    rrh[i] = ( rrh[i+1] - ll(str[len-2-i]) * e[i+1] + RHMOD*RHMOD ) %RHMOD;
}


int main(){

  scanf( "%d %d" , &n , &m );
  scanf( "%s" , str );

  REP( i , m )
    scanf( "%d" , &a[i] );

  len = strlen( str );

  construct_RH();
  
  if( m > 0 ){
    sum[ a[0] ]++;
    sum[ a[0] + len ]--;
  }

  ok = true;
  FOR( i , 1 , m ){
    int d = a[i-1]+len - a[i];
    if( d > 0 && rrh[d-1] != lrh[d-1] ) ok = false;
    sum[ a[i] ]++;
    sum[ a[i] + len ]--;
  }


  FOR( i , 1 , n+1 )
    sum[i] += sum[i-1];

  ll ans = 1;
  FOR( i , 1 , n+1 )
    if( sum[i] == 0 ) ans = (ans*26) % MOD;

  if( ok )  printf( "%I64d\n" , ans );
  else printf( "0\n" );

  return 0;
}