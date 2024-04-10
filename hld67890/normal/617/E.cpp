#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct node {
	long long l , r , ls , rs , i , ans;
} q[200000];
long long n , m , k , size = 350;
long long a[200000] , sq[200000];
long long t[2100000] , tmp[2100000] , ans , tans , lastl , lastr;
long long aans[200000];
bool cmp ( node x1 , node x2 ) {
	if ( x1.ls == x2.ls ) return x1.r < x2.r;
	return x1.ls < x2.ls;
}
void work () {
	long long i , j;
	scanf ( "%I64d%I64d%I64d" , &n , &m , &k );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%I64d" , &a[i] );
	}
	for ( i = 1 ; i <= n ; i++ ) a[i] = a[i] ^ a[i-1];
	//for ( i = 1 ; i <= n ; i++ ) cout << a[i] << " ";
	//cout << endl;
	for ( i = 0 ; i <= n ; i++ ) sq[i] = i / size;
	for ( i = 1 ; i <= m ; q[i].i = i, i++ ) {
		scanf ( "%I64d%I64d" , &q[i].l , &q[i].r );
		q[i].l--;
		q[i].ls = sq[q[i].l]; q[i].rs = sq[q[i].r];
	}
	sort ( q + 1 , q + 1 + m , cmp );
	lastl = lastr = size;
	//cout << endl;
	for ( i = 1 ; i <= m ; i++ ) {
		if ( q[i].ls != q[i-1].ls ) {
			for ( j = 0 ; j <= 2000000 ; j++ ) t[j] = 0;
			ans = 0;
			lastl = size * (q[i].ls+1);
			lastr = size * (q[i].ls+1);
		}
		if ( q[i].ls == q[i].rs ) {
			tans = 0;
			//cout << q[i].l << " " << q[i].r << endl;
			for ( j = q[i].l ; j <= q[i].r ; j++ ) {
				tans += tmp[k^a[j]];
				tmp[a[j]]++;
			}
			//for ( j = 0 ; j <= 10 ; j++ ) cout << tmp[j] << " ";
			//cout << endl;
			for ( j = q[i].l ; j <= q[i].r ; j++ ) tmp[a[j]] = 0;
			q[i].ans = tans;
		}
		else {
			//cout << q[i].l << " " << q[i].r << " " << q[i].ls << " " << q[i].rs << endl;
			for ( j = lastr ; j <= q[i].r ; j++ ) {
				//cout << (k ^ a[j])  << "##$#$# " << a[j] << endl;
				ans += t[k^a[j]];
				t[a[j]]++;
			}
			lastr = j;
			//for ( j = 0 ; j <= 10 ; j++ ) cout << t[j] << " ";
			//cout << endl;
			//cout << lastl << endl;
			if ( lastl > q[i].l ) {
				for ( j = q[i].l ; j < lastl ; j++ ){
					ans += t[k^a[j]];
					t[a[j]]++;
					//cout << j <<endl;
				}
				lastl = q[i].l;
			}
			else {
				for ( j = lastl ; j < q[i].l ; j++ ){
					t[a[j]]--;
					ans -= t[k^a[j]];
				}
				lastl = q[i].l;
			}
			//for ( j = 0 ; j <= 10 ; j++ ) cout << t[j] << " ";
			//cout << endl;
			q[i].ans = ans;
		}
	}
	for ( i = 1 ; i <= m ; i++ ) aans[q[i].i] = q[i].ans;
	for ( i = 1 ; i <= m ; i++ ) printf ( "%I64d\n" , aans[i] );
}
int main () {
	work ();
	return 0;
}