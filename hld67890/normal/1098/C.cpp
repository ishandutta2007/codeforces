#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

//long long
const long long maxn = 120000;
long long n;
long long s;
queue < long long > q[maxn];
long long fa[maxn] , left[maxn] , d[maxn];
long long check ( long long x , long long out ) {
    long long i , j , lim , t , dep , nowd;
    long long ret;
    if ( s > (long long)n * (n+1) / 2 ) return 0;
    lim = 1;
    t = 1;
    dep = 1;
    ret = 0;
    for ( i = 1 ; i <= n ; i++ ) {
        if ( t == 0 ) {
            lim = lim * x;
            t = lim;
            dep++;
        }
        t--;
        ret += dep;
    }
    if ( ret > s ) return 0;
    //if ( x == 3 ) printf ( "%lld\n" , ret );
    if ( out == 1 ) {
        ret = (long long)n * (n+1) / 2;
        for ( i = 2 ; i <= n ; i++ ) {
            fa[i] = i - 1;
            left[i] = x - 1;
        }
        left[1] = x - 1;
        left[n] = x;
        for ( i = 1 ; i <= n ; i++ ) {
            q[i].push ( i );
        }
        i = n; nowd = 1;
        while ( ret > s && i > 0 ) {
            //printf ( "%lld %lld %lld\n" , ret , s , i );
            if ( i <= nowd ) break;
            if ( ret - s >= i - nowd - 1 ) {
                ret -= i - nowd - 1;
                fa[i] = q[nowd].front ();
                left[q[nowd].front()]--;
                q[nowd+1].push ( i );
                left[i] = x;
                if ( left[q[nowd].front()] == 0 ) q[nowd].pop ();
                if ( q[nowd].size () == 0 ) nowd++;
            }
            else {
                fa[i] = q[i-(ret-s)-1].front ();
                ret = s;
            }
            i--;
        }
        printf ( "Yes\n" );
        for ( i = 2 ; i <= n ; i++ ) {
            printf ( "%lld%c" , fa[i] , i==n?'\n':' ' );
        }
    }
    return 1;
}
void work () {
    long long l , r , mid;
    scanf ( "%lld%lld" , &n , &s );
    l = 0; r = n;
    if ( check ( n , 0 ) == 0 ) {
        printf ( "No\n" );
        return ;
    }
    while ( l < r - 1 ) {
        mid = (l+r)/2;
        if ( check ( mid , 0 ) == 1 ) r = mid;
        else l = mid;
    }
    check ( r , 1 );
}
int main () {
    //freopen ( "out.out" , "w" , stdout );
    work ();
    return 0;
}