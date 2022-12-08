#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

//long long
long long n;
multiset < long long > s[40];
long long sum[40];
long long po[40];
long long belong ( long long x ) {
    long long i;
    for ( i = 0 ; i <= 32 ; i++ ) {
        if ( x <= po[i] ) return i;
    }
}
void work () {
    long long i , j , x , b , cnt , tot;
    char op[20];
    scanf ( "%lld" , &n );
    po[0] = 1;
    for ( i = 1 ; i <= 32 ; i++ ) po[i] = po[i-1] * 2;
    tot = 0;
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%s%lld" , op + 1 , &x );
        b = belong ( x );
        if ( op[1] == '+' ) {
            s[b].insert ( x );
            for ( j = b ; j <= 32 ; j++ ) {
                sum[j] += x;
            }
            tot++;
        }
        else {
            s[b].erase ( s[b].find ( x ) );
            for ( j = b ; j <= 32 ; j++ ) {
                sum[j] -= x;
            }
            tot--;
        }
        cnt = 0;
        for ( j = 0 ; j <= 32 ; j++ ) {
            if ( s[j].size () != 0 ) {
                if ( (*s[j].begin ()) > (j==0?0ll:sum[j-1]) * 2ll ) cnt++;
            }
        }
        printf ( "%lld\n" , tot - cnt );
    }
}
int main () {
    work ();
    return 0;
}