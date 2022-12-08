#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

//long long
const long long maxn = 120000;
struct node {
    long long x , y;
} p[maxn] , q[maxn];
long long n , m;
long long con1[maxn] , con2[maxn] , tot1 , tot2;
long long a[maxn*8] , b[maxn*8] , next[maxn*8];
bool cmp ( node x1 , node x2 ) {
    if ( x1.x == x2.x ) return x1.y < x2.y;
    return x1.x < x2.x;
}
long long abss ( long long x ) {
    if ( x < 0 ) return -x;
    return x;
}
long long det1 ( long long i , long long j , long long k ) {
    long long x1 , x2 , yy1 , yy2;
    //printf ( "%I64d %I64d %I64d\n" , i , j , k );
    x1 = p[j].x - p[i].x; yy1 = p[j].y - p[i].y;
    x2 = p[k].x - p[i].x; yy2 = p[k].y - p[i].y;
    return x1*yy2-x2*yy1;
}
void convex1 () {
    long long i , tmp;
    con1[1] = 1; tot1 = 1;
    for ( i = 2 ; i <= n ; i++ ) {
        while ( tot1 > 1 && det1 ( con1[tot1-1] , con1[tot1] , i ) >= 0 ) tot1--;
        con1[++tot1] = i;
    }
    tmp = tot1;
    for ( i = n - 1 ; i >= 1 ; i-- ) {
        while ( tot1 > tmp && det1 ( con1[tot1-1] , con1[tot1] , i ) >= 0 ) tot1--;
        con1[++tot1] = i;
    }
    //for ( i = 1 ; i <=  3 ; i++ ) printf ( "%I64d\n" , con1[i] );
    //printf ( "@%I64d\n" , tot1 );
    tot1--;
}
long long det2 ( long long i , long long j , long long k ) {
    long long x1 , x2 , yy1 , yy2;
    //printf ( "%I64d %I64d %I64d\n" , i , j , k );
    x1 = q[j].x - q[i].x; yy1 = q[j].y - q[i].y;
    x2 = q[k].x - q[i].x; yy2 = q[k].y - q[i].y;
    return x1*yy2-x2*yy1;
}
void convex2 () {
    long long i , tmp;
    con2[1] = 1; tot2 = 1;
    for ( i = 2 ; i <= m ; i++ ) {
        while ( tot2 > 1 && det2 ( con2[tot2-1] , con2[tot2] , i ) >= 0 ) tot2--;
        con2[++tot2] = i;
    }
    tmp = tot2;
    for ( i = m - 1 ; i >= 1 ; i-- ) {
        while ( tot2 > tmp && det2 ( con2[tot2-1] , con2[tot2] , i ) >= 0 ) tot2--;
        con2[++tot2] = i;
    }
    tot2--;
}
unsigned long long dis ( node x1 , node x2 ) {
	return ( (x1.x-x2.x)*(x1.x-x2.x) + (x1.y-x2.y)*(x1.y-x2.y) );
}
long long det ( node i , node j , node k ) {
    long long x1 , x2 , yy1 , yy2;
    //printf ( "%I64d %I64d %I64d\n" , i , j , k );
    x1 = j.x - i.x; yy1 = j.y - i.y;
    x2 = k.x - i.x; yy2 = k.y - i.y;
    return x1*yy2-x2*yy1;
}
void work () {
	long long i , j;
	scanf ( "%I64d%I64d" , &n , &m );
    for ( i = 1 ; i <= n ; i++ ) {
        scanf ( "%I64d%I64d" , &p[i].x , &p[i].y );
    }
	for ( i = 1 ; i <= m ; i++ ) {
        scanf ( "%I64d%I64d" , &q[i].x , &q[i].y );
    }
    sort ( p + 1 , p + 1 + n , cmp );
    convex1 ();
    sort ( q + 1 , q + 1 + m , cmp );
    convex2 ();
    if ( tot1 != tot2 ) {
    	printf ( "NO\n" );
    	return ;
    }
    con1[tot1+1] = con1[1];
    con1[tot1+2] = con1[2];
    con2[tot2+1] = con2[1];
    con2[tot2+2] = con2[2];
    for ( i = 1 ; i <= tot1 ; i++ ) {
    	a[i*2-1] = dis ( p[con1[i]] , p[con1[i+1]] );
    	a[i*2] = det ( p[con1[i+1]] , p[con1[i]] , p[con1[i+2]] );
    }
    for ( i = 1 ; i <= tot1 * 2 ; i++ ) {
    	a[i+tot1*2] = a[i];
    }
    for ( i = 1 ; i <= tot2 ; i++ ) {
    	b[i*2-1] = dis ( q[con2[i]] , q[con2[i+1]] );
    	b[i*2] = det ( q[con2[i+1]] , q[con2[i]] , q[con2[i+2]] );
    }
    j = 0;
    next[1] = 0;
    for ( i = 2 ; i <= tot2 * 2 ; i++ ) {
    	while ( j != 0 && b[j+1] != b[i] ) j = next[j];
    	if ( b[j+1] == b[i] ) j++;
    	next[i] = j;
    }
    j = 0;
    for ( i = 1 ; i <= tot1 * 4 ; i++ ) {
    	while ( j != 0 && b[j+1] != a[i] ) j = next[j];
    	if ( b[j+1] == a[i] ) j++;
    	if ( j == tot2 * 2 ) {
    		printf ( "YES\n" );
    		return ;
    	}
    }
    printf ( "NO\n" );
}
int main () {
	work ();
	return 0;
}