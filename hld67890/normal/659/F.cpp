#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	   long long x , i , j;
} s[1200000];
long long n , m;
long long k;
long long map[1100][1100] , f[1100][1100] , f1[1100][1100];
long long c[1200000];
long long cnt , ans;
bool cmp ( node x1 , node x2 ) {
	 return x1.x >
	  x2.x;
}
long long get ( long long x , long long y ) {
	return (x-1)*m+y;
}
long long find ( long long x ) {
	long long i , t;
	for ( i = x ; c[i] > 0 ; i = c[i] ) ;
	while ( c[x] > 0 ) {
		  t = c[x];
		  c[x] = i;
		  x = t;
	}
	return i;
}
void Union ( long long x , long long y ) {
	 if ( x == y ) return ;
	 c[x] += c[y];
	 c[y] = x;
}
void dfs ( long long x , long long y ) {
	 if ( cnt < ans ) {
	 	  cnt++;
	 	  f1[x][y] = ans;
	 	  if ( x > 1 && find ( get(x-1,y)) == find (get(x,y)) && f1[x-1][y] == 0 ) dfs ( x - 1, y );
	 	  if ( x < n && find ( get(x+1,y)) == find (get(x,y)) && f1[x+1][y] == 0 ) dfs ( x + 1 , y );
	 	  if ( y > 1 && find ( get(x,y-1)) == find (get(x,y)) && f1[x][y-1] == 0 ) dfs ( x , y - 1 );
	 	  if ( y < m && find ( get(x,y+1)) == find (get(x,y)) && f1[x][y+1] == 0 ) dfs ( x , y + 1 );
	 }
}
void work () {
	 long long i , j , l , x;
	 scanf ( "%I64d%I64d%I64d" , &n , &m , &k );
	 for ( i = 1 ; i <= n * m ; i++ ) c[i] = -1;
	 for ( i = 1 ; i <= n ; i++ ) for ( j = 1 ; j <= m ; j++ ) {
	 	 scanf ( "%I64d" , &map[i][j] );
	 	 s[get(i,j)].i = i; s[get(i,j)].j = j; s[get(i,j)].x = map[i][j];
	 }
	 sort ( s + 1 , s + 1 + m * n , cmp );
	 for ( i = 1 ; i <= n * m ; i++ ) {
	 	f[s[i].i][s[i].j] = 1;
	 	if ( f[s[i].i-1][s[i].j] == 1 ) Union ( find ( get(s[i].i-1,s[i].j) ) , find ( get(s[i].i,s[i].j) ) );
	 	if ( f[s[i].i+1][s[i].j] == 1 ) Union ( find ( get(s[i].i+1,s[i].j) ) , find ( get(s[i].i,s[i].j) ) );
	 	if ( f[s[i].i][s[i].j-1] == 1 ) Union ( find ( get(s[i].i,s[i].j-1) ) , find ( get(s[i].i,s[i].j) ) );
	 	if ( f[s[i].i][s[i].j+1] == 1 ) Union ( find ( get(s[i].i,s[i].j+1) ) , find ( get(s[i].i,s[i].j) ) );
	 	x = -c[find (get(s[i].i,s[i].j))];
	 	if ( k % s[i].x == 0 ) {
		   	 if ( x >= (k/s[i].x) ) {
			 	  ans = k / s[i].x;
			 	  dfs ( s[i].i , s[i].j );
			 	  break;
	 		 }
		}
	 }
	 if ( ans == 0 ) {
	 	  printf ( "NO\n" );
	 	  return ;
	 }
	 printf ( "YES\n" );
	 for ( i = 1 ; i <= n ; i++ , printf ( "\n" ) ) for ( j = 1 ; j <= m ; j++ ) printf ( "%I64d " , f1[i][j] ? k / f1[i][j] : 0 );
}
int main () {
	work ();
	return 0;
}