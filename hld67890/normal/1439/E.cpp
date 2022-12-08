#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

#define pii pair<int,int>
#define piii pair<pair<int,int> , int>
#define fi first
#define se second

using namespace std;

int n;
int x1[120000] , y1[120000] , x2[120000] , y2[120000];
int a[1200000];
map < pii , int > m;
map < int , int > l;
int tot , ntot , cntm;
pii v[1210000] , lc[120000] , fa[1200000];
pii st[1200000];
int tops;
int ans;
bool operator < ( pii x1 , pii x2 ) {
	return x1.fi + x1.se < x2.fi + x2.se;
}
int lowbit ( int x ) {
	if ( x == 0 ) return 2147483647;
	return x & (-x);
}
pii top ( pii x ) {
	if ( x.fi == 0 || x.se == 0 ) return make_pair(0,0);
	int mask;
	if ( lowbit ( x.fi ) < lowbit ( x.se ) ) {
		mask = lowbit ( x.se ) - 1;
		x.fi &= (~mask);
	}
	else {
		mask = lowbit ( x.fi ) - 1;
		x.se &= (~mask);
	}
	return x;
}
pii tfa ( pii x ) {
	if ( lowbit ( x.fi ) < lowbit ( x.se ) ) {
		x.fi--;
	}
	else {
		x.se--;
	}
	return x;
}
piii lca ( pii x1 , pii x2 ) {
	pii ox1 = x1 , ox2 = x2 , lx1;
	if ( x1 == x2 ) {
		return make_pair(x1,0);
	}
	if ( x1 == make_pair(0,0) ) {
		return make_pair(x1,1);
	}
	if ( x2 == make_pair(0,0) ) {
		return make_pair(x2,0);
	}
	//printf ( "lca %d %d %d %d\n" , x1.fi , x1.se , x2.fi , x2.se );
	while ( top ( x1 ) != top ( x2 ) ) {
		//printf ( "%d %d %d %d\n" , x1.fi , x1.se , x2.fi , x2.se );
		if ( top ( x1 ) < top ( x2 ) ) {
			x2 = top ( x2 );
		}
		else {
			lx1 = x1;
			x1 = top ( x1 );
		}
	}
	piii ret;
	int s1 = 0 , s2 = 0;
	if ( top ( x1 ).fi == x1.fi ) {
		s2++;
	}
	else s1++;
	if ( top ( x2 ).fi == x2.fi ) {
		s2++;
	}
	else s1++;
	if ( s1 == 0 || s2 == 0 ) {
		if ( x1 < x2 ) ret.fi = x1;
		else ret.fi = x2;
	}
	else ret.fi = top ( x1 );
	//printf ( "%d %d %d %d\n" , ret.fi.fi , ret.fi.se , x1.fi , x1.se );
	if ( ret.fi != ox1 && ret.fi != ox2 ) {
		if ( x1 == ret.fi ) x1 = lx1;
		if ( ret.fi.se == x1.se ) ret.se = 1;
		else ret.se = 0;
	}
	else {
		if ( ret.fi == ox1 ) ret.se = 1;
		else ret.se = 0;
	}
	//printf ( "%d %d\n" , ret.fi.fi , ret.fi.se );
	return ret;
}
bool cmp ( pii x1 , pii x2 ) {
	//printf ( "%d %d %d %d %d\n" , x1.fi , x1.se , x2.fi , x2.se , lca(x1,x2).se );
	return lca ( x1 , x2 ).se;
}
void work () {
	int i , sum , b1 , b2;
	pii t1 , t2 , nowlca;
	//printf ( "%d\n" , cmp ( {1,6} , {0,8} ) );
	scanf ( "%d" , &n );
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d%d%d" , &x1[i] , &y1[i] , &x2[i] , &y2[i] );
		t1 = make_pair ( x1[i] , y1[i] );
		t2 = make_pair ( x2[i] , y2[i] );
		if ( m[t1] == 0 ) {
			v[++tot] = t1;
			m[t1] = tot;
		}
		a[m[t1]]++;
		if ( m[t2] == 0 ) {
			v[++tot] = t2;
			m[t2] = tot;
		}
		a[m[t2]]++;
		nowlca = lca ( t1 , t2 ).fi;
		if ( nowlca != make_pair(0,0) ) {
			nowlca = tfa ( nowlca );
			lc[i] = nowlca;
			if ( m[nowlca] == 0 ) {
				v[++tot] = nowlca;
				m[nowlca] = tot;
			}
			a[m[nowlca]] -= 2;
		}
		else lc[i] = make_pair(-1,-1);
	}
	sort ( v + 1 , v + 1 + tot , cmp );
	cntm = tot;
	ntot = tot;
	for ( i = 1 ; i < tot ; i++ ) {
		v[++ntot] = lca ( v[i] , v[i+1] ).fi;
	}
	sort ( v + 1 , v + 1 + ntot , cmp );
	/*for ( i = 1 ; i <= tot ; i++ ) {
		printf ( "%d %d %d %d\n" , v[i].fi , v[i].se , m[v[i]] , a[m[v[i]]]);
	}
	printf ( "\n" );*/
	tot = 0;
	for ( i = 1 ; i <= ntot ; i++ ) {
		if ( i == 1 || v[i] != v[tot] ) {
			v[++tot] = v[i];
			if ( m[v[tot]] == 0 ) {
				m[v[tot]] = ++cntm;
			}
		}
	}
	tops = 1;
	st[1] = v[1];
	for ( i = 2 ; i <= tot ; i++ ) {
		while ( tops && lca ( st[tops] , v[i] ).fi != st[tops] ) {
			fa[m[st[tops]]] = st[tops-1];
			//printf ( "%d %d\n" , i , tops );
			tops--;
		}
		st[++tops] = v[i];
	}
	while ( tops >= 2 ) {
		fa[m[st[tops]]] = st[tops-1];
		tops--;
	}
	/*for ( i = 1 ; i <= tot ; i++ ) {
		printf ( "%d %d fa: %d %d\n" , v[i].fi , v[i].se , fa[m[v[i]]].fi , fa[m[v[i]]].se );;
	}*/
	for ( i = tot ; i >= 1 ; i-- ) {
		a[m[fa[m[v[i]]]]] += a[m[v[i]]];
		if ( a[m[v[i]]] != 0 ) {
			l[v[i].fi + v[i].se]++;
			if ( v[i] != make_pair(0,0) ) {
				pii father = fa[m[v[i]]];
				l[father.fi + father.se]--;
			}
		}
	}
	sum = 0;
	for ( auto it = l.rbegin() ; it != l.rend () ; it++ ) {
		//printf ( "%d %d\n" , it -> first , it -> second );
		b1 = sum % 2;
		sum += it -> second;
		b2 = sum % 2;
		if ( b1 != b2 ) {
			ans++;
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}