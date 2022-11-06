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

int a[55] , dp[55] , sf[55] , n;

void Solve(){
	int i;
	for( i = n - 1 , dp[n] = a[n] ; i ; -- i)
		dp[i] = max( dp[i + 1] , sf[i + 1] - dp[i + 1] + a[i] );
}

int main( int argc , char * argv[] ){
	Read( n );
	for(int i = 1 ; i <= n ; ++ i) Read( a[i] );
	for(int i = n ; i >= 1 ; -- i) sf[i] = sf[i + 1] + a[i];
	Solve();
	cout << sf[1] - dp[1] << " " << dp[1] << endl;
	return 0;
}