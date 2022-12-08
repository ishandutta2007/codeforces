#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n , q;
int op[310000] , t[310000] , maxt;
int tt[310000] , t1[310000];
queue < int > que[310000];
void work () {
	int i , ans , cnt , nn = 0;
	scanf ( "%d%d" , &n , &q );
	ans = 0;
	for ( i = 1 ; i <= q ; i++ ) {
		scanf ( "%d%d" , &op[i] , &t[i] );
		if ( op[i] == 1 ) {
			que[t[i]].push ( i );
			ans += 1;
			tt[++nn] = t[i]; t1[nn] = i;
		}
		if ( op[i] == 2 ) {
			while ( que[t[i]].size () != 0 ) {
				ans--;
				que[t[i]].pop ();
			}
		}
		if ( op[i] == 3 ) {
			for ( maxt = maxt + 1 ; maxt <= t[i] ; maxt++ ) {
				//cout << maxt << " " << tt[maxt] << " " << t1[maxt]<< endl;
				if ( que[tt[maxt]].size () == 0 ) continue;
				if ( que[tt[maxt]].front () <= t1[t[i]] ) {
					ans--;
					que[tt[maxt]].pop ();
				}
			}
			if ( maxt > t[i] ) maxt--;
		}
		printf ( "%d\n" , ans );
	}
}
int main () {
	work ();
	return 0;
}