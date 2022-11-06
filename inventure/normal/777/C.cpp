#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

using namespace std;

const int maxn = 1e5 + 50;

int n , m , *mat[maxn] , *down[maxn] , mx[maxn];

int main(int argc,char *argv[]){
	n = read() , m = read();
	for(int i = 1 ; i <= n ; ++ i){
		mat[i] = new int[m + 1];
		down[i] = new int[m + 1];
		for(int j = 1 ; j <= m ; ++ j)
			mat[i][j] = read();
	}
	for(int j = 1 ; j <= m ; ++ j){
		for(int i = n ; i >= 1 ; -- i){
			down[i][j] = 1;
			if( i + 1 <= n && mat[i][j] <= mat[i + 1][j] )
				down[i][j] += down[i + 1][j];
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		mx[i] = 0;
		for(int j = 1 ; j <= m ; ++ j)
			mx[i] = max( mx[i] , down[i][j] );
	}
	int K = read();
	while( K -- ){
		int l = read() , r = read();
		if( mx[l] >= r - l + 1 )
			puts( "Yes" );
		else
			puts( "No" );
	}
	return 0;
}