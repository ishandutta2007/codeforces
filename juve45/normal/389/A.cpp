#include <iostream>
#include <algorithm>

using namespace std ;

int  main()
{
  int n , a[110] ;
  cin >> n >> a[0] ;
  for ( int i = 1 ; i < n ; i++ )
    {
      cin>> a[i] ;
      a[0] = __gcd ( a[0] , a[i] ) ;
    }
  cout << a[0] * n ;
  return 0 ;
}