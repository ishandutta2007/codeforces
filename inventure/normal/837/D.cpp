#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 5;
int n , k , two[maxn] , five[maxn] , ten[maxn] , cur;
long long a[maxn];
short dp[2][maxn][maxn * 64][2];

inline void upd( short & x , short y ){
	x = max( x , y );
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & k );
	for(int i = 1 ; i <= n ; ++ i){
		long long x;
		scanf( "%lld" , & x );
		int cnt2 = 0 , cnt5 = 0;
		while( x % 2 == 0 ) x /= 2 , ++ cnt2;
		while( x % 5 == 0 ) x /= 5 , ++ cnt5;
		ten[i] = min( cnt2 , cnt5 );
		cnt2 -= ten[i] , cnt5 -= ten[i];
		two[i] = cnt2;
		five[i] = cnt5;
	}
	int w = n * 64;
	memset( dp , -1 , sizeof( dp ) );
	dp[cur][0][0][1] = 0;
	for(int i = 1 ; i <= n ; ++ i){
		int pre = cur ; cur ^= 1;
		memset( dp[cur] , -1 , sizeof( dp[cur] ) );
		for(int j = 0 ; j <= k ; ++ j)
			for(int k = 0 ; k < w ; ++ k)
				for(int f = 0 ; f < 2 ; ++ f)
					if( ~dp[pre][j][k][f] ){
						upd( dp[cur][j][k][f] , dp[pre][j][k][f] );
						short newret = dp[pre][j][k][f] + ten[i];
						int us = 0 , ds = 0;
						if( f == 0 ) us = k;
						else ds = k;
						us += two[i];
						ds += five[i];
						int z = min( us , ds );
						us -= z , ds -= z;
						newret += z;
						int newk , newf;
						if( us ) newk = us , newf = 0;
						else newk = ds , newf = 1;
						upd( dp[cur][j + 1][newk][newf] , newret );
					}
	}
	short ans = 0;
	for(int j = 0 ; j <= k ; ++ j)
		for(int k = 0 ; k < w ; ++ k)
			for(int f = 0 ; f < 2 ; ++ f)
				if( ~dp[cur][j][k][f] )
					upd( ans , dp[cur][j][k][f] );
	cout << ans << endl;
	return 0;
}