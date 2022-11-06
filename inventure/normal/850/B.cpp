#include <bits/stdc++.h>

using namespace std;


inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int maxn = 1e6 + 15;
const int mxsz = 2e6 + 50;

int n , a[maxn] , x , y , prime[maxn] , primelen , vis[maxn] , sum[mxsz];
long long pf[mxsz];

void Init(){
	for(int i = 2 ; i < maxn ; ++ i){
		if( !vis[i] ) prime[primelen ++] = i;
		for(int j = 0 ; j < primelen && i * prime[j] < maxn ; ++ j){
			vis[i * prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
		}
	}
}

int main( int argc , char * argv[] ){
	Init();
	n = read() , x = read() , y = read();
	for(int i = 1 ; i <= n ; ++ i){
		int x = read();
		++ sum[x];
		pf[x] += x;
	}
	for(int i = 1 ; i <= 2000000 ; ++ i) sum[i] += sum[i - 1] , pf[i] += pf[i - 1];
	long long ans = 1LL << 60;
	for(int i = 0 ; i < primelen ; ++ i){
		int p = prime[i];
		long long ret = 0;
		for(int l = 1 , r = p ; r <= 2000000 ; l += p , r += p){
			// [l , r] -> r
			int z = max( l , r - ( x / y ) );
			long long f1 = 0 , f2 = 0;
			f1 = ( 1LL * r * ( sum[r] - sum[z - 1] ) -  ( pf[r] - pf[z - 1] ) ) * y;
			f2 = 1LL * ( sum[z - 1] - sum[l - 1] ) * x;
			ret += ( f1 + f2 );
		}
		ans = min( ans , ret );
	}
	printf( "%I64d\n" , ans );
	return 0;
}