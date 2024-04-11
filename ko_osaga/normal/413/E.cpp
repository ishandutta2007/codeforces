#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

struct node{
	int adj[2][2];
}empty;

node merge(node l, node r){
	node x;
	memset(x.adj, 0x3f, sizeof(r.adj));
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				x.adj[i][j] = min(x.adj[i][j], l.adj[i][k] + r.adj[k][j]);
			}
		}
	}
	return x;
}

struct seg{
	node tree[1050000];
	void init(int s, int e, int p, char *r1, char *r2){
		if(s == e){
			if(s % 2 == 1){
				tree[p].adj[0][0] = tree[p].adj[1][1] = 1;
				tree[p].adj[0][1] = tree[p].adj[1][0] = 1e6;
			}
			else{
				tree[p].adj[0][0] = (r1[s/2] == '.' ? 0 : 1e6);
				tree[p].adj[1][1] = (r2[s/2] == '.' ? 0 : 1e6);
				tree[p].adj[0][1] = tree[p].adj[1][0] = (r1[s/2] == '.' && r2[s/2] == '.' ? 1 : 1e6);
			}
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p, r1, r2);
		init(m+1, e, 2*p+1, r1, r2);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	node query(int s, int e, int ps, int pe, int p){
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps + pe) / 2;
		if(e <= pm) return query(s, e, ps, pm, 2*p);
		if(pm < s) return query(s, e, pm+1, pe, 2*p+1);
		return merge(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
}seg;

int n, q;
char str[2][200005];

int main(){
	scanf("%d %d %s %s",&n,&q,str[0],str[1]);
	seg.init(0, 2*n-2, 1, str[0], str[1]);
	while(q--){
		int x, y;
		scanf("%d %d",&x,&y);
		x--, y--;
		int r1 = x%n, r2 = y%n;
		int c1 = x/n, c2 = y/n;
		if(r1 > r2) swap(r1, r2), swap(c1, c2);
		node p = seg.query(2*r1, 2*r2, 0, 2*n-2, 1);
		if(p.adj[c1][c2] > 5e5) puts("-1");
		else printf("%d\n", p.adj[c1][c2]);
	}
}