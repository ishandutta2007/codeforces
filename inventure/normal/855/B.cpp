#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;
const long long inf = 1LL << 62;

int n , p , q , r , a[maxn];

long long dp[maxn][3];

inline void Update( long long & x , long long v ){
    x = max( x , v );
}

int main( int argc , char * argv[] ){
    scanf( "%d%d%d%d" , & n , & p , & q , & r );
    for(int i = 1 ; i <= n ; ++ i) scanf( "%d" , a + i );
    for(int i = 0 ; i <= n ; ++ i) for(int j = 0 ; j < 3 ; ++ j) dp[i][j] = -inf;
    dp[0][0] = 0;
    long long ans = -inf;
    for(int i = 0 ; i < n ; ++ i)
        for(int j = 0 ; j < 3 ; ++ j)
            if( dp[i][j] != -inf ){
                Update( dp[i + 1][j] , dp[i][j] );
                if( j == 0 ) Update( dp[i][j + 1] , dp[i][j] + 1LL * a[i + 1] * p );
                else if( j == 1 ) Update( dp[i][j + 1] , dp[i][j] + 1LL * a[i + 1] * q );
                else Update( ans , dp[i][j] + 1LL * a[i + 1] * r );
            }
    printf( "%lld\n" , ans );
    return 0;
}