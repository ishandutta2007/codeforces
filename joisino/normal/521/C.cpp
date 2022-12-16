#include "stdio.h"
#include "algorithm"
#include "string"

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

ll ex[100010];
char str[100010];

ll d[100010];
ll sum[100010];

ll bikkuri[100010];

ll modpow( ll x , ll k ){
  ll res = 1;
  while( k > 0 ){
    if( k % 2 == 1 ){
      res *= x;
      res %= MOD;
    }
    x *= x;
    x %= MOD;
    k /= 2;
  }
  return res;
}

ll ncr( ll n , ll r ){
  ll res = bikkuri[n];
  res *= modpow( bikkuri[r] , MOD-2 );
  res %= MOD;
  res *= modpow( bikkuri[n-r] , MOD-2 );
  return res%MOD;
}

int main(){

  bikkuri[0] = 1;
  for( int i = 1; i < 100010; i++ )
    bikkuri[i] = (bikkuri[i-1]*i)%MOD;

  /*
  for( int i = 0; i < 4; i++ ){
    for( int j = 0; j <= i; j++ ){
      printf( "%d " , ncr(i,j) );
    }
    printf( "\n" );
  }
  return 0;
  */

  int n , k;
  scanf( "%d %d\n" , &n , &k );

  scanf( "%s" , str );

  for( int i = 0; i < n; i++ )
    d[i] = (ll)(str[i]-'0');

  sum[0] = d[0];
  for( int i = 1; i < n; i++ )
    sum[i] = sum[i-1]+d[i];

  ll ans = 0;
  ll kur = 1;
  for( int i = 0; i < n-k; i++ ){
    ans += ((sum[n-2-i]*kur)%MOD)*ncr( n-2-i , k-1 );
    //printf( "%lld %lld %lld\n" , sum[n-2-i] , kur , ncr(n-2-i,k-1) );
    ans %= MOD;
    kur *= 10;
    kur %= MOD;
  }

  //printf( "%d\n" , ans );

  kur = 1;
  for( int i = n-1; i >= k; i-- ){
    ans += ((d[i]*kur)%MOD)*ncr(i,k);
    ans %= MOD;
    kur *= 10;
    kur %= MOD;
  }

  printf( "%I64d\n" , ans );

  return 0;
}