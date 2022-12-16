#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

int n;
double p;
int t;

double np[2010];

int main(){

  scanf( "%d %lf %d" , &n , &p , &t );

  np[0] = 1.0;
  for( int i = 0; i < t; i++ ){
    np[n] = np[n] + np[n-1]*p;
    for( int j = n-1; j >= 0; j-- ){
      np[j] = np[j]*(1-p)+np[j-1]*p;
    }
  }

  double ans = 0.0;
  for( int i = 1; i <= n; i++ )
    ans += np[i]*i;

  printf( "%.8lf\n" , ans );
  
  return 0;
}