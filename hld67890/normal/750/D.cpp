#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 40;
const int maxm = 410;
int n;
int t[maxn];
bool boom[maxm][maxm][10][maxn];
int f[maxm][maxm];
int dx[10] , dy[10];
int ans;
void dfs ( int x , int y , int dir , int i ) {
	if ( i == n + 1 ) return ;
	int j;
	for ( j = 1 ; j < t[i] ; j++ ) {
		f[x][y] = 1;
		x += dx[dir]; y += dy[dir];
	}
	f[x][y] = 1;
	int dir1 = (dir-1+8) % 8 , dir2 = (dir+1) % 8;
	if ( boom[x][y][dir][i] == 0 ) {
		boom[x][y][dir][i] = 1;
		dfs ( x + dx[dir1] , y + dy[dir1] , dir1 , i + 1 );
		dfs ( x + dx[dir2] , y + dy[dir2] , dir2 , i + 1 );
	}
}
void work () {
	int i , j;
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) scanf ( "%d" , &t[i] );
	dx[0] = 0; dy[0] = 1;
	dx[1] = 1; dy[1] = 1;
	dx[2] = 1; dy[2] = 0;
	dx[3] = 1; dy[3] = -1;
	dx[4] = 0; dy[4] = -1;
	dx[5] = -1; dy[5] = -1;
	dx[6] = -1; dy[6] = 0;
	dx[7] = -1; dy[7] = 1;
	dfs ( 200 , 200 , 0 , 1 );
	ans = 0;
	for ( i = 0 ; i <= 400 ; i++ ) for ( j = 0 ; j <= 400 ; j++ ) ans += f[i][j];
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}