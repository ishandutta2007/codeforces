#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int a[120000];
int ans , x[333];
int main () {
    int i;
    scanf ( "%d" , &n );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] );
        if ( a[i] == a[i-1] ) {
            x[a[i]]++;
        }
        else {
            ans = max ( ans , min ( x[1] , x[2] ) );
            x[a[i]] = 1;
        }
    }
    ans = max ( ans , min ( x[1] , x[2] ) );
    printf ( "%d\n" , ans * 2 );
    return 0;
}