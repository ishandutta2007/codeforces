#include <bits/stdc++.h>

using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}


int main( int argc , char * argv[] ){
	int s , v1 , v2 , t1 , t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int c1 = t1 * 2 + v1 * s;
	int c2 = t2 * 2 + v2 * s;
	if( c1 < c2 )
		puts( "First" );
	else if( c1 == c2 )
		puts( "Friendship" );
	else
		puts( "Second" );
	return 0;
}