#include <bits/stdc++.h>

using namespace std;

const int maxn = 500 + 50;

int n , m , k;
pair < int , int > fire[maxn];
set < int > rx , ry;

bool check( int time ){
    rx.clear() , ry.clear();
    rx.insert( 1 ) , rx.insert( n ) , ry.insert( 1 ) , ry.insert( m );
    for(int i = 1 ; i <= k ; ++ i)
        for(int j = -1 ; j <= 1 ; ++ j){
            rx.insert( max( 1 , min( fire[i].first + j + time , n ) ) );
            rx.insert( min( n , max( fire[i].first + j - time , 1 ) ) );
            ry.insert( max( 1 , min( fire[i].second + j + time , m ) ) );
            ry.insert( min( m , max( fire[i].second + j - time , 1 ) ) );
        }
    int xmin = 1e9 + 7 , xmax = -1;
    for(auto && x : rx){
        vector < pair < int , int > > seg;
        for(int i = 1 ; i <= k ; ++ i)
            if( fire[i].first - time <= x && x <= fire[i].first + time )
                seg.emplace_back( make_pair( max( 1 , fire[i].second - time ) , min( m , fire[i].second + time ) ) );
        if( seg.empty() ){
            xmin = min( xmin , x ) , xmax = max( xmax , x );
            continue;
        }
        sort( seg.begin() , seg.end() );
        int ok = 1 , r = seg.begin()->second;
        if( seg.begin()->first != 1 ) ok = 0;
        for(int i = 0 ; i < seg.size() ; ++ i)
            if( r + 1 >= seg[i].first )
                r = max( r , seg[i].second );
            else
                break;
        if( r != m ) ok = 0;
        if( !ok ) xmin = min( xmin , x ) , xmax = max( xmax , x );
    }
    if( xmax != -1 && xmax - xmin > 2 * time ) return false;
    int ymin = 1e9 + 7 , ymax = -1;
    for(auto && x : ry){
        vector < pair < int , int > > seg;
        for(int i = 1 ; i <= k ; ++ i)
            if( fire[i].second - time <= x && x <= fire[i].second + time )
                seg.emplace_back( make_pair( max( 1 , fire[i].first - time ) , min( n , fire[i].first + time ) ) );
        if( seg.empty() ){
            ymin = min( ymin , x ) , ymax = max( ymax , x );
            continue;
        }
        sort( seg.begin() , seg.end() );
        int ok = 1 , r = seg.begin()->second;
        if( seg.begin()->first != 1 ) ok = 0;
        for(int i = 0 ; i < seg.size() ; ++ i)
            if( r + 1 >= seg[i].first )
                r = max( r , seg[i].second );
            else
                break;
        if( r != n ) ok = 0;
        if( !ok ) ymin = min( ymin , x ) , ymax = max( ymax , x );
    }
    if( ymax == -1 ) return true;
    if( ymax - ymin > 2 * time ) return false;
    return true;
}

int main( int argc , char * argv[] ){
    scanf( "%d%d%d" , & n , & m , & k );
    for(int i = 1 ; i <= k ; ++ i) scanf( "%d%d" , & fire[i].first , & fire[i].second );
    if( k + 1 == 1LL * n * m ){
        puts( "0" );
        return 0;
    }
    int l = 1 , r = max( n , m );
    while( l < r ){
        int mid = l + r >> 1;
        if( check( mid ) ) r = mid;
        else l = mid + 1;
    }
    printf( "%d\n" , l );
    return 0;
}