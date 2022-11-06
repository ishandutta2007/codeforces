#include <bits/stdc++.h>

using namespace std;

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 100 + 5;
int n , q , c , cnt[maxn][maxn][11] , sum[maxn][maxn][11];

int main( int argc , char * argv[] ){
	n = read() , q = read() , c = read();
	for(int i = 1 ; i <= n ; ++ i){
		int x = read() , y = read() , r = read();
		++ cnt[x][y][r];
	}
	for(int mod = 0 ; mod <= c ; ++ mod)
		for(int i = 1 ; i <= 100 ; ++ i)
			for(int j = 1 ; j <= 100 ; ++ j){
				sum[i][j][mod] = sum[i][j - 1][mod] + sum[i - 1][j][mod] - sum[i - 1][j - 1][mod];
				for(int k = 0 ; k <= c ; ++ k)
					sum[i][j][mod] += cnt[i][j][k] * ( ( k + mod ) % ( c + 1 ) );
			}
	while( q -- ){
		int t = read() , x1 = read() , y1 = read() , x2 = read() , y2 = read();
		t %= ( c + 1 );
		int ret = sum[x2][y2][t] - sum[x1 - 1][y2][t] - sum[x2][y1 - 1][t] + sum[x1 - 1][y1 - 1][t];
		printf( "%d\n" , ret );
	}
	return 0;
}