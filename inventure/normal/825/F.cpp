#include <bits/stdc++.h>

using namespace std;

const int maxn = 8000 + 15;
const int inf = 0x3f3f3f3f;

char s[maxn];
int n , cost[maxn] , dp[maxn] , Lcp[maxn][maxn];

void PreDeal(){
	for(int i = 1 ; i < maxn ; ++ i){
		int j = i;
		while( j ){
			++ cost[i];
			j /= 10;
		}
	}
}

inline void upd( int & x , int y ){
	x = min( x , y );
}

int main( int argc , char * argv[] ){
	PreDeal();
	scanf( "%s" , s + 1 );
	n = strlen( s + 1 );
	for(int i = n ; i >= 1 ; -- i)
		for(int j = n ; j >= 1 ; -- j)
			if( s[i] == s[j] )
				Lcp[i][j] = Lcp[i + 1][j + 1] + 1;
	memset( dp , 0x3f , sizeof( dp ) );
	dp[0] = 0;
	for(int i = 0 ; i < n ; ++ i)
		if( dp[i] != inf )
			for(int len = 1 ; i + len <= n ; ++ len)
				for(int j = i + 1 , k = 1 ; j <= n ; j += len , ++ k)
					if( Lcp[i + 1][j] >= len ){
						upd( dp[j + len - 1] , dp[i] + len + cost[k] );
					}
					else
						break;
	printf( "%d\n" , dp[n] );
	return 0;
}