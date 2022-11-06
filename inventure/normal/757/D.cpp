#include <bits/stdc++.h>
const int mod = 1e9 + 7;
inline int mul( int x , int y ){ return 1LL * x * y % mod ;}
int power_mod( int x , int y ){int ret = 1;while( y ){if( y & 1 ) ret = mul( ret , x );y >>= 1;x = mul( x , x );}return ret;}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const int maxn = 1e5 + 50;

int dp[80][1 << 20] , n ;
char s[maxn];

inline void upd( int & x , int v ){
	x += v;
	if( x >= mod )
		x -= mod;
}

int cost( int x ){
	for(int i = 30 ; i >= 0 ; -- i)
		if( x >> i & 1 )
			return i + 1;
}

int main( int argc , char * argv[] ){
	scanf( "%d%s" , & n , s + 1 );
	for(int i = 0 ; i < n ; ++ i){
		upd( dp[i][0] , 1 );
		for(int mask = 0 ; mask < (1 << 20) ; ++ mask)
			if( dp[i][mask] ){
				int number = 0;
				for(int st = i + 1 ; st <= n && number <= 20 ; ++ st){
					number = number * 2 + s[st] - '0';
					if( number <= 20 && number >= 1 )
						upd( dp[st][mask | (1 << number - 1)] , dp[i][mask] );
				}
			}
	}
	int ans = 0 ;
	for(int i = 1 ; i <= n ; ++ i)
		for(int bit = 0 ; bit < 20 ; ++ bit)
			upd( ans , dp[i][(1 << bit + 1) - 1] );
	printf( "%d\n" , ans );
	return 0;
}