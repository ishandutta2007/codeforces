#include <bits/stdc++.h>


// http://codeforces.com/contest/868/problem/F

using namespace std;
using ull = unsigned long long;
const int maxn = 1e5 + 50;

int n , a[maxn] , K , cnt[maxn], l , r;
long long f[maxn] , g[maxn] , ret;

void Move( int tl , int tr ){
	while( l > tl ) ret += cnt[a[-- l]]++;
	while( l < tl ) ret -= --cnt[a[l++]];
	while( r < tr ) ret += cnt[a[++ r]]++;
	while( r > tr ) ret -= --cnt[a[r--]];
}

void Solve( int l , int r , int bestl , int bestr , long long * x , long long * y ){
	if( l > r ) return ;
	int mid = l + r >> 1 , s , checkr = min( bestr , mid );
	y[mid] = 1ll << 60;
	Move( bestl , mid );
	for(int i = bestl ; i <= checkr ; ++ i){
		Move( i + 1 , mid );
		long long c = x[i] + ret;
		if( y[mid] > c ) y[mid] = c , s = i;
	}
	Solve( mid + 1 , r , s , bestr , x , y );
	Solve( l , mid - 1 , bestl , s , x , y );
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & K );
	for(int i = 1 ; i <= n ; ++ i){
		scanf( "%d" , a + i );
		f[i] = f[i - 1] + cnt[a[i]]++;
	}
	memset( cnt , 0 , sizeof( cnt ) );
	auto x = f , y = g;
	for(int i = 2 ; i <= K ; ++ i , swap( x , y )){
		memset( cnt , 0 , sizeof( cnt ) ); ret = 0 , l = 1 , r = 0;
		Solve( 1 , n , 1 , n , x , y );
	}
	printf( "%lld\n" , x[n] );
	return 0;
}