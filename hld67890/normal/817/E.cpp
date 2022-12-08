#include <stdio.h>
#include <algorithm>

using namespace std;

const int NN = 120000;
struct node {
	int s;
	int ch[3];
} p[NN*30];
int top;
int q;
int ans;
void work () {
	int i , j , op , x , l , f , now;
	scanf ( "%d" , &q );
	top = 1;
	for ( j = 1 ; j <= q ; j++ ) {
		scanf ( "%d%d" , &op , &x );
		if ( op == 1 || op == 2 ) {
			if ( op == 1 ) f = 1;
			else f = -1;
			for ( i = 30 , now = 1 ; i >= 0 ; i-- ) {
				if ( !p[now].ch[(x&(1<<i))!=0?1:0] ) {
					p[now].ch[(x&(1<<i))!=0?1:0] = ++top;
				}
				p[now].s += f;
				now = p[now].ch[(x&(1<<i))!=0?1:0];
				//printf ( "%d\n" , now );
			}
			p[now].s += f;
		}
		else {
			scanf ( "%d" , &l );
			ans = 0;
			for ( i = 30 , now = 1 ; i >= 0 ; i-- ) {
				if ( now == 0 ) break;
				if ( (l&(1<<i)) ) ans += p[p[now].ch[(x&(1<<i))!=0?1:0]].s;
				//printf ( " %d %d %d\n" , (l&(1<<i)) , p[now].ch[((x)&(1<<i))!=0?1:0], ans );
				if ( (l&(1<<i)) ) now = p[now].ch[((x)&(1<<i))!=0?0:1];
				else now = p[now].ch[((x)&(1<<i))!=0?1:0];
			}
			printf ( "%d\n" , ans );
		}
	}
}
int main () {
	work ();
	return 0;
}