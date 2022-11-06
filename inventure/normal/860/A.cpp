#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 3000 + 50;
const int inf = 0x3f3f3f3f;
using ull = unsigned long long;
 
template < typename T >
void Read( T & x ){
	x=0;
	char ch;
	for( ch = getchar() ; ch < '0' || ch > '9' ; ch = getchar() );
	for( ; ch <= '9' && ch >= '0' ; ch = getchar() ) x = x * 10 + ch - '0';
}

char s[maxn];
int vis[555] , dp[maxn];

bool check( char c ){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main( int argc , char * argv[] ){
	scanf( "%s" , s );
	int n = strlen( s );
	for(int i = 0 , j = 0 , k = 0 ; i < n ; ++ i){
		if( check( s[i] ) ){
			j = k = 0;
			memset( vis , 0 , sizeof( vis ) );
		}else{
			++ j;
			k += (vis[s[i]] ^ 1);
			vis[s[i]] = 1;
		}
		if( j >= 3 && k >= 2 ){
			putchar( ' ' );
			memset( vis , 0 , sizeof( vis ) );
			if( check( s[i] ) )
				j = k = 0;
			else
				j = k = 1 , vis[s[i]] = 1;
		}
		putchar( s[i] );
	}
	puts( "" );
	return 0;
}