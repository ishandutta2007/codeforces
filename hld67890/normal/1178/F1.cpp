#include <stdio.h>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
long long n , m;
long long a[12000];
long long l[1200] , r[1200];
long long dp[510][510];
void work () {
    long long i , j , k , minn , tmp1 , tmp2;
    scanf ( "%lld%lld" , &n , &m );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] );
        l[a[i]] = r[a[i]] = i;
    }
    for ( i = 0 ; i <= n + 1 ; i++ ) {
        for ( j = i + 1 ; j <= n + 1 ; j++ ) dp[j][i] = 1;
    }
    for ( long long st = 1 ; st <= n ; st++ ) {
        for ( i = 1 ; i + st - 1 <= n ; i++ ) {
            j = i + st - 1;
            if ( i == j ) {
                dp[i][j] = 1;
                continue;
            }
            minn = i;
            for ( k = i + 1 ; k <= j ; k++ ) {
                if ( a[k] < a[minn] ) minn = k;
            }
            tmp1 = tmp2 = 0;
            for ( k = minn ; k <= j ; k++ ) {
                tmp1 = (tmp1 + dp[minn+1][k] * dp[k+1][j] ) % mod;
            }
            for ( k = i ; k <= minn ; k++ ) {
                tmp2 = (tmp2 + dp[k][minn-1] * dp[i][k-1] ) % mod;
            }
            dp[i][j] = (tmp1*tmp2) % mod;
            //printf ( "%lld %lld %lld %lld\n" , i , j , tmp1 , tmp2 );
        }
    }
    printf ( "%lld\n" , dp[1][n] );
}
int main () {
    work ();
    return 0;
}