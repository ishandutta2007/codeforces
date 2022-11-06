#include <bits/stdc++.h>

using namespace std;

int n;
map < int , int > add , del;
set < int > tl;

int main( int argc , char * argv[] ){
    scanf( "%d" , & n );
    while( n -- ){
        int l , r;
        scanf( "%d%d" , & l , & r );
        ++ add[l];
        ++ del[r];
        tl.insert( l );
        tl.insert( r );
    }
    int r = 2;
    for(auto && x : tl){
        if( add.count( x ) ) r -= add[x];
        if( r < 0 ){
            puts( "NO" );
            return 0;
        }
        if( del.count( x ) ) r += del[x];
    }
    puts( "YES" );
    return 0;
}