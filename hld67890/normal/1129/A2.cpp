#include <stdio.h>
#include <algorithm>

using namespace std;

int n , m;
int num[5100] , best[5100];
int tot , total , ok[5100] , so;
int now , to[5100] , vis[5100];
int ans , sum;
int get ( int i , int a , int b ) {
    if ( a < i && b < i ) return min ( a , b );
    if ( a < i && b > i ) return b;
    if ( b < i && a > i ) return a;
    return min ( a , b );
}
int bet ( int i , int j ) {
    if ( j < best[j] && j < i && i < best[j] ) return 1;
    if ( j > best[j] && (i > j || i < best[j]) ) return 1;
    return 0;
}
void work () {
    int i , j , u , v;
    scanf ( "%d%d" , &n , &m );
    for ( i = 1 ; i <= m ; i++ ) {
        scanf ( "%d%d" , &u , &v );
        num[u]++;
        if ( best[u] == 0 ) best[u] = v;
        else best[u] = get ( u , best[u] , v );
        ans = max ( ans , num[u] );
    }
    //printf ( "%d\n" , ans );
    for ( i = 1 ; i <= n ; i++ ) {
        if ( num[i] == ans ) total++;
        //printf ( "%d %d\n" , i , num[i] );
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= n ; j++ ) to[j] = vis[j] = 0;
        so = 0;
        for ( j = 1 ; j <= n ; j++ ) {
            if ( num[j] && num[j] == ans - 1 && bet ( i , j ) ) {
                //printf ( "%d\n" , best[j] );
                to[best[j]]++;
                so++;
            }
        }
        now = 0;
        j = i;
        sum = 0;
        while ( now < total + so ) {
            if ( to[j] ) {
                now += to[j];
                to[j] = 0;
            }
            //printf ( "%d %d %d\n" , j , now , total  + so );
            if ( now >= total + so ) break;
            if ( num[j] == ans && !vis[j] ) {
                to[best[j]]++;
                vis[j] = 1;
                //printf ( "%d %d\n" , best[j] , to[best[j]] );
            }
            j++;
            if ( j == n + 1 ) j = 1;
            sum++;
        }
        printf ( "%d " , (ans-1) * n + sum );
    }
}
int main () {
    work ();
    return 0;
}