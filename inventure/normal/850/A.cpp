#include <bits/stdc++.h>

using namespace std;


inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int maxn = 1000 + 15;

int n , p[maxn][5] , ans[maxn];

int main( int argc , char * argv[] ){
	n = read();
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 0 ; j < 5 ; ++ j)
			p[i][j] = read();
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 1 ; j <= n && !ans[i] ; ++ j)
			if( i ^ j )
				for(int k = j + 1 ; k <= n && !ans[i] ; ++ k)
					if( ( i ^ k ) && ( j ^ k ) ){
						int ret = 0;
						for(int z = 0 ; z < 5 ; ++ z) ret += (p[k][z] - p[i][z]) * (p[j][z] - p[i][z]);
						if( ret > 0 ) ans[i] = 1;
					}
	vector < int > ret;
	for(int i = 1 ; i <= n ; ++ i) if( !ans[i] ) ret.emplace_back( i );
	printf( "%d\n" , ret.size() );
	for(auto && x : ret) printf( "%d " , x );
	puts( "" );
	return 0;
}