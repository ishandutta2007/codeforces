#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
    int a , i;
} t[1020];
int n;
int s;
bool cmp ( node x1 , node x2 ) {
    return x1.a < x2.a;
}
void work () {
    int i , ts = 0;
    scanf ( "%d" , &n );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &t[i].a );
        s += t[i].a;
        t[i].i = i;
    }
    int num = 0;
    sort ( t + 2 , t + n + 1 , cmp );
    for ( i = 2 ; i <= n ; i++ ) {
        if ( t[i].a * 2 <= t[1].a ) {
            ts += t[i].a;
            num++;
        }
    }
    ts += t[1].a;
    if ( ts * 2 > s ) {
        printf ( "%d\n" , num + 1 );
        for ( i = 1 ; i <= n ; i++ ) {
            if ( t[i].a * 2 <= t[1].a ) {
                printf ( "%d " , t[i].i );
            }
        }
        printf ( "1\n" );
    }
    else {
        printf ( "0\n" );
    }
}
int main () {
    work ();
    return 0;
}