#include <bits/stdc++.h>
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int maxn = 2e5 + 50;

int n , live[maxn] , a[maxn] , k;

int main( int argc , char * argv[] ){
	n = read() , k = read();
	for(int i = 1 ; i <= k ; ++ i)
		a[i] = read();
	for(int i = 0 ; i < n ; ++ i) live[i] = 1;
	int cur = 0;
	for(int i = 1 ; i <= k ; ++ i){
		int ret = 0;
		a[i] %= (n-i+1);
		while( ret < a[i] ){
			cur = (cur + 1) % n;
			if( live[cur] )
				++ ret;
		}
		assert( live[cur] == 1 );
		live[cur] = 0;
		printf( "%d " , cur + 1 );
		while( !live[cur] )
			cur = (cur + 1)%n;
	}
	puts( "" );
	return 0;
}