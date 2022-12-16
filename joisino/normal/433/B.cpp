#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

typedef long long int ll;

const int MAX_N = 100010;

struct Bit{
  ll bit[MAX_N*2] , size;
  void init( int s ){
    size = 1;
    while( size < s ) size *= 2;
    for( int i = 0; i < size; i++ ) bit[i] = 0;
  }
  void add( int k , ll x ){
    while( k <= size ){
      bit[k] += x;
      k += k & -k;
    }
  }
  ll sum( int k ){
    ll res = 0;
    while( k > 0 ){
      res += bit[k];
      k -= k & -k;
    }
    return res;
  }
};

Bit no , so;

int v[MAX_N];

int main(){

  int n;
  scanf( "%d" , &n );

  no.init( n );
  so.init( n );

  for( int i = 1; i <= n; i++ ){
    scanf( "%d" , &v[i] );
    no.add( i , v[i] );
  }

  sort( v+1 , v+n+1 );
  for( int i = 1; i <= n; i++ ){
    so.add( i , v[i] );
  }

  int q;
  scanf( "%d" , &q );

  for( int i = 0; i < q; i++ ){
    int t , a , b;
    scanf( "%d %d %d" , &t , &a , &b );
    if( t == 1 ){
      printf( "%I64d\n" , no.sum(b) - no.sum(a-1) );
    } else if( t == 2 ){
      printf( "%I64d\n" , so.sum(b) - so.sum(a-1) );
    }
  }

  return 0;
}