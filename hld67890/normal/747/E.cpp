#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 1200000;
struct str {
	int l , r;
	str *next;
} pool[maxn * 2] , *g[maxn];
int top;
int n;
char z[maxn];
int s[maxn];
int ans , dep;
void add ( int x , int l , int r ) {
	str *tmp = &pool[++top];
	//printf ( "%d\n" , tmp );
	tmp -> l = l; tmp -> r = r; tmp -> next = g[x]; g[x] = tmp;
}
void output ( str *id ) {
	if ( !id ) return ;
	if ( id -> next ) output ( id -> next );
	int i;
	for ( i = id -> l ; i <= id -> r ; i++ ) printf ( "%c" , z[i] );
	printf ( " " );
}
int read ( int i ) {
	i++;
	while ( i <= n && z[i] != ',' ) i++;
	return i;
}
int get ( int l , int r ) {
	int i , s = 0;
	for ( i = l ; i <= r ; i++ ) s = s * 10 + (z[i]-'0');
	return s;
}
void work () {
	int i , j , k;
	scanf ( "%s" , z + 1 );
	n = strlen ( z + 1 );
	i = 0; dep = 1;
	ans = 0;
	while ( i <= n ) {
		j = read ( i );
		k = read ( j );
		add ( dep , i + 1 , j - 1 );
		ans = max ( ans , dep );
		s[dep] = get ( j + 1 , k - 1 ); s[dep-1]--;
		while ( dep >= 1 && s[dep] == 0 ) dep--;
		dep++;
		i = k;
	}
	printf ( "%d\n" , ans );
	for ( i = 1 ; i <= ans ; i++ ) {
		output ( g[i] );
		printf ( "\n" );
	}
}
int main () {
	work ();
	return 0;
}