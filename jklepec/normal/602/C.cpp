#include <bits/stdc++.h>
#define iter(i) set< i >::iterator
#define FOR( i, a, b ) for( int i = a; i < b; i++ )
#define REP( i, a ) for( int i = 0; i < a; i++ )
using namespace std;

typedef long long llint;
typedef pair< int, int > point;

const int MaxN = 450, MOD = 1e9 + 7, B = 3137;

int n, m;
bool cesta[MaxN][MaxN];
vector < int > v[MaxN];
int bio[MaxN], sol[MaxN];
queue< point > Q;


int main() {

    cin >> n >> m;

    bool obrni = false;
    REP( i, m ) {
        int x, y;
        cin >> x >> y;
        if( x > y ) swap( x, y );
        if( x == 1 && y == n ) obrni = true;
        cesta[x][y] = true;
        cesta[y][x] = true;
    }

    FOR( i, 1, n+1 )
        FOR( j, 1, n+1 )
            if( i != j and ( cesta[i][j] xor obrni ) )
                v[i].push_back( j );

    Q.push( point( 1, 0 ) );
    bio[1] = true;
    while( !Q.empty() ) {
        int node = Q.front().first;
        int sati = Q.front().second;
        sol[node] = sati;
        Q.pop();
        REP( i, v[node].size() ) {
            if( !bio[ v[node][i] ] )
                Q.push( point( v[node][i], sati + 1 ) );
            bio[ v[node][i] ] = true;
        }
    }

    cout << ( sol[n] == 0 ? -1 : sol[n] );

    return 0;
}