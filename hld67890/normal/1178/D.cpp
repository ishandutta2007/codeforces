#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int top;
int u[120000] , v[120000];
int d[12000];
int blo[12000];
void add ( int a , int b ) {
    top++;
    u[top] = a;
    v[top] = b;
    d[a]++;
    d[b]++;
}
void add1 ( int base , int x ) {
    int i , j;
    if ( x == 9 ) {
        for ( i = 1 ; i <= 6 ; i++ ) {
            for ( j = i + 2 ; j <= 6 ; j++ ) {
                if ( i == 1 && j == 6 ) continue;
                add ( base + i , base + j );
            }
        }
    }
    else {
        if ( x <= 3 ) {
            for ( i = 1 ; i <= x ; i++ ) {
                add ( base + i , base + i + 3 );
            }
        }
        else {
            if ( x == 4 ) {
                add(base+1,base+3);
                add(base+1,base+4);
                add(base+1,base+5);
                add(base+2,base+6);
            }
            if ( x == 5 ) {
                add(base+1,base+3);
                add(base+1,base+4);
                add(base+1,base+5);
                add(base+2,base+4);
                add(base+4,base+6);
            }
            if ( x == 6 ) {
                add(base+1,base+3);
                add(base+1,base+4);
                add(base+1,base+5);
                add(base+2,base+5);
                add(base+3,base+5);
                add(base+3,base+6);
            }
        }
    }
}
void work () {
    int i , j;
    scanf ( "%d" , &n );
    if ( n <= 5 ) {
        if ( n == 3 ) {
            printf ( "3\n" );
            printf ( "1 2\n" );
            printf ( "1 3\n" );
            printf ( "2 3\n" );
        }
        if ( n == 4 ) {
            printf ( "5\n" );
            printf ( "1 2\n" );
            printf ( "1 3\n" );
            printf ( "2 3\n" );
            printf ( "2 4\n" );
            printf ( "3 4\n" );
        }
        if ( n == 5 ) {
            printf ( "5\n" );
            printf ( "1 2\n" );
            printf ( "2 3\n" );
            printf ( "3 4\n" );
            printf ( "4 5\n" );
            printf ( "5 1\n" );
        }
        return ;
    }
    for ( i = n ; i <= n * 2 ; i++ ) {
        for ( j = 2 ; j < i ; j++ ) {
            if ( i % j == 0 ) {
                break;
            }
        }
        if ( j == i ) break;
    }
    m = i;
    m -= n;
    int k = 1;
    for ( i = 1 ; i <= n ; i += 6 , k++ ) {
        for ( j = i ; j <= i + 5 && j <= n ; j++ ) {
            blo[j] = i;
        }
    }
    if ( n % 6 == 1 ) {
        blo[n] -= 6;
    }
    if ( n % 6 == 2 ) {
        blo[n] -= 6;
        blo[n-1] -= 6;
    }
    for ( i = 1 ; i <= n ; i++ ) {
        if ( blo[i+1] != blo[i] ) {
            add ( i , blo[i] );
            continue;
        }
        add ( i , i + 1 );
    }
    //printf ( "%d\n" , top );
    for ( i = 6 ; i <= n ; i += 6 ) {
        if ( m >= 9 ) {
            add1 ( i-6 , 9 );
            m -= 9;
        }
        else {
            if ( m == 7 || m == 8 ) {
                add1 ( i-6 , 6 );
                m -= 6;
            }
            else {
                add1 ( i-6 , m );
                m = 0;
            }
        }
    }
    if ( m != 0 ) printf ( "-1\n" );
    else {
        printf ( "%d\n" , top );
        for ( i = 1 ; i <= top ; i++ ) {
            printf ( "%d %d\n" , u[i] , v[i] );
        }
    }
    //for ( i = 1 ; i <= n ; i++ )
    //    printf ( "%d " , d[i] );
}
int main () {
    work ();
    return 0;
}