#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;

inline void Update( int & x , int y ){
    x += y;
    if( x >= mod )
        x -= mod;
}

int n , m , dp[maxn][3][11] , temp[3][11] , K , X;
vector < int > G[maxn];

void Dfs( int u , int fa = 0 ){
    dp[u][0][0] = K - 1;
    dp[u][1][1] = 1;
    dp[u][2][0] = m - K;
    for(auto && v : G[u]){
        if( v == fa )
            continue;
        Dfs( v , u );
        memset( temp , 0 , sizeof( temp ) );
        for(int j = 0 ; j < 3 ; ++ j)
            for(int k = 0 ; k <= X ; ++ k)
                if( dp[u][j][k] )
                    for(int f = 0 ; f < 3 ; ++ f)
                        for(int w = 0 ; w + k <= X ; ++ w)
                            if( dp[v][f][w] ){
                                if( j == 1 && f >= 1 ) continue;
                                if( f == 1 && j >= 1 ) continue;
                                Update( temp[j][w + k] , 1LL * dp[u][j][k] * dp[v][f][w] % mod );
                            }
        for(int j = 0 ; j < 3 ; ++ j)
            for(int k = 0 ; k <= X ; ++ k)
                dp[u][j][k] = temp[j][k];
    }
}


int main( int argc , char * argv[] ){
    scanf( "%d%d" , & n , & m );
    for(int i = 2 ; i <= n ; ++ i){
        int u , v;
        scanf( "%d%d" , & u , & v );
        G[u].emplace_back( v );
        G[v].emplace_back( u );
    }
    scanf( "%d%d" , & K , & X );
    Dfs( 1 );
    int ans = 0;
    for(int i = 0 ; i < 3 ; ++ i)
        for(int j = 0 ; j <= X ; ++ j)
            Update( ans , dp[1][i][j] );
    printf( "%d\n" , ans );
    return 0;
}