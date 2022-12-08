#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n , m;
char s[510000] , t[510000];
int nextt[510000];
int c0 , c1 , d0 , d1;
void work () {
    int i , j;
    scanf ( "%s" , s + 1 );
    scanf ( "%s" , t + 1 );
    n = strlen ( s + 1 );
    m = strlen ( t + 1 );
    nextt[1] = 0;
    j = 0;
    for ( i = 2 ; i <= m ; i++ ) {
        while ( j && t[i] != t[j+1] ) j = nextt[j];
        if ( t[i] == t[j+1] ) j++;
        nextt[i] = j;
    }
    //for ( i = 1 ; i <= m ; i++ ) printf ( "%d " , nextt[i] );
    for ( i = 1 ; i <= n ; i++ ) {
        if ( s[i] == '0' ) c0++;
        else c1++;
    }
    for ( i = 1 ; i <= m ; i++ ) {
        if ( t[i] == '0' ) d0++;
        else d1++;
    }
    if ( c0 < d0 || c1 < d1 ) {
        printf ( "%s\n" , s + 1 );
        return ;
    }
    printf ( "%s" , t + 1 );
    c0 -= d0;
    c1 -= d1;
    while ( 1 ) {
        for ( i = nextt[m] + 1 ; i <= m ; i++ ) {
            if ( t[i] == '0' ) {
                if ( c0 == 0 ) {
                    for ( j = 1 ; j <= c1 ; j++ ) printf ( "1" );
                    return ;
                }
                else {
                    c0--;
                    printf ( "0" );
                }
            }
            else {
                if ( c1 == 0 ) {
                    for ( j = 1 ; j <= c0 ; j++ ) printf ( "0" );
                    return ;
                }
                else {
                    c1--;
                    printf ( "1" );
                }
            }
        }
    }
}
int main () {
    work ();
    return 0;
}