#include <bits/stdc++.h>

using namespace std;

char digit[8];
int ans = 6;

void Dfs( int x , int sum ){
    if( x == 6 ){
        int a = 0 , b = 0;
        for(int i = 0 ; i < 3 ; ++ i) a += digit[i];
        for(int i = 3 ; i < 6 ; ++ i) b += digit[i];
        if( a == b ) ans = min( ans , sum );
    }else{
        for(int i = 0 ; i <= 9 ; ++ i){
            int newsum = sum + ( i != digit[x] ) , pre = digit[x];
            digit[x] = i;
            Dfs( x + 1 , newsum );
            digit[x] = pre;
        }
    }
}

int main( int argc , char * argv[] ){
    scanf( "%s" , digit );
    for(int i = 0 ; i < 6 ; ++ i) digit[i] -= '0';
    Dfs( 0 , 0 );
    printf( "%d\n" , ans );
    return 0;
}