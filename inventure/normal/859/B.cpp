#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1000 + 50;
const int inf = 0x3f3f3f3f;
 
template < typename T >
void Read( T & x ){
	x=0;
	char ch;
	for( ch = getchar() ; ch < '0' || ch > '9' ; ch = getchar() );
	for( ; ch <= '9' && ch >= '0' ; ch = getchar() ) x = x * 10 + ch - '0';
}

int a[55];

int main( int argc , char * argv[] ){
	//freopen( "Sample" , "r" , stdin );
	int n;
	Read( n );
	int ret = 1 << 30;
	for(int i = 1 ; i <= n ; ++ i){
		int z = (n + i - 1) / i;
		ret = min( ret , z + i );
	}
	cout << (ret << 1) << endl;
	return 0;
}