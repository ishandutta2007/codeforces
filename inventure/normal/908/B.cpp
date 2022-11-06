#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 15;

int n , m , dir[4][2] = {-1,0,1,0,0,-1,0,1} , pr[4] = {0,1,2,3};
char G[maxn][maxn] , S[maxn << 1];

bool inmap( int x , int y ){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool check(){
	int sx , sy;
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 1 ; j <= m ; ++ j)
			if( G[i][j] == 'S' )
				sx = i , sy = j;
	for(char * p = S ; *p ; ++ p){
		int w = *p - '0';
		sx += dir[pr[w]][0];
		sy += dir[pr[w]][1];
		if( !inmap( sx , sy ) || G[sx][sy] == '#' ) return false;
		if( G[sx][sy] == 'E' ) return true;
	}
	return false;
}

int main( int argc , char * argv[] ){
	scanf( "%d%d" , & n , & m );
	for(int i = 1 ; i <= n ; ++ i)
		scanf( "%s" , G[i] + 1 );
	scanf( "%s" , S );
	int ans = 0;
	do{
		if( check() )
			++ ans;
	}while(next_permutation(pr,pr+4));
	printf( "%d\n" , ans );
	return 0;
}