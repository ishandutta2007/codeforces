#include <bits/stdc++.h>

using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}


int z[50][50];
queue < pair < int , int > > que;

void Init(){
	que.push( make_pair( 0 , 0 ) );
	z[0][0] = 1;
	while( !que.empty() ){
		pair < int , int > x = que.front() ; que.pop();
		pair < int , int > newx = make_pair( x.first + 2 , x.second + 1 );
		if( max( newx.first , newx.second ) < 50 && !z[newx.first][newx.second] )
			z[newx.first][newx.second] = 1,
			que.push( newx );
		newx = make_pair( x.first + 1 , x.second + 2 );
		if( max( newx.first , newx.second ) < 50 && !z[newx.first][newx.second] )
			z[newx.first][newx.second] = 1,
			que.push( newx );
	} 
}

int main( int argc , char * argv[] ){
	Init();
	int n ;
	scanf( "%d" , & n );
	while( n -- ){
		int a , b ;
		scanf( "%d%d" , & a , & b );
		if( a > b )
			swap( a , b );
		long long z = 1LL * a * b;
		long long l = 1 , r = 1e6;
		while( l < r ){
			long long mid = l + r >> 1;
			if( 1LL * mid * mid * mid < z )
				l = mid + 1;
			else
				r = mid;
		}
		if( 1LL * l * l * l != z || a % l != 0 || b % l != 0 ){
			puts( "No" );
			continue;
		}
		puts( "Yes" );
	}
	return 0;
}