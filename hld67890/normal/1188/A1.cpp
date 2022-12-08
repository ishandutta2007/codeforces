#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int d[120000];
void work () {
    int i , u , v;
    scanf ( "%d" , &n );
    for ( i = 1 ; i < n ; i++ ) {
        scanf ( "%d%d" , &u , &v );
        d[u]++;
        d[v]++;
    }
    for ( i = 1 ; i <= n ; i++ ) {
        if ( d[i] == 2 ) {
            printf ( "NO\n" );
            return ;
        }
    }
    printf ( "YES\n" );
}
int main () {
    work ();
    return 0;
}