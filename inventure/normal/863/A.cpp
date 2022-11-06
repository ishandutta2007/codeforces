#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;


int main( int argc , char * argv[] ){
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0 ; i < 20 ; ++ i){
        string news = s;
        reverse( news.begin() , news.end() );
        for(int j = 0 ; j < i ; ++ j) news.push_back( '0' );
        reverse( news.begin() , news.end() );
        int ok = 1;
        for(int j = 0 , k = news.size() - 1 ; j < k ; ++ j , -- k)
            if( news[j] != news[k] ){
                ok = 0;
            }
        ans |= ok;
    }
    if( ans ) puts( "YES" );
    else puts( "NO" );
    return 0;
}