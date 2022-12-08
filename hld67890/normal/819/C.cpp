#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

//long long
long long n , m , s;
long long nn[4] , mm[4] , ss[4];
map < long long , long long > dn , dm , ds;
long long taboo[50] , cnt;
long long ans;
void clear () {
	long long i;
	dn.clear (); dm.clear (); ds.clear ();
	for ( i = 1 ; i <= cnt ; i++ ) taboo[i] = 0;
	cnt = 0;
	ans = 0;
}
long long poww ( long long f , long long x ) {
	/*long long s = 1;
	while ( x ) {
		if ( x % 2 == 1 ) s = s * f;
		f = f * f; x >>= 1;
	}
	return s;*/
	long long i , s = 1;
	for ( i = 1 ; i <= x ; i++ ) {
		if ( m / s < f ) return -1;
		s = s * f;
	}
	return s;
}
void solve ( long long pro , map<long long,long long>::iterator it ) {
	//printf ( "%I64d %I64d\n" , pro , it -> first );
	if ( pro > n ) return ;
	if ( it == ds.end() ) {
		ans++;
		return ;
	}
	long long i , x = it -> first , tmp = it -> second;
	it++;
	solve ( pro , it );
	for ( i = 1 ; i <= tmp ; i++ ) {
		pro = pro * x;
		solve ( pro , it );
	}
}
void work () {
	long long i , j , t , tmp , f;
	map<long long,long long>::iterator it;
	clear ();
	for ( i = 1 ; i <= 3 ; i++ ) {
		scanf ( "%I64d" , &nn[i] );
		t = nn[i];
		for ( j = 2 ; j * j <= nn[i] ; j++ ) {
			while ( t % j == 0 ) {
				t = t / j;
				dn[j]++;
			}
		}
		if ( t != 1 ) dn[t]++;
	}
	for ( i = 1 ; i <= 3 ; i++ ) {
		scanf ( "%I64d" , &mm[i] );
		t = mm[i];
		for ( j = 2 ; j * j <= mm[i] ; j++ ) {
			while ( t % j == 0 ) {
				t = t / j;
				dm[j]++;
			}
		}
		if ( t != 1 ) dm[t]++;
	}
	for ( i = 1 ; i <= 3 ; i++ ) {
		scanf ( "%I64d" , &ss[i] );
		t = ss[i];
		for ( j = 2 ; j * j <= ss[i] ; j++ ) {
			while ( t % j == 0 ) {
				t = t / j;
				ds[j]++;
			}
		}
		if ( t != 1 ) ds[t]++;
	}
	ds[2]++;
	n = nn[1] * nn[2] * nn[3];
	m = mm[1] * mm[2] * mm[3];
	s = ss[1] * ss[2] * ss[3];
	solve ( 1 , ds.begin() );
	//printf ( "%I64d\n" , ans );
	for ( it = dn.begin () ; it != dn.end () ; it++ ) {
		if ( it -> second > ds[it->first] ) {
			taboo[++cnt] = poww ( it -> first , ds[it->first] + 1 );
		}
	}
	for ( i = 0 ; i < (1<<cnt) ; i++ ) {
		t = i;
		j = 1;
		tmp = 1; f = 1;
		while ( t ) {
			if ( t % 2 == 1 ) {
				tmp = tmp * taboo[j];
				if ( taboo[j] == -1 ) {
					tmp = -1;
					break;
				}
				f = -f;
			}
			j++; t >>= 1;
		}
		//printf ( "%I64d %I64d %I64d\n" , f , tmp , m / tmp );
		if ( tmp != -1 ) ans += (m/tmp) * f;
	}
	printf ( "%I64d\n" , ans );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) work ();
	return 0;
}