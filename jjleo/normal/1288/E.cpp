#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

struct Node{
	int son[2], val, fa, siz, pl;
}t[maxn];

int root;
int n, m; 

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

void up(int x){
	t[0].siz = 0;
	t[x].siz = t[ls(x)].siz + t[rs(x)].siz + 1;
} 

inline void add(int x, int y){
	t[x].pl += y, t[x].val += y;
}

inline void down(int x){
	if(t[x].pl){
		if(ls(x)) add(ls(x), t[x].pl);
		if(rs(x)) add(rs(x), t[x].pl);
		t[x].pl = 0;
	}
}

bool get(int x){
	return x == rs(t[x].fa);
}

void rotate(int x){
	int y = t[x].fa, z = t[y].fa;
	down(x);
	down(y);
	int k = get(x);
  	t[y].son[k] = t[x].son[k ^ 1];
  	t[t[y].son[k]].fa = y;
  	t[x].son[k ^ 1] = y;
  	t[y].fa = x;
  	t[x].fa = z;// 
  	if (z) t[z].son[y == rs(z)] = x;//get(y) y 
  	up(y);
  	up(x);//yx y 
}

void splay(int x, int f){//xf 
	while(t[x].fa != f){
		int y = t[x].fa;
		if(!t[y].fa){
			rotate(x);
			break;
		}
		if(t[y].fa == f){
			rotate(x);
			break;
		}
		if(get(x) == get(y)){
			rotate(y);
			rotate(x);
		}else{
			rotate(x);
			rotate(x);
		}
	} 
	if(!f) root = x;
}


int build(int l, int r, int fa){
	int mid = l + r >> 1;
	t[mid].fa = fa;
	t[mid].val = mid;
	t[mid].siz = 1;
	if(l <= mid - 1) ls(mid) = build(l, mid - 1, mid);
	if(mid + 1 <= r) rs(mid) = build(mid + 1 , r, mid);
	up(mid);
	return mid;
}

int pre(){
	down(root);
	int x = ls(root);
	while(rs(x)) down(x), x = rs(x);
	return x;
}

int L(){
	int x = root;
	while(ls(x)) down(x), x = ls(x);
	down(x);
	return x;
}

void dfs(int i){
	if(!i) return;
	down(i);
	dfs(ls(i));
	printf("%d-%d ", i, t[i].siz);
	dfs(rs(i));
}

int x;
int mn[maxn], mx[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) mn[i] = mx[i] = i;
	root = build(1, n, 0);
	while(m--){
		scanf("%d", &x);
		splay(x, 0);
		//printf("%d %d--\n", x, t[ls(x)].siz + 1);
		mn[x] = 1, mx[x] = max(mx[x], t[ls(x)].siz + 1);
		int y = pre();
		if(!y) continue;
		splay(y, 0), splay(x, y);
		int z = L();
		rs(y) = rs(x);
		if(rs(y)) t[rs(y)].fa = y;
		up(y);
		ls(z) = x, t[x].fa = z;
		rs(x) = 0, up(x), up(z);//debug: 
		while(z) up(z), z = t[z].fa;
		splay(x, 0);
		//dfs(root);puts("----");
	}
	for(int i = 1;i <= n;i++) splay(i, 0), printf("%d %d\n", mn[i], max(mx[i], t[ls(i)].siz + 1));
}