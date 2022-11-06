#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int n , cur , sgn;
vector < int > checkspeed;

inline void Update( int & x , int y ){
    x = min( x , y );
}

int main( int argc , char * argv[] ){
    int speed , ans = 0;
    scanf( "%d%*d%d" , & n , & speed );;
    for(int i = 2 ; i <= n ; ++ i){
        int tp , x;
        scanf( "%d" , & tp );
        if( tp == 1 || tp == 3 ) scanf( "%d" , & x );
        if( tp == 1 ){
            while( !checkspeed.empty() && x > checkspeed.back() ) ++ ans , checkspeed.pop_back();
            speed = x;
        }else if( tp == 2 ){
            ans += sgn;
            sgn = 0;
        }else if( tp == 3 ){
            checkspeed.emplace_back( x );
            while( !checkspeed.empty() && speed > checkspeed.back() ) ++ ans , checkspeed.pop_back();
        }else if( tp == 4 )
            sgn = 0;
        else if( tp == 5 )
            checkspeed.emplace_back( inf );
        else
            ++ sgn;
    }
    printf( "%d\n" , ans );
    return 0;
}