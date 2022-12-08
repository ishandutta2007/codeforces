#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct node {
	int d , x , y;
};
int n , m , x1 , y1 , x2 , y2;
int d[5][1200][1200];
int map[5][1200][1200];
char z[1200];
queue < node > q;
int ans;
int main () {
	int i , j , k;
	cin >> n >> m;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> z;
		for ( j = 0 ; j < m ; j++ ) {
			if ( z[j] == '+' ) d[0][i][j+1] = 15;
			if ( z[j] == '-' ) d[0][i][j+1] = 5;
			if ( z[j] == '|' ) d[0][i][j+1] = 10;
			if ( z[j] == '^' ) d[0][i][j+1] = 8;
			if ( z[j] == '>' ) d[0][i][j+1] = 4;
			if ( z[j] == '<' ) d[0][i][j+1] = 1;
			if ( z[j] == 'v' ) d[0][i][j+1] = 2;
			if ( z[j] == 'L' ) d[0][i][j+1] = 14;
			if ( z[j] == 'R' ) d[0][i][j+1] = 11;
			if ( z[j] == 'U' ) d[0][i][j+1] = 7;
			if ( z[j] == 'D' ) d[0][i][j+1] = 13;
			if ( z[j] == '*' ) d[0][i][j+1] = 0;
		}
	}
	for ( i = 1 ; i <= 3 ; i++ ) for ( j = 1 ; j <= n ; j++ ) for ( k = 1 ; k <= m ; k++ ) d[i][j][k] = (d[i-1][j][k]>>1) + (d[i-1][j][k]&1?8:0);
	for ( i = 0 ; i <= 3 ; i++ ) for ( j = 1 ; j <= n ; j++ ) for ( k = 1 ; k <= m ; k++ ) map[i][j][k] = 9999999;
	//for ( i = 0 ; i <= 3 ; i++ ) for ( j = 1 ; j <= n ; j++ ) for ( k = 1 ; k <= m ; k++ ) cout << i << " " << j << " " << k << " " << d[i][j][k] << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	map[0][x1][y1] = 0;
	node tmp;
	tmp.d = 0; tmp.x = x1; tmp.y = y1; q.push ( tmp );
	while ( q.size () != 0 ) {
		tmp = q.front (); q.pop ();
		//cout << tmp.x << " " << tmp.y << " " << tmp.d << " " << map[tmp.d][tmp.x][tmp.y] << endl;
		if ( map[(tmp.d+1)%4][tmp.x][tmp.y] == 9999999 ) {
			map[(tmp.d+1)%4][tmp.x][tmp.y] = map[tmp.d][tmp.x][tmp.y] + 1;
			tmp.d = (tmp.d+1)%4;
			q.push ( tmp );
			tmp.d = (tmp.d+3)%4;
		}
		if ( tmp.y + 1 <= m && ((d[tmp.d][tmp.x][tmp.y] & 4) == 4) && ((d[tmp.d][tmp.x][tmp.y+1] & 1) == 1) ) {
			if ( map[tmp.d][tmp.x][tmp.y+1] == 9999999 ) {
				map[tmp.d][tmp.x][tmp.y+1] = map[tmp.d][tmp.x][tmp.y] + 1;
				tmp.y++;
				q.push ( tmp );
				tmp.y--;
			}
		}
		if ( tmp.y - 1 >= 1 && ((d[tmp.d][tmp.x][tmp.y] & 1) == 1) && ((d[tmp.d][tmp.x][tmp.y-1] & 4) == 4) ) {
			if ( map[tmp.d][tmp.x][tmp.y-1] == 9999999 ) {
				map[tmp.d][tmp.x][tmp.y-1] = map[tmp.d][tmp.x][tmp.y] + 1;
				tmp.y--;
				q.push ( tmp );
				tmp.y++;
			}
		}
		if ( tmp.x + 1 <= n && ((d[tmp.d][tmp.x][tmp.y] & 2) == 2) && ((d[tmp.d][tmp.x+1][tmp.y] & 8) == 8) ) {
			if ( map[tmp.d][tmp.x+1][tmp.y] == 9999999 ) {
				map[tmp.d][tmp.x+1][tmp.y] = map[tmp.d][tmp.x][tmp.y] + 1;
				tmp.x++;
				q.push ( tmp );
				tmp.x--;
			}
		}
		if ( tmp.x - 1 >= 1 && ((d[tmp.d][tmp.x][tmp.y] & 8) == 8) && ((d[tmp.d][tmp.x-1][tmp.y] & 2) == 2) ) {
			if ( map[tmp.d][tmp.x-1][tmp.y] == 9999999 ) {
				map[tmp.d][tmp.x-1][tmp.y] = map[tmp.d][tmp.x][tmp.y] + 1;
				tmp.x--;
				q.push ( tmp );
				tmp.x++;
			}
		}
	}
	ans = min ( min ( map[0][x2][y2] , map[1][x2][y2] ) , min ( map[2][x2][y2] , map[3][x2][y2] ) );
	if ( ans == 9999999 ) ans = -1;
	cout << ans << endl;
	return 0;
}