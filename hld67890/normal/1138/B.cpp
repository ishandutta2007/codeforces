#include <stdio.h>
#include <algorithm>

using namespace std;

const int del = 5001;
int n;
char arco[5200] , cl[5200];
int a , b , c , d;
int outa , outb , outc , outd;
void work () {
    int i , j , a1 , a2 , b1 , b2 , c1 , c2 , d1 , d2;
    scanf ( "%d" , &n );
    scanf ( "%s" , cl + 1 );
    scanf ( "%s" , arco + 1 );
    for ( i = 1 ; i <= n ; i++ ) {
        if ( arco[i] == '1' && cl[i] == '1' ) d++;
        if ( arco[i] == '1' && cl[i] == '0' ) c++;
        if ( arco[i] == '0' && cl[i] == '1' ) b++;
        if ( arco[i] == '0' && cl[i] == '0' ) a++;
    }
    for ( i = 0 ; i <= b ; i++ ) {
        for ( j = 0 ; j <= c ; j++ ) {
            b1 = i; c2 = j;
            b2 = b - i; c1 = c - j;
            if ( (c2 + d - b1) % 2 != 0 ) continue;
            d1 = (c2+d-b1) / 2;
            d2 = d - d1;
            a1 = n/2 - b1 - c1 - d1;
            a2 = a - a1;
            if ( a1 < 0 || a1 > a ) continue;
            if ( a2 < 0 || a2 > a ) continue;
            if ( b1 < 0 || b1 > b ) continue;
            if ( b2 < 0 || b2 > b ) continue;
            if ( c1 < 0 || c1 > c ) continue;
            if ( c2 < 0 || c2 > c ) continue;
            if ( d1 < 0 || d1 > d ) continue;
            if ( d2 < 0 || d2 > d ) continue;
            for ( i = 1 ; i <= n ; i++ ) {
                if ( arco[i] == '1' && cl[i] == '1' ) {
                    if ( outd >= d1 ) continue;
                    outd++;
                    printf ( "%d " , i );
                }
                if ( arco[i] == '1' && cl[i] == '0' ) {
                    if ( outc >= c1 ) continue;
                    outc++;
                    printf ( "%d " , i );
                }
                if ( arco[i] == '0' && cl[i] == '1' ) {
                    if ( outb >= b1 ) continue;
                    outb++;
                    printf ( "%d " , i );
                }
                if ( arco[i] == '0' && cl[i] == '0' ) {
                    if ( outa >= a1 ) continue;
                    outa++;
                    printf ( "%d " , i );
                }
            }
            return ;
        }
    }
    printf ( "-1\n" );
}
int main () {
    work ();
    return 0;
}