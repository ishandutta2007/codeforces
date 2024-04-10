#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

int n , m , vis[maxn] , sum[maxn] , head[maxn] , used[maxn << 2] , tot;
vector < int > vi;

struct Edge{
    int v , nxt , c;
}Edge[maxn << 1];

void Link( int u , int v , int c ){
    Edge[tot].v = v , Edge[tot].nxt = head[u] , Edge[tot].c = c , head[u] = tot ++ ;
}

void Gauss(){
    int cur = 0;
    for(int i = 30 ; i >= 0 ; -- i){
        int nxt = -1;
        for(int j = cur ; j < vi.size() ; ++ j) 
            if( vi[j] >> i & 1 ){
                nxt = j;
                break;
            }
        if( nxt == -1 ) continue;
        swap( vi[nxt] , vi[cur] );
        for(int j = 0 ; j < vi.size() ; ++ j) 
            if( j != cur && ( vi[j] >> i & 1 ) )
                vi[j] ^= vi[cur];
        ++ cur;
    }
}

void Dfs( int u , int fa = 0 ){
    vis[u] = 1;
    for(int i = head[u] ; ~i ; i = Edge[i].nxt){
        int v = Edge[i].v , c = Edge[i].c;
        if( v == fa ) continue;
        if( vis[v] ){
            if( !used[i] && !used[i ^ 1] ){
                used[i] = used[i ^ 1] = 1;
                vi.emplace_back( sum[u] ^ sum[v] ^ c );
            }
            continue;
        }
        sum[v] = sum[u] ^ c;
        Dfs( v , u );
    }
}

int main( int argc , char * argv[] ){
    scanf( "%d%d" , & n , & m );
    memset( head , -1 , ( n + 1 ) << 2 );
    for(int i = 1 ; i <= m ; ++ i){
        int u , v , c;
        scanf( "%d%d%d" , & u , & v , & c );
        Link( u , v , c );
        Link( v , u , c );
    }
    Dfs( 1 );
    Gauss();
    int ans = sum[n];
    for(int i = 30 ; i >= 0 ; -- i){
        int Mi = ans;
        for(auto && x : vi) Mi = min( Mi , ans ^ x );
        ans = Mi;
    }
    printf( "%d\n" , ans );
    return 0;
}