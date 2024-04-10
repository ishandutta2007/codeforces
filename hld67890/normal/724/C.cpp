#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
	long long x , y;
	long long ans;
} s[120000];
struct nowpos {
	point x , d;
} now;
struct node {
	long long i;
	node *next;
} pool[3000000] , *g1[300000] , *g2[300000];
long long top;
long long n , m , k;
long long f1[300000] , f2[300000];
long long del;
void add1 ( long long x , long long y ) {
	node *tmp = &pool[++top];
	tmp -> i = y; tmp -> next = g1[x]; g1[x] = tmp;
}
void add2 ( long long x , long long y ) {
	node *tmp = &pool[++top];
	tmp -> i = y; tmp -> next = g2[x]; g2[x] = tmp;
}
long long abss ( long long x ) {
	if ( x >= 0 ) return x;
	return -x;
}
void find ( nowpos x ) {
	if ( x.d.x * x.d.y > 0 ){
		for ( node *j = g2[x.x.x-x.x.y+100000] ; j ; j = j -> next ) if ( s[j->i].ans == -1 || abss ( s[j->i].x - x.x.x ) + del < s[j->i].ans ) s[j->i].ans = abss ( s[j->i].x - x.x.x ) + del;
	}
	else {
		for ( node *j = g1[x.x.x+x.x.y] ; j ; j = j -> next ) if ( s[j->i].ans == -1 || abss ( s[j->i].x - x.x.x ) + del < s[j->i].ans ) s[j->i].ans = abss ( s[j->i].x - x.x.x ) + del;
	}
}
nowpos nextpos ( nowpos x ) {
	if ( x.d.x == 1 && x.d.y == 1 ) {
		if ( n - x.x.x > m - x.x.y ) {
			del += m - x.x.y;
			x.x.x += m - x.x.y; x.x.y = m;
			x.d.x = 1; x.d.y = -1;
		}
		else {
			del += n - x.x.x;
			x.x.y += n - x.x.x; x.x.x = n;
			x.d.x = -1; x.d.y = 1;
		}
		return x;
	}
	if ( x.d.x == 1 && x.d.y == -1 ) {
		if ( n - x.x.x > x.x.y ) {
			del += x.x.y;
			x.x.x += x.x.y; x.x.y = 0;
			x.d.x = 1; x.d.y = 1;
		}
		else {
			del += n - x.x.x;
			x.x.y -= n - x.x.x; x.x.x = n;
			x.d.x = -1; x.d.y = -1;
		}
		return x;
	}
	if ( x.d.x == -1 && x.d.y == 1 ) {
		if ( x.x.x > m - x.x.y ) {
			del += m - x.x.y;
			x.x.x -= m - x.x.y; x.x.y = m;
			x.d.x = -1; x.d.y = -1;
		}
		else {
			del += x.x.x;
			x.x.y += x.x.x; x.x.x = 0;
			x.d.x = 1; x.d.y = 1;
		}
		return x;
	}
	if ( x.d.x == -1 && x.d.y == -1 ) {
		if ( x.x.x > x.x.y ) {
			del += x.x.y;
			x.x.x -= x.x.y; x.x.y = 0;
			x.d.x = -1; x.d.y = 1;
		}
		else {
			del += x.x.x;
			x.x.y -= x.x.x; x.x.x = 0;
			x.d.x = 1; x.d.y = -1;
		}
		return x;
	}
}
void work () {
	long long i;
	scanf ( "%I64d%I64d%I64d" , &n , &m , &k );
	for ( i = 1 ; i <= k ; i++ ) {
		scanf ( "%I64d%I64d" , &s[i].x , &s[i].y );
		add1 ( s[i].x + s[i].y , i );
		add2 ( s[i].x - s[i].y + 100000 , i );
		s[i].ans = -1;
	}
	now.x.x = 0; now.x.y = 0;
	now.d.x = 1; now.d.y = 1;
	del = 0;
	while ( 1 ) {
		if ( now.d.x * now.d.y > 0 ) {
			if ( f2[now.x.x-now.x.y+100000] == 0 ) {
				f2[now.x.x-now.x.y+100000] = 1;
				find ( now );
			}
		}
		else {
			if ( f1[now.x.x+now.x.y] == 0 ) {
				f1[now.x.x+now.x.y] = 1;
				find ( now );
			}
		}
		now = nextpos ( now );
		//printf ( "%d %d %d %d\n" , now.x.x , now.x.y , now.d.x , now.d.y );
		if ( (now.x.x==0&&now.x.y==0) || (now.x.x==0&&now.x.y==m)
			|| (now.x.x==n&&now.x.y==0) || (now.x.x==n&&now.x.y==m) ) break;
	}
	for ( i = 1 ; i <= k ; i++ ) printf ( "%I64d\n" , s[i].ans );
}
int main () {
	work ();
	return 0;
}