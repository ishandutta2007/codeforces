#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100005;
typedef long long ll;

int n;
char str[10];
int op[N], opx[N];

struct Hash {
	int val, rank, id;
} hash[N];
int hn;

bool cmp(Hash a, Hash b) {
	return a.val < b.val;
}

#define lson(x) ((x<<1)+1)
#define rson(x) ((x<<1)+2)

struct Node {
	int l, r, mov;
 	ll k[5];
} node[N * 4];

void pushup(int x) {
	if (node[x].l == node[x].r) {
		ll tmp = 0;
		for (int i = 0; i < 5; i++) if (node[x].k[i]) tmp = node[x].k[i];
		if (tmp == 0) return;
		memset(node[x].k, 0, sizeof(node[x].k));
		node[x].k[node[x].mov % 5] = tmp;
		return;
 	}
	for (int i = 0; i < 5; i++)
		node[x].k[(i + node[x].mov) % 5] = node[lson(x)].k[i] + node[rson(x)].k[i];
}

void build(int l, int r, int x = 0) {
	node[x].l = l; node[x].r = r;
	node[x].mov = 0;
	memset(node[x].k, 0, sizeof(node[x].k));
	if (l == r) return;
	int mid = (l + r) / 2;
	build(l, mid, lson(x));
	build(mid + 1, r, rson(x));
}

void add(int l, int r, int v, int x = 0) {
	if (node[x].l >= l && node[x].r <= r) {
		node[x].mov += v;
		pushup(x);
		return;
 	}
 	int mid = (node[x].l + node[x].r) / 2;
 	if (l <= mid) add(l, r, v, lson(x));
 	if (r > mid) add(l, r, v, rson(x));
 	pushup(x);
}

int to[N];

void add2(int v, int val, int x = 0) {
	if (node[x].l == node[x].r) {
 		memset(node[x].k, 0, sizeof(node[x].k));
		if (val == 1)
  			node[x].k[node[x].mov % 5] = to[node[x].l];
		return;
 	}
	int mid = (node[x].l + node[x].r) / 2;
	if (v <= mid) add2(v, val, lson(x));
	if (v > mid) add2(v, val, rson(x));
	pushup(x);
}

int main() {
	hn = 0;
	scanf("%d", &n);
 	for (int i = 0; i < n; i++) {
	 	scanf("%s", str);
	 	if (str[0] == 'a' || str[0] == 'd') {
   			op[i] = 1;
   			if (str[0] == 'd') op[i] = -1;
   			scanf("%d", &opx[i]);
   			hash[hn].id = i;
   			hash[hn++].val = opx[i];
		} else op[i] = 0;
 	}
 	sort(hash, hash + hn, cmp);
 	to[0] = hash[0].val;
 	hash[0].rank = 0;
 	for (int i = 1; i < hn; i++) {
 		hash[i].rank = hash[i - 1].rank;
 		if (hash[i].val != hash[i - 1].val) {
    		hash[i].rank++;
    		to[hash[i].rank] = hash[i].val;
		}
  	}
  	build(0, hash[hn - 1].rank);
  	for (int i = 0; i < hn; i++)
  		opx[hash[i].id] = hash[i].rank;
	for (int i = 0; i < n; i++) {
		if (op[i] == 0) printf("%lld\n", node[0].k[3]);
		else {
  			add(opx[i], hash[hn - 1].rank, op[i]);
     		add2(opx[i], op[i]);
		}
 	}
	return 0;
}