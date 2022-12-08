#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char z[1200000];
char s[1200000];
int f[1200000];
int n;
int flag;
void work () {
    int i , j , k;
    scanf ( "%s" , z + 1 );
    n = strlen ( z + 1 );
    j = n;
    flag = 0;
    k = 0;
    for ( i = 1 ; i <= (n+1) / 2 ; i++ ) {
        if ( z[i] == z[j] ) {
            //s[++k] = z[i];
            f[i] = 1;
            f[j] = 1;
            //if ( i == j ) flag = 1;
        }
        else {
            if ( z[i+1] != z[j-1] ) {
                if ( z[i+1] == z[j] ) {
                    f[i+1] = 1; f[j] = 1;
                }
                else {
                    f[i] = 1; f[j-1] = 1;
                }
                i++;j--;
                //s[++k] = z[i];
                //if ( i + 1 == j ) flag = 1;
            }
        }
        j--;
    }
    /*printf ( "%s" , s + 1 );
    for ( i = k - flag ; i >= 1 ; i-- ) {
        printf ( "%c" , s[i] );
    }*/
    for ( i = 1 ; i <= n ; i++ ) {
        if ( f[i] == 1 ) printf ( "%c" , z[i] );
    }
}
int main () {
    work ();
    return 0;
}