#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

struct Node{
	int son[2], fa;
	int sum, mx;
}t[maxn];

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

inline void up(int x){
	t[x].sum = t[ls(x)].sum + t[rs(x)].sum + 1;
	t[x].mx = max(x, max(t[ls(x)].mx, t[rs(x)].mx));
} 

inline bool get(int x){
	return x == rs(t[x].fa);
}

inline bool isRoot(int x){
	return ls(t[x].fa) != x && rs(t[x].fa) != x;
}

inline void rotate(int x){
	int y = t[x].fa, z = t[y].fa, k = get(x);
	if(!isRoot(y)) t[z].son[y == rs(z)] = x;// yisRoot  
  	t[y].son[k] = t[x].son[k ^ 1];
  	t[t[y].son[k]].fa = y;
  	t[x].son[k ^ 1] = y;
  	t[y].fa = x;
  	t[x].fa = z;
  	up(y);
  	up(x);
}


inline void splay(int x){
	for(int fa = t[x].fa;x && !isRoot(x);rotate(x), fa = t[x].fa){//isRootx 
		if(!isRoot(fa)) rotate(get(x) == get(fa) ? fa : x);
	}
}

inline int access(int x){
	int p = 0;
	for(;x;p = x, x = t[x].fa){
		splay(x);
		t[x].son[1] = p;
		up(x);
	}
	return p;
}

inline void link(int x, int y){
	splay(x), t[x].fa = y;
}

inline void cut(int x){
	access(x), splay(x);
	ls(x) = t[ls(x)].fa = 0, up(x);
}


int n, m;
int opt, x, y;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x), up(i);
		if(i + x <= n) link(i, i + x);
	}
	while(m--){
		scanf("%d", &opt);
		switch(opt){
			case 0:
				scanf("%d%d", &x, &y);
				cut(x);
				if(x + y <= n) link(x, x + y);
				break;
			case 1:
				scanf("%d", &x);
				access(x), splay(x);//debug:access 
				printf("%d %d\n", t[x].mx, t[x].sum);
				break;		
		}
	}
}