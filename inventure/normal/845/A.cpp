#include <bits/stdc++.h>

using namespace std;

int n , a[222];

int main( int argc , char * argv[] ){
    cin >> n ;
    for(int i = 1 ; i <= (n << 1) ; ++ i)
        cin >> a[i];
    sort( a + 1 , a + (n << 1) + 1 );
    for(int i = n + 1 , j = n ; j >= 1 ; ++ i , -- j)
        if( a[i] <= a[j] ){
            puts( "NO" );
            return 0;
        }
    puts( "YES" );
    return 0;
}