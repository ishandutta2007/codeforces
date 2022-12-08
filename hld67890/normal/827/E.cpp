#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int NN = 510000;
const double pi = acos(-1);
struct complex {
	double r , i;
} a[NN*2*2] , b[NN*2*2] , c[NN*2*2] , d[NN*2*2];
int n , N;
char z[NN];
int ans[NN];
int out[NN] , tot;
complex operator + ( complex x1 , complex x2 ) {complex y;y.r = x1.r + x2.r;y.i = x1.i + x2.i;return y;}
complex operator - ( complex x1 , complex x2 ) {complex y;y.r = x1.r - x2.r;y.i = x1.i - x2.i;return y;}
complex operator * ( complex x1 , complex x2 ) {complex y;y.r = x1.r * x2.r - x1.i * x2.i;y.i = x1.r * x2.i + x1.i * x2.r;return y;}
void clear () {
	int i;
	for ( i = 0 ; i < N ; i++ ) {
		a[i].r = a[i].i = b[i].r = b[i].i = 0.0;
	}
	for ( i = 1 ; i <= n ; i++ ) {
		ans[i] = 0;
	}
	tot = 0;
}
double abs ( double x ) {
	if ( x < 0 ) return -x;
	return x;
}
int rev ( int x ) {
	int i , y;
	i = 1; y = 0;
	while ( i < N ) {
		y = y * 2 + (x%2);
		x >>= 1; i <<= 1;
	}
	return y;
}
void br ( complex *x ) {
	int i;
	for ( i = 0 ; i < N ; i++ ) d[rev(i)] = x[i];
	for ( i = 0 ; i < N ; i++ ) x[i] = d[i];
}
void FFT ( complex *x , int f ) {
	int i , j , s , k;
	complex u , t , w , wm;
	br ( x );
	for ( s = 2 ; s <= N ; s = s * 2 ) {
		k = s / 2;
		wm.r = cos (2*pi/s); wm.i = sin (2*pi/s) * f;
		for ( i = 0 ; i < N ; i += s ) {
			w.r = 1.0; w.i = 0.0;
			for ( j = 1 ; j <= k ; j++ ) {
				u = x[i+j-1]; t = x[i+j-1+k] * w;
				x[i+j-1] = u + t;
				x[i+j-1+k] = u - t;
				w = w * wm;
			}
		}
	}
	if ( f == -1 ) for ( i = 0 ; i < N ; i++ ) x[i].r = x[i].r / N;
}
void work () {
	int i , j;
	scanf ( "%d" , &n );
	scanf ( "%s" , z );
	N = 1;
	while ( N <= n * 2 ) N = N * 2;
	clear ();
	for ( i = 0 ; i < n ; i++ ) {
		if ( z[i] == 'V' ) a[i].r = 1;
		if ( z[i] == 'K' ) b[n-i-1].r = 1;
	}
	FFT ( a , 1 ); FFT ( b , 1 );
	for ( i = 0 ; i < N ; i++ ) c[i] = a[i] * b[i];
	FFT ( c , -1 );
	//for ( i = 0 ; i < N ; i++ )
	//	printf ( "%lf %lf\n" , c[i].r , c[i].i );
	for ( i = 0 ; i < N ; i++ ) {
		if ( abs ( c[i].r ) > 0.5 ) {
			ans[abs(i-n+1)] = 1;
		}
	}
	for ( i = 1 ; i <= n ; i++ ) {
		for ( j = i ; j <= n ; j += i ) if ( ans[j] == 1 ) break;
		if ( j > n ) out[++tot] = i;
	}
	printf ( "%d\n" , tot );
	for ( i = 1 ; i <= tot ; i++ ) printf ( "%d%c" , out[i] , i==tot?'\n':' ' );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}