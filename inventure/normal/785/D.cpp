#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;

inline int mul( int x , int y ){
	return 1LL * x * y % mod;
}

inline void upd( int & x , int y ){
	x += y;
	if( x >= mod )
		x -= mod;
}

int power( int x , int y ){
	int ret = 1;
	while( y ){
		if( y & 1 )
			ret = mul( ret , x );
		y >>= 1;
		x = mul( x , x );
	}
	return ret;
}

char s[maxn];
int nxt[maxn] , fac[maxn << 1] , n , sum[maxn] , sum2[maxn] , ans , dp[maxn];

void PreDeal(){
	fac[0] = 1;
	for(int i = 1 ; i < 2 * maxn ; ++ i)
		fac[i] = mul( fac[i - 1] , i );
}

int C( int n , int m ){
	if( n < m )
		return 0;
	return mul( fac[n] , power( mul( fac[m] , fac[n - m ] ) , mod - 2 ) );
}

int main( int argc , char * argv[] ){
	PreDeal();
	scanf( "%s" , s + 1 );
	n = strlen( s + 1 );
	for(int i = 1 ; i <= n ; ++ i)
		sum[i] = sum[i - 1] + (s[i] == '('),
		sum2[i] = sum2[i - 1] + (s[i] == ')');
	int pre = 0, ans =0;
	for(int i = 1 ; i <= n ; ++ i)
		if( s[i] == '(' ){
			int lft = sum[i];
			int rht = sum2[n] - sum2[i];
			dp[i] = C( lft + rht , lft );
			dp[i] -= C( pre + rht , pre );
			if( dp[i] < 0 )
				dp[i] += mod;
			upd( ans , dp[i] );
			++ pre;
		}
	cout << ans << endl;
	return 0;
}