#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
    int a , i;
} s[1200];
int n , m;
int a[1200][1200];
int rrank[1200][1200];
int crank[1200][1200];
int r[1200] , c[1200];
int ans[1200][1200];
bool cmp ( node x1 , node x2 ) {
    return x1.a < x2.a;
}
void work () {
    int i , j;
    scanf ( "%d%d" , &n , &m );
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= m ; j++ ) {
            scanf ( "%d" , &a[i][j] );
        }
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= m ; j++ ) {
            s[j].i = j;
            s[j].a = a[i][j];
        }
        sort ( s + 1 , s + 1 + m , cmp );
        for ( j = 1 ; j <= m ; j++ ) {
            if ( s[j].a != s[j-1].a ) r[i]++;
            rrank[i][s[j].i] = r[i];
        }
    }
    for ( i = 1 ; i <= m ; i++ ) {
        for ( j = 1 ; j <= n ; j++ ) {
            s[j].i = j;
            s[j].a = a[j][i];
        }
        sort ( s + 1 , s + 1 + n , cmp );
        for ( j = 1 ; j <= n ; j++ ) {
            if ( s[j].a != s[j-1].a ) c[i]++;
            crank[s[j].i][i] = c[i];
        }
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= m ; j++ ) {
            //printf ( "%d " , crank[i][j] );
            printf ( "%d%c" , max(rrank[i][j]-1,crank[i][j]-1) + max (r[i]-rrank[i][j],c[j]-crank[i][j]) + 1 , j==m?'\n':' ' );
        }
        //printf ( "\n" );
    }
}
int main () {
    work ();
    return 0;
}