#include <stdio.h>
#include <algorithm>
#include <time.h>

using namespace std;

struct so {
	long long s , sum;
} q[420000];
struct node {
	long long v , u , taboo;
	node *next , *rev;
} pool[1200000] , *g[420000] , *og[420000];
long long top;
long long n , index;
long long a[420000];
long long key[420000];
long long siz[420000] , belong[420000] , used[420000];
long long s[420000] , mxdep , tot;
long long pos[420000] , first , last;
long long ans;
void clear () {
	long long i;
	for ( i = 1 ; i <= mxdep ; i++ ) {
		s[i] = 0;
	}
	for ( i = 1 ; i <= tot ; i++ ) q[i] = q[0];
}
bool cmp ( so x1 , so x2 ) {
	return x1.sum < x2.sum;
}
void add ( long long u , long long v ) {
	node *tmp1 = &pool[++top] , *tmp2 = &pool[++top];
	tmp1 -> v = v; tmp1 -> next = og[u]; og[u] = tmp1;
	tmp2 -> v = u; tmp2 -> next = og[v]; og[v] = tmp2;
}
void add1 ( long long u , long long v ) {
	node *tmp1 = &pool[++top] , *tmp2 = &pool[++top];
	//printf ( "%lld %lld\n" , u , v );
	tmp1 -> v = v; tmp1 -> u = u; tmp1 -> next = g[u]; g[u] = tmp1; tmp1 -> rev = tmp2;
	tmp2 -> v = u; tmp2 -> u = v; tmp2 -> next = g[v]; g[v] = tmp2; tmp2 -> rev = tmp1;
}
void rebuild ( long long i , long long from ) {
	long long lst = i , tmp;
	for ( node *j = og[i] ; j ; j = j -> next ) if ( j -> v != from ) {
		tmp = ++index;
		belong[tmp] = i;
		add1 ( lst , tmp );
		add1 ( tmp , j -> v );
		lst = tmp;
		//add1 ( i , j -> v );
		rebuild ( j -> v , i );
	}
}
void dfs1 ( long long i , long long from ) {
	siz[i] = 1;
	//printf ( "%lld %lld\n" , i , from );
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && j -> taboo == 0 ){
		dfs1 ( j -> v , i );
		siz[i] += siz[j->v];
	}
}
node *dfs2 ( long long i , long long from , long long tot ) {
	node *ret = NULL;
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && j -> taboo == 0 ) {
		if ( siz[j->v] * 2 >= tot ) {
			ret = dfs2 ( j -> v , i , tot );
			if ( ret == NULL ) return j;
			return ret;
		}
		if ( ret == NULL || siz[j->v] > siz[ret->v] ) ret = j;
	}
	return ret;
}
void dfs3 ( long long i , long long from , long long sum , long long dep , long long ssum ) {
	//printf ( "%lld %lld %lld %lld %lld\n" , i , from , sum ,dep , ssum );
	int f = 0;
	if ( !used[belong[i]] ) {
		sum += a[belong[i]];
		dep++;
		used[belong[i]] = 2;
		f = 1;
		mxdep = max ( mxdep , dep );
		ssum += sum;
		s[dep] = max ( s[dep] , ssum );
	}
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && j -> taboo == 0 ) {
		dfs3 ( j -> v , i , sum , dep , ssum );
	}
	if ( f ) used[belong[i]] = 0;
}
void dfs4 ( long long i , long long from , long long sum , long long dep , long long ssum ) {
	int f = 0;
	if ( !used[belong[i]] ) {
		sum += a[belong[i]];
		dep++;
		used[belong[i]] = 2;
		f = 1;
		ssum += a[belong[i]] * dep;
		tot++;
		q[tot].s = ssum; q[tot].sum = sum;
	}
	for ( node *j = g[i] ; j ; j = j -> next ) if ( j -> v != from && j -> taboo == 0 ) {
		dfs4 ( j -> v , i , sum , dep , ssum );
	}
	if ( f ) used[belong[i]] = 0;
}
double getcross ( long long u , long long v ) {
	return (double)(s[v]-s[u]) / (double)(u-v);
}
void getans ( long long u , long long v ) {
	long long i , tsum , tdep , tssum;
	mxdep = 0; tot = 0;
	if ( belong[u] == belong[v] ) {
		tsum = a[belong[u]];
		tdep = 1;
		tssum = a[belong[u]];
		s[1] = a[belong[u]];
		mxdep = 1;
		dfs3 ( u , -1 , tsum , tdep , tssum );
		if ( mxdep == 0 ) return ;
		dfs4 ( v , -1 , 0 , 0 , 0 );
		if ( tot == 0 ) {
			clear ();
			return ;
		}
	}
	else {
		if ( u > n ) {
			tsum = a[belong[u]];
			tdep = 1;
			tssum = a[belong[u]];
			s[1] = a[belong[u]];
			mxdep = 1;
		}
		else {
			tsum = tdep = tssum = 0;
		}
		dfs3 ( u , -1 , tsum , tdep , tssum );
		if ( mxdep == 0 ) return ;
		if ( v > n ) {
			tsum = a[belong[v]];
			tdep = 1;
			tssum = a[belong[v]];
			tot++;
			q[tot].s = q[tot].sum = a[belong[v]];
		}
		else {
			tsum = tdep = tssum = 0;
		}
		dfs4 ( v , -1 , tsum , tdep , tssum );
		if ( tot == 0 ) {
			clear ();
			return ;
		}
	}
	sort ( q + 1 , q + 1 + tot , cmp );
	first = 0;
	for ( i = 1 ; i <= mxdep ; i++ ) {
		//printf ( "s%lld num%lld\n" , s[i] , i );
		while ( first >= 2 && getcross ( pos[first-1] , pos[first] ) > getcross ( pos[first-1] , i ) ) first--;
		pos[++first] = i;
	}
	last = 1;
	for ( i = 1 ; i <= tot ; i++ ) {
		//printf ( "s%lld sum%lld\n" , q[i].s , q[i].sum );
		while ( last < first && getcross ( pos[last] , pos[last+1] ) <= q[i].sum ) last++;
		ans = max ( ans , q[i].s + s[pos[last]] + q[i].sum * pos[last] );
	}
	//printf ( "u=%lld v=%lld mxdep=%lld tot=%lld\n" , u , v , mxdep , tot );
	clear ();
	//printf ( "%lld\n" , ans );
}
void solve ( long long u ) {
	dfs1 ( u , -1 );
	if ( siz[u] == 1 ) return ;
	//printf ( "%lld\n" , u );
	node *root = dfs2 ( u , -1 , siz[u] );
	long long v;
	u = root -> u; v = root -> v;
	//printf ( "$$%lld %lld\n" , u , v );
	root -> taboo = 1; root -> rev -> taboo = 1;
	if ( u != belong[u] ) used[belong[u]] = 1;
	if ( v != belong[v] ) used[belong[v]] = 1;
	getans ( u , v ); getans ( v , u );
	used[belong[u]] = used[belong[v]] = 0;
	solve ( u ); solve ( v );
}
void work () {
	long long i , u , v;
	scanf ( "%lld" , &n );
	//srand(2200);
	//n = 20000;
	for ( i = 1 ; i < n ; i++ ) {
		scanf ( "%lld%lld" , &u , &v );
		//u = i + 1; v = max ( 1ll , rand () % i + 1  );
		//printf ( "%lld %lld\n" , u , v );
		add ( u , v );
	}
	for ( i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &a[i] );
		//a[i] = rand () % 10 + 1;
		//printf ( "%lld%c" , a[i] , i == n ? '\n' : ' ' );
		key[i] = 1; belong[i] = i;
	}
	index = n;
	rebuild ( 1 , -1 );
	solve ( 1 );
	printf ( "%lld\n" , ans );
}
int main () {
	work ();
	return 0;
}