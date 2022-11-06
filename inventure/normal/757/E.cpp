#include <bits/stdc++.h>
const int mod = 1e9 + 7;
inline int mul( int x , int y ){ return 1LL * x * y % mod ;}
int power_mod( int x , int y ){int ret = 1;while( y ){if( y & 1 ) ret = mul( ret , x );y >>= 1;x = mul( x , x );}return ret;}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const int maxn = 1e6 ;

int f[maxn + 1][20] , C[maxn + 1][20] , fac[maxn + 1] ;

inline void upd( int & x , int v ){
	x += v;
	if( x >= mod )
		x -= mod;
}

void PreDeal(){
	fac[0] = 1;
	for(int i = 1 ; i <= maxn ; ++ i) fac[i] = mul( fac[i - 1] , i );
	C[0][0] = 1;
	for(int i = 1 ; i <= maxn ; ++ i){
		C[i][0] = 1;
		for(int j = 1 ; j < 20 ; ++ j)
			upd( C[i][j] , C[i - 1][j - 1] + C[i - 1][j] );
	}
	for(int i = 1 ; i <= maxn ; ++ i)
		for(int j = i ; j <= maxn ; j += i)
			if( __gcd( i , j / i ) == 1 )
				upd( f[j][0] , 1 );
	for(int t = 0 ; t < 19 ; ++ t)
		for(int i = 1 ; i <= maxn ; ++ i)
			if( f[i][t])
				for(int j = i + i ; j <= maxn ; j += i)
					upd( f[j][t + 1] , f[i][t] );
}


int main( int argc , char * argv[] ){
	PreDeal();
	int T = read();
	for(int i = 1 ; i <= T ; ++ i){
		int r = read() , n = read() , ans = 0;
		for(int tl = 0 ; tl <= min( r , 19 ) ; ++ tl)
			upd( ans , mul( f[n][tl] , C[r][tl] ) );
		printf( "%d\n" , ans );
	}
	return 0;
}