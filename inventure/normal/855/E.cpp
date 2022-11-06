#include <bits/stdc++.h>

using namespace std;

long long dp[11][70][1 << 10];
int F[55] , len;

long long Dfs( int base , int x , int f , int mask ){
    if( x == -1 ) return mask == 0;
    if( f == 1 && ~dp[base][x][mask] )
        return dp[base][x][mask];
    long long ret = 0;
    int ed = f ? base - 1 : F[x];
    for(int i = 0 ; i <= ed ; ++ i) ret += Dfs( base , x - 1 , f | (i < ed) , mask ^ (1 << i) );
    if( f == 1 ) dp[base][x][mask] = ret;
    return ret;
}

long long Solve( long long n , int b ){
    if( n == 0 ) return 0;
    len = 0;
    while( n ){
        int x = n % b;
        F[len ++] = x;
        n /= b;
    }
    long long ret = 0;
    for(int i = 1 ; i <= F[len - 1] ; ++ i)
        ret += Dfs( b , len - 2 , i < F[len - 1] , 1 << i );
    for(int i = 1 ; i < len ; ++ i)
        for(int j = 1 ; j < b ; ++ j)
            ret += Dfs( b , i - 2 , 1 , 1 << j );
    return ret;
}


int main( int argc , char * argv[] ){
    memset( dp , -1 , sizeof( dp ) );
    int T;
    scanf( "%d" , & T );
    while( T -- ){
        int b;
        long long l , r;
        scanf( "%d%lld%lld" , & b , & l , & r );
        printf( "%lld\n" , Solve( r , b ) - Solve( l - 1 , b ) );
    }
    return 0;
}