#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 50;

int use[maxn];

string s[maxn];

int main( int argc , char * argv[] ){
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; ++ i) cin >> s[i];
    for(int i = 0 ; i < n ; ++ i){
        int ok = 0;
        for(int j = 0 ; j < i ; ++ j)
            if( s[j] == s[i] )
                ok = 1;
        if( ok )
            puts( "YES" );
        else
            puts( "NO" );
    }
    return 0;
}