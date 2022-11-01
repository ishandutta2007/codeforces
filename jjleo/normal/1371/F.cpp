#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

struct Node{
	bool rev, id[2];
	bool sig[2], ld[2], rd[2];
	int l[2], r[2], m[2];
}t[maxn << 2];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

inline Node up(Node x, Node y){
	Node z;
	z.rev = false;
	z.id[0] = 0, z.id[1] = 1;
	for(int k = 0;k <= 1;k++){
		int i = x.id[k], j = y.id[k];
		z.ld[k] = x.ld[i], z.rd[k] = y.rd[j];
		if(x.sig[i] && y.sig[j]){
			z.m[k] = 0;
			if(x.rd[i] == y.ld[j] || (x.rd[i] == 1 && y.ld[j] == 0)){
				z.sig[k] = true;
				z.l[k] = z.r[k] = x.l[i] + y.r[j];
			}else{
				z.sig[k] = false;
				z.l[k] = x.l[i], z.r[k] = y.r[j];
			}
		}else{
			if(x.sig[i]) x.r[i] = 0;
			else if(y.sig[j]) y.l[j] = 0;
			z.sig[k] = false;
			z.l[k] = x.l[i], z.r[k] = y.r[j];
			z.m[k] = max(x.m[i], y.m[j]);
			if(x.rd[i] == y.ld[j] || (x.rd[i] == 1 && y.ld[j] == 0)){
				if(x.sig[i]){
					z.l[k] = x.l[i] + y.l[j];
				}else if(y.sig[j]){
					z.r[k] = x.r[i] + y.r[j];
				}else{
					z.m[k] = max(z.m[k], x.r[i] + y.l[j]);
				}
			}else{
				z.m[k] = max(z.m[k], max(x.r[i], y.l[j]));
			}
		}
	}
	return z;
}

inline void reverse(int x){
	t[x].rev ^= 1;
	swap(t[x].id[0], t[x].id[1]);
}

inline void down(int x){
	if(t[x].rev){
		t[x].rev = false;
		reverse(ls(x)), reverse(rs(x));
	}
}

Node query(int x, int l, int r, int ll, int rr){
	if(ll <= l && r <= rr){
		reverse(x);
		//printf("%d %d %d %d %d--\n", l, r, t[x].l[0], t[x].r[0], t[x].sig[0]);
		return t[x];
	}
	down(x);
	int mid = l + r >> 1;
	Node node;
	if(mid >= rr) node = query(ls(x), l, mid, ll, rr);
	else if(mid < ll) node = query(rs(x), mid + 1, r, ll, rr);
	else node = up(query(ls(x), l, mid, ll, rr), query(rs(x), mid + 1, r, ll, rr));
	t[x] = up(t[ls(x)], t[rs(x)]);
	//printf("%d %d %d %d %d--\n", l, r, node.l[0], node.r[0], node.sig[0]);
	return node;
}

char s[maxn];

void build(int x, int l, int r){
	if(l == r){
		int i = s[l] == '>';
		t[x].rev = false;
		t[x].id[0] = 0, t[x].id[1] = 1;
		t[x].sig[0] = t[x].sig[1] = true;
		t[x].m[0] = t[x].m[1] = 0;
		
		t[x].ld[0] = t[x].rd[0] = i;
		t[x].l[0] = t[x].r[0] = 1;
		
		t[x].ld[1] = t[x].rd[1] = i ^ 1;
		t[x].l[1] = t[x].r[1] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls(x), l, mid), build(rs(x), mid + 1, r);
	t[x] = up(t[ls(x)], t[rs(x)]);
	//printf("%d %d %d %d %d--\n", l, r, t[x].l[0], t[x].r[0], t[x].sig[0]);
}

int n, q;
int x, y;

int main(){
	scanf("%d%d%s", &n, &q, s + 1);
	build(1, 1, n);
	while(q--){
		scanf("%d%d", &x, &y);
		/*if(n == 500000){
			if(q == 99997){
				printf("%d %d--\n", x, y);
			}else{
				continue;
			}
		}*/
		Node node = query(1, 1, n, x, y);
		int i = node.id[0];
		printf("%d\n", max(node.m[i], max(node.l[i], node.r[i])));
	}
}