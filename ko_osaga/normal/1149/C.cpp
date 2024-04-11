#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXT = 530000;
using lint = long long;
using pi = pair<int, int>;

int n, q;
char str[MAXN];

struct node{
	int adj[4][4];
	int lazy;
};

node merge(node x, node y){
	node ret;
	ret.lazy = 0;
	for(int i=0; i<4; i++){
		for(int j=i; j<4; j++){
			ret.adj[i][j] = -1e9;
			for(int k=i; k<=j; k++){
				ret.adj[i][j] = max(ret.adj[i][j], x.adj[i][k] + y.adj[k][j]);
			}
		}
	}
	return ret;
}

struct seg{
	node tree[MAXT];
	void Apply(int p, int v){
		tree[p].lazy += v;
		tree[p].adj[0][1] += v;
		tree[p].adj[0][2] -= v;
		tree[p].adj[1][2] -= 2 * v;
		tree[p].adj[1][3] -= v;
		tree[p].adj[2][3] += v;
	}
	void upd(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			Apply(p, v);
			return;
		}
		if(tree[p].lazy){
			Apply(2 * p, tree[p].lazy);
			Apply(2 * p + 1, tree[p].lazy);
			tree[p].lazy = 0;
		}
		int pm = (ps + pe) / 2;
		upd(s, e, ps, pm, 2*p, v);
		upd(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
}seg;

int main(){
	scanf("%d %d %s",&n,&q,str);
	n = 2*n-2;
	for(int i=0; i<n; i++){
		if(str[i] == '(') seg.upd(i + 1, n, 0, n, 1, +1);
		else seg.upd(i + 1, n, 0, n, 1, -1);
	}
	printf("%d\n", seg.tree[1].adj[0][3]);
	while(q--){
		int x, y; scanf("%d %d",&x,&y);
		x--, y--;
		if(x > y) swap(x, y);
		if(str[x] != str[y]){
			if(str[x] == ')') seg.upd(x + 1, y, 0, n, 1, +2);
			else seg.upd(x + 1, y, 0, n, 1, -2);
			swap(str[x], str[y]);
		}
		printf("%d\n", seg.tree[1].adj[0][3]);
	}
}