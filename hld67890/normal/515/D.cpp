#include <iostream>
#include <queue>

using namespace std;

struct point {
	int x , y;
};
int n , m;
char z[2101][2101];
bool f[2101][2101];
queue < point > q;
bool check ( int x , int y ) {
	int s;
	s = 0;
	if ( z[x + 1][y] == '.' ) s++;
	if ( z[x - 1][y] == '.' ) s++;
	if ( z[x][y + 1] == '.' ) s++;
	if ( z[x][y - 1] == '.' ) s++;
	if ( s == 0 || s == 1 ) return true;
	return false;
}
void add ( int x , int y ) {
	point p;
	if ( z[x + 1][y] == '.' ) { p.x = x + 1; p.y = y; q.push ( p ); }
	if ( z[x - 1][y] == '.' ) { p.x = x - 1; p.y = y; q.push ( p ); }
	if ( z[x][y + 1] == '.' ) { p.x = x; p.y = y + 1; q.push ( p ); }
	if ( z[x][y - 1] == '.' ) { p.x = x; p.y = y - 1; q.push ( p ); }
}
void work () {
	point p;
	int i , j , s;
	bool flag;
	cin >> n >> m;
	for ( i = 1 ; i <= n ; i++ ) {
		cin >> z[i];
		for ( j = m ; j >= 1 ; j-- ) z[i][j] = z[i][j - 1];
		z[i][0] = z[i][m + 1] = '*';
	}
	flag = false;
	for ( i = 1 ; i <= m ; i++ ) z[0][i] = z[n + 1][i] = '*';
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ ) {
			if ( z[i][j] == '.' ) flag = true;
			if ( z[i][j] == '.' && check ( i , j ) ) {
				p.x = i; p.y = j;
				q.push ( p );
			}
		}
	}
	if ( flag == true && q.empty () ) { cout << "Not unique" << endl; return ; }
	flag = true;
	while ( !q.empty () ) {
		p = q.front ();
		//cout << p.x << " " << p.y << endl;
		q.pop ();
		if ( z[p.x][p.y] != '.' ) continue;
		s = 0;
		if ( z[p.x + 1][p.y] == '.' ) s++;
		if ( z[p.x - 1][p.y] == '.' ) s++;
		if ( z[p.x][p.y + 1] == '.' ) s++;
		if ( z[p.x][p.y - 1] == '.' ) s++;
		//cout << s << endl;
		if ( s >= 2 )
			continue;
		if ( s == 0 ) { flag = false; break; }
		if ( z[p.x + 1][p.y] == '.' ) { z[p.x][p.y] = '^'; z[p.x + 1][p.y] = 'v'; add ( p.x + 1 , p.y ); }
		if ( z[p.x - 1][p.y] == '.' ) { z[p.x][p.y] = 'v'; z[p.x - 1][p.y] = '^'; add ( p.x - 1 , p.y ); }
		if ( z[p.x][p.y + 1] == '.' ) { z[p.x][p.y] = '<'; z[p.x][p.y + 1] = '>'; add ( p.x , p.y + 1 ); }
		if ( z[p.x][p.y - 1] == '.' ) { z[p.x][p.y] = '>'; z[p.x][p.y - 1] = '<'; add ( p.x , p.y - 1 ); }
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = 1 ; j <= m ; j++ )
			if ( z[i][j] == '.' ) { flag = false; }
	}
	if ( flag == false ) cout << "Not unique" << endl;
	else {
		for ( i = 1 ; i <= n ; i++ ) {
			for ( j = 1 ; j <= m ; j++ )
				cout << z[i][j];
			cout << endl;
		}
	}
}
int main () {
	work ();
	return 0;
}