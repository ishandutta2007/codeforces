#include "stdio.h"
#include "algorithm"

using namespace std;

typedef long long int ll;

const int MAX_N = 100010;
const int INF = 2000000000;

int n , m , w;
int a[MAX_N];

ll bit[2][MAX_N*2];
int size;
void init( int s ){
  size = 1;
  while( size < s ) size *= 2;
  for( int i = 0; i < size; i++ ) bit[0][i] = bit[1][i] = 0;
}
void badd( int t , int k , ll x ){
  while( k <= size ){
    bit[t][k] += x;
    k += k & -k;
  }
}
ll bsum( int t , int k ){
  ll res = 0;
  while( k > 0 ){
    res += bit[t][k];
    k -= k & -k;
  }
  return res;
}
void add( int a , int b , ll x ){
  a++; b++;
  badd( 1 , a , x );
  badd( 1 , b , -x );
  badd( 0 , a , (1-a)*x );
  badd( 0 , b , (b-1)*x );
}
ll sum( int k ){
  k++;
  return bsum(0,k) + bsum(1,k)*k;
}
ll get( int k ){
  return sum(k) - sum(k-1);
}


int main(){

  scanf( "%d %d %d" , &n , &m , &w );

  for( int i = 0; i < n; i++ ){
    scanf( "%d" , &a[i] );
  }


  ll lb = -1 , ub = INF;
  while( ub - lb > 1 ){
    ll md = (lb+ub)/2;
    ll passed = 0;

    init( n+10 );
    for( int i = 0; i < n; i++ ){
      add( i , i+1 , a[i] );
    }
    for( int i = 0; i < n; i++ ){
      ll gi = get(i);
      if( gi < md ){
	passed += md-gi;
	add( i , min(n,i+w) , md-gi );
      }
    }
    if( passed <= (ll)m ) lb = md;
    else ub = md;

  }

  printf( "%d\n" , lb );

  return 0;
}