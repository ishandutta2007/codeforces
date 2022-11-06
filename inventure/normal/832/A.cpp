#include <bits/stdc++.h>


inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;


int main( int argc , char * argv[] ){
	//freopen( "Sample" , "r" , stdin );
	long long n , k;
	cin >> n >> k;
	if( ( n / k ) & 1 )
		puts( "YES" );
	else
		puts( "NO" );
	return 0;
}