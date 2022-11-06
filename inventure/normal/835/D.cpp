#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;

const int maxn = 5000 + 50;

char s[maxn] , f[maxn][maxn];
int n , ans[maxn] , cur;
char dp[2][maxn][maxn];

char Dfs( int l , int r ){
	if( ~f[l][r] )
		return f[l][r];
	char & ans = f[l][r] = 0;
	if( l > r ) return ans = 1;
	if( s[l] == s[r] ) return ans = Dfs( l + 1 , r - 1 );
	return ans = 0;
}

char Dfs( int l , int r , int k ){
	if( ~dp[l][r][k] )
		return dp[l][r][k];
	char & ans = dp[l][r][k] = 0;
	if( l >= r || !Dfs( l , r ) ) return ans = 0;
	int mid = l + r >> 1;
	if( Dfs( l , mid - ( ( r - l + 1 ) & 1 ) , k - 1 ) && Dfs( mid + 1 , r , k - 1 ) )
		return ans = 1;
	return ans = 0;
}

int main( int argc , char * argv[] ){
	scanf( "%s" , s + 1 );
	n = strlen( s + 1 );
	memset( dp , -1 , sizeof( dp ) );
	memset( f , -1 , sizeof( f ) );
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = i ; j <= n ; ++ j)
			if( Dfs( i , j ) ){
				++ ans[1];
				dp[cur][i][j] = 1;
			}else
				dp[cur][i][j] = 0;
	for(int k = 2 ; k < 15 ; ++ k){
		int pre = cur ; cur ^= 1;
		memset( dp[cur] , 0 , sizeof( dp[cur] ) );
		for(int i = 1 ; i <= n ; ++ i)
			for(int j = i + 1 ; j <= n ; ++ j)
				if( Dfs( i , j ) ){
					int mid = i + j >> 1;
					if( dp[pre][i][mid - ( ( j - i + 1 ) & 1 )] && dp[pre][mid + 1][j] )
						++ ans[k] , dp[cur][i][j] = 1;
				}
	}
	for(int i = 1 ; i <= n ; ++ i)
		printf( "%d " , ans[i] );
	puts( "" );
	return 0;
}