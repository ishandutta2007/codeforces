#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

int n , fa[maxn] , Lca[maxn][20] , deep[maxn] , F1[maxn][20] , F2[maxn][20] , vis[maxn] , Djset[maxn];
vector < int > G[maxn];

int Find_Fa( int u ){
    return Djset[u] != u ? Djset[u] = Find_Fa( Djset[u] ) : u;
}

void Union_Set( int u , int v ){
    int p1 = Find_Fa( u ) , p2 = Find_Fa( v );
    if( p1 ^ p2 ) Djset[p1] = p2;
}

void Dfs( int u ){
    vis[u] = 1;
    for(auto && v : G[u]){
        deep[v] = deep[u] + 1;
        Union_Set( u , v );
        Dfs( v );
    }
}

int QueryLca( int u , int v ){
    if( deep[u] < deep[v] )
        swap( u , v );
    for(int i = 19 ; i >= 0 ; -- i)
        if( deep[u] - (1 << i) >= deep[v] )
            u = Lca[u][i];
    if( u == v ) return u;
    for(int i = 19 ; i >= 0 ; -- i)
        if( Lca[u][i] ^ Lca[v][i] )
            u = Lca[u][i] , v = Lca[v][i];
    return Lca[u][0];
}

int Arrive( int u , int v , int T[][20] ){
    for(int i = 19 ; i >= 0 && u != -1 ; -- i)
        if( deep[u] - (1 << i) >= deep[v] )
            u = T[u][i];
    return u == v;
}

int main( int argc , char * argv[] ){
    scanf( "%d" , & n );
    memset( Lca , -1 , sizeof( Lca ) );
    memset( F1 , -1 , sizeof( F1 ) );
    memset( F2 , -1 , sizeof( F2 ) );
    for(int i = 1 ; i <= n ; ++ i)
        Djset[i] = i;
    for(int i = 1 ; i <= n ; ++ i){
        int tp;
        scanf( "%d" , fa + i );
        Lca[i][0] = fa[i];
        if( fa[i] > 0 ) G[fa[i]].emplace_back( i );
        scanf( "%d" , & tp );
        if( tp == 0 ) F1[i][0] = fa[i];
        else if( tp == 1 ) F2[i][0] = fa[i];
    }
    for(int i = 1 ; i <= n ; ++ i)
        if( !vis[i] )
            Dfs( i );
    for(int j = 1 ; j < 20 ; ++ j)
        for(int i = 1 ; i <= n ; ++ i){
            if( Lca[i][j - 1] != -1 )
                Lca[i][j] = Lca[Lca[i][j - 1]][j - 1];
            if( F1[i][j - 1] != -1 )
                F1[i][j] = F1[F1[i][j - 1]][j - 1];
            if( F2[i][j - 1] != -1 )
                F2[i][j] = F2[F2[i][j - 1]][j - 1];
        }
    int Q;
    scanf( "%d" , & Q );
    while( Q -- ){
        int tp , u , v;
        scanf( "%d%d%d" , & tp , & u , & v );
        if( u == v ){
            puts( "NO" );
            continue;
        }
        if( Find_Fa( u ) != Find_Fa( v ) ){
            puts( "NO" );
            continue;
        }
        if( tp == 1 ){
            if( QueryLca( u , v ) != u || !Arrive( v , u , F1 ) )
                puts( "NO" );
            else
                puts( "YES" );
        }else{
            int lca = QueryLca( u , v );
            if( v != lca && Arrive( v , lca , F2 ) && Arrive( u , lca , F1 ) )
                puts( "YES" );
            else
                puts( "NO" );
        }
    }
    return 0;
}