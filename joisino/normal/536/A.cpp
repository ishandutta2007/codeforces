#include "bits/stdc++.h"

typedef long long int ll;

ll a , b , n;

ll s( ll k ){
  return a+(k-1)*b;
}

ll sum( ll k ){
  return k*(s(k)+a)/2;
}

int main(){

  scanf( "%I64d %I64d %I64d" , &a , &b , &n );

  for( int i = 0; i < n; i++ ){
    ll l , t , m;
    scanf( "%I64d %I64d %I64d" , &l , &t , &m );

    ll lb = -1 , ub = 1e10;
    while( ub - lb > 1 ){
      ll md = (lb+ub)/2;
      if( s(md) <= t && sum(md)-sum(l-1) <= m*t ) lb = md;
      else ub = md;
    }
    if( lb >= l ) printf( "%I64d\n" , lb );
    else printf( "-1\n" );
  }
  
  return 0;
}