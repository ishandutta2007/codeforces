#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N = 200050; 
int read(void) {
	int x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-')f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if (f) return -x;
	return x;
}
struct node{
	int l, r;
	int dis[3][3];
	#define l(x) tree[x].l
	#define r(x) tree[x].r
}tree[N<<2];

#define p1 p << 1
#define p2 p << 1 | 1
const int inf = 400005;
inline mn(int x,int y) {
	return x > y ? y : x;
}

void update(node &fa,node ls,node rs) {
	for (int i = 1;i <= 2; i++) 
		for (int j = 1;j <= 2; j++) {
			fa.dis[i][j] = inf;
			for (int k = 1;k <= 2; k++) 
				fa.dis[i][j] = min(fa.dis[i][j], ls.dis[i][k] + rs.dis[k][j] + 1);
		}
}


int n, q;
char s[3][N];
void build(int l,int r,int p) {
	l(p) = l, r(p) = r;
	if (l == r) {
		tree[p].dis[1][2] = tree[p].dis[2][1] = 1;
		if (s[1][l] == 'X') 
			tree[p].dis[2][1] = tree[p].dis[1][1] = tree[p].dis[1][2] = inf;
		if (s[2][l] == 'X')
			tree[p].dis[1][2] = tree[p].dis[2][1] = tree[p].dis[2][2] = inf;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, p1); build(mid + 1, r, p2);
	update(tree[p], tree[p1], tree[p2]);
}

node query(int l,int r,int p) {
	if (l(p) >= l && r(p) <= r) return tree[p];
	if (l > r(p1)) return query(l, r, p2);
	if (r < l(p2)) return query(l, r, p1);
	node tmp; update(tmp, query(l, r, p1), query(l, r, p2));
	return tmp;
}
int main() {
	n = read(), q = read();
	scanf ("%s", s[1] + 1);
	scanf ("%s", s[2] + 1);
	build(1, n, 1);
	for (int i = 1;i <= q; i++) {
		int x1, x2, y1, y2; x1 = read(), x2 = read();
		if (x1 <= n) y1 = x1, x1 = 1;
		else y1 = x1 - n, x1 = 2;
		if (x2 <= n) y2 = x2, x2 = 1;
		else y2 = x2 - n, x2 = 2;
		if (y1 > y2) swap(x1, x2), swap(y1, y2);
		node tmp = query(y1, y2, 1);
		if (tmp.dis[x1][x2] >= inf) printf ("-1\n");
		else printf ("%d\n", tmp.dis[x1][x2]);
	}
	return 0;
}
/*

4 7
.X..
...X
5 1
1 3
7 7
1 4
6 1
4 7
5 7

*/