#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll MOD = 1000000007;

mat matmal( mat a , mat b ){
  mat c = mat( a.size() , vec(b[0].size()) );
  for( int i = 0; i < c.size(); i++ )
    for( int j = 0; j < c[i].size(); j++ )
      for( int k = 0; k < a[i].size(); k++ )
	c[i][j] = (c[i][j]+a[i][k]*b[k][j])%MOD;
  return c;
}

mat matpow( mat x , ll k ){
  mat res = mat( x.size() , vec(x[0].size()) );
  for( int i = 0; i < res.size(); i++ )
    res[i][i] = 1;
  while( k > 0 ){
    if( k & 1 ){
      res = matmal( res , x );
    }
    x = matmal( x , x );
    k /= 2;
  }
  return res;
}

int c[128];

int main(){

  int n;
  ll x;
  scanf( "%d %I64d" , &n , &x );

  for( int i = 0; i < n; i++ ){
    int a;
    scanf( "%d" , &a );
    c[a]++;
  }
  
  mat d = mat( 101 , vec(1) );
  d[0][0] = 1;
  d[100][0] = 1;

  mat a = mat( 101 , vec(101) );
  for( int j = 0; j < 100; j++ )
    a[0][j] = c[j+1];
  for( int i = 1; i < 100; i++ )
    a[i][i-1] = 1;
  a[0][100] = 1;
  a[100][100] = 1;
  

  a = matpow( a , x );

  /*

  mat e = mat( 101 , vec(101) );
  for( int i = 0; i < 101; i++ )
    e[i][i] = 1;
  
  mat b = matpow( a , 1 );
  
  for( int i = 0; i < 10; i++ ){
    for( int j = 0; j < 10; j++ )
      printf( "%d " , b[i][j] );
    printf( "\n" );
  }
  return 0;

  */
   
  mat res = matmal( a , d );

  /*
  for( int i = 0; i < 10; i++ )
    printf( "%I64d\n" , res[i][0] );
  */

  printf( "%I64d\n" , res[0][0] );
  
  return 0;
}