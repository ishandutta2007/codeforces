#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <assert.h>

using namespace std;

struct node {
	map < long long , long long > *m;
	multiset < long long > *mn;
	long long del;
	
	node () {
		m = new map<long long,long long>;
		mn = new multiset<long long>;
		del = 0;
	}
};
long long n , taboo;
long long op[210000] , y[210000] , v[210000];
long long match[210000];
long long st[210000] , tops;
long long ans;
node solve ( long long l , long long r , long long ini ) {
	node ret , tmp;
	long long i , cost , t;
	//printf ( "@@@ %lld %lld\n" , l , r );
	(*ret.m)[ini] = 0;
	ret.mn -> insert ( 0 );
	for ( i = l ; i <= r ; i++ ) {
		//printf ( "%lld %lld %lld\n" , l , r , i );
		if ( op[i] == 1 ) {
			if ( y[i] != taboo ) {
				t = (*ret.mn->begin())+ret.del;
				ret.del += v[i];
				if ( ret.m -> find ( y[i] ) != ret.m -> end () ) {
					ret.mn -> erase ( ret.mn -> find ( (*ret.m)[y[i]] ) );
				}
				(*ret.m)[y[i]] = t - ret.del;
				ret.mn -> insert ( t - ret.del );
			}
			else {
				ret.del += v[i];
			}
		}
		else {
			if ( ret.m -> find ( y[i] ) != ret.m -> end () ) {
				tmp = solve ( i + 1 , match[i] - 1 , y[i] );

				//merge ans&tmp
				cost = (*ret.m)[y[i]] + ret.del;
				//printf ( "cost %lld\n" , cost );
				ret.mn -> erase ( ret.mn -> find ( (*ret.m)[y[i]] ) );
				ret.m -> erase ( y[i] );
				tmp.del += cost;
				if ( ret.m -> size () < tmp.m -> size () ) {
					swap ( ret , tmp );
				}
				for ( auto id : (*tmp.m) ) {
					if ( ret.m -> find ( id.first ) != ret.m -> end () ) {
						ret.mn -> erase ( ret.mn -> find ( (*ret.m)[id.first] ) );
						(*ret.m)[id.first] = min ( (*ret.m)[id.first] , id.second + tmp.del - ret.del );
					}
					else {
						(*ret.m)[id.first] = id.second + tmp.del - ret.del;
					}
					ret.mn -> insert ( (*ret.m)[id.first] );
				}
			}
			
			i = match[i];
		}
	}
	/*printf ( "%lld %lld del%lld mn%lld\n" , l , r , ret.del , *ret.mn->begin() );
	for ( auto id : (*ret.m) ) {
		printf ( "%lld %lld\n" , id.first , id.second );
	}*/
	return ret;
}
void work () {
	long long i;
	char z[120];
	node tmp;
	scanf ( "%lld%lld" , &n , &taboo );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%s" , z + 1 );
		if ( z[1] == 's' ) {
			op[i] = 1;
			scanf ( "%lld%lld" , &y[i] , &v[i] );
		}
		if ( z[1] == 'i' ) {
			op[i] = 2;
			scanf ( "%lld" , &y[i] );
			st[++tops] = i;
		}
		if ( z[1] == 'e' ) {
			op[i] = 3;
			match[i] = st[tops];
			match[st[tops]] = i;
			tops--;
		}
	}
	//printf ( "%d\n" , match[393] );
	tmp = solve ( 1 , n , 0 );
	ans = 21474836477777777ll;
	for ( auto id : *tmp.m ) {
		ans = min ( ans , id.second + tmp.del );
	}
	printf ( "%lld\n" , ans );
}
int main () {
	//freopen ( "g.in" , "r" , stdin );
	work ();
	return 0;
}