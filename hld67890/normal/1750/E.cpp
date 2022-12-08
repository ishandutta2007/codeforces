#include <stdio.h>
#include <algorithm>

using namespace std;

//long long
long long del;
struct node {
	long long l , r , num , sum , clr;
	node *ll , *rr;
} pool[2120000] , *t1 , *t2;
struct so {
	long long x , f , le , ri;
} s[420000];
long long top;
long long n;
char z[220000];
long long ans;
void clear1 () {
	long long i;
	for ( i = 1 ; i <= top ; i++ ) {
		pool[i] = pool[0];
	}
	top = 0;
	ans = 0;
}
bool cmp ( so x1 , so x2 ) {
	if ( x1.x == x2.x ) return x1.f < x2.f;
	return x1.x < x2.x;
}
void clear ( node *id ) {
	id -> clr = 1;
	id -> num = id -> sum = 0;
}
void pushdown ( node *id ) {
	if ( id -> clr ) {
		id -> ll -> clr = 1;
		id -> ll -> num = id -> ll -> sum = 0;
		id -> rr -> clr = 1;
		id -> rr -> num = id -> rr -> sum = 0;
		id -> clr = 0;
	}
}
void update ( node *id ) {
	id -> num = id -> ll -> num + id -> rr -> num;
	id -> sum = id -> ll -> sum + id -> rr -> sum;
}
void buildtree ( node *id , long long l , long long r ) {
	id -> l = l; id -> r = r;
	//printf ( "%lld %lld\n" , l , r );
	id -> clr = 0;
	id -> num = id -> sum = 0;
	if ( l == r ) {
		return ;
	}
	long long mid = (l+r)/2;
	id -> ll = &pool[++top];
	id -> rr = &pool[++top];
	buildtree ( id -> ll , l , mid );
	buildtree ( id -> rr , mid + 1 , r );
}
void change ( node *id , long long l , long long num , long long sum ) {
	if ( id -> l == id -> r ) {
		id -> num += num;
		id -> sum += sum;
		return ;
	}
	pushdown ( id );
	long long mid=(id->l+id->r)/2;
	if ( l <= mid ) change ( id -> ll , l , num , sum );
	else change ( id -> rr , l , num , sum );
	update ( id );
}
long long querynum ( node *id , long long l , long long r ) {
	if ( id -> l == l && id -> r == r ) {
		return id -> num;
	}
	pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) return querynum(id->ll,l,r);
	else {
		if ( l > mid ) return querynum ( id -> rr , l , r );
		else return querynum(id->ll,l,mid) + querynum(id->rr,mid+1,r);
	}
}
long long querysum ( node *id , long long l , long long r ) {
	if ( id -> l == l && id -> r == r ) {
		return id -> sum;
	}
	pushdown ( id );
	long long mid = (id->l+id->r)/2;
	if ( r <= mid ) return querysum(id->ll,l,r);
	else {
		if ( l > mid ) return querysum ( id -> rr , l , r );
		else return querysum(id->ll,l,mid) + querysum(id->rr,mid+1,r);
	}
}
void solve ( long long l , long long r ) {
	long long i;
	long long mid = (l+r) / 2;
	long long sum1 , sum2;
	if ( l == r ) {
		ans++;
		return ;
	}
	solve ( l , mid );
	solve ( mid + 1 , r );
	so tmp;
	long long cnt = 0;
	tmp.x = 0; tmp.f = 1; tmp.le = tmp.ri = 0;
	for ( i = mid ; i >= l ; i-- ) {
		if ( z[i] == '(' ) {
			if ( tmp.le == 0 ) tmp.ri++;
			else tmp.le--;
		}
		else {
			tmp.le++;
		}
		tmp.x = tmp.ri;
		s[++cnt] = tmp;
	}
	tmp.x = 0; tmp.f = 2; tmp.le = tmp.ri = 0;
	for ( i = mid + 1 ; i <= r ; i++ ) {
		if ( z[i] == '(' ) {
			tmp.ri++;
		}
		else {
			if ( tmp.ri == 0 ) tmp.le++;
			else tmp.ri--;
		}
		tmp.x = tmp.le;
		s[++cnt] = tmp;
	}
	sort ( s + 1 , s + 1 + cnt , cmp );
	clear ( t1 );
	clear ( t2 );
	sum1 = sum2 = 0;
	int oans = ans;
	for ( i = 1 ; i <= cnt ; i++ ) {
		if ( s[i].f == 1 ) {
			change ( t1 , del + s[i].le - s[i].ri , 1 , s[i].le - s[i].ri );
			sum1 += s[i].ri;
		}
		else {
			change ( t2 , del + s[i].ri - s[i].le , 1 , s[i].ri - s[i].le );
			sum2 += s[i].le;
		}
	}
	//printf ( "solve %lld %lld %lld ans=%lld\n" , l , mid , r , ans );
	for ( i = 1 ; i <= cnt ; i++ ) {
		if ( s[i].f == 1 ) {
			change ( t1 , del + s[i].le - s[i].ri , -1 , (-1) * (s[i].le - s[i].ri) );
			sum1 -= s[i].ri;
			ans += sum2 + querynum ( t2 , 1 , del + s[i].le-s[i].ri ) * (s[i].le-s[i].ri) + querysum ( t2 , del + s[i].le-s[i].ri + 1 , n + 1 + del );
		}
		else {
			change ( t2 , del + s[i].ri - s[i].le , -1 , (-1) * (s[i].ri - s[i].le) );
			sum2 -= s[i].le;
			ans += sum1 + querynum ( t1 , 1 , del + s[i].ri-s[i].le ) * (s[i].ri-s[i].le) + querysum ( t1 , del + s[i].ri-s[i].le + 1 , n + 1 + del );
		}
		//printf ( " %lld %lld %lld %lld\n" , s[i].f , s[i].le , s[i].ri , ans );
	}
	//printf ( "solve    %lld %lld %lld delans=%lld\n" , l , mid , r , ans - oans );
}
void work () {
	long long i;
	//n = rand () % 10000 + 1;
	scanf ( "%lld" , &n );
	/*for ( i = 1 ; i <= n ; i++ ) {
		if ( rand () % 2 == 0 ) z[i] = '(';
		else z[i] = ')';
	}*/
	scanf ( "%s" , z + 1 );
	ans = 0;
	del = n + 10;
	t1 = &pool[++top];
	buildtree ( t1 , 1 , n + 1 + del );
	t2 = &pool[++top];
	buildtree ( t2 , 1 , n + 1 + del );
	solve ( 1 , n );
	printf ( "%lld\n" , ans );
	//printf ( "%lld\n" , top );
}
int main () {
	int t;
	scanf ( "%d" , &t );
	while ( t-- ) {
		work ();
		clear1();
	}
	return 0;
}