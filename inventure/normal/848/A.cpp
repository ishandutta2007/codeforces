#include <bits/stdc++.h>
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

using namespace std;

int main( int argc , char * argv[] ){
	int K;
	scanf( "%d" , & K );
	string ret;
	if( K == 0 ) ret.push_back( 'a' );
	for(int i = 'a' ; i <= 'z' && K ; ++ i){
		int j;
		for(j = 1 ; j * (j - 1) <= 2 * K ; ++ j);
		-- j;
		K -= (j * (j - 1) / 2);
		for(int k = 0 ; k < j ; ++ k) ret.push_back( i );
	}
	printf( "%s\n" , ret.c_str() );
	return 0;
}