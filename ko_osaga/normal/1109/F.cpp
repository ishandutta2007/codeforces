#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 1e9 + 7;
const int MAXN = 250005;
const int MAXT = 530000;

struct node{
	node *l, *r, *p, *pp;
	int rev;
	node(){
		l = r = p = pp = NULL;
		rev = 0;
	}
	node(int x){
		l = r = p = pp = NULL;
		rev = 0;
	}
	void push(){
		if(rev){
			if(l) l->rev ^= 1;
			if(r) r->rev ^= 1;
			rev = 0;
			swap(l, r);
		}
	}
	void pull(){}
	void setLeft(node *p){
		push();
		l = p;
		p->p = this;
		pull();
	}
	void setRight(node *p){
		push();
		r = p;
		p->p = this;
		pull();
	}
	void rotate(){
		node *x = this;
		if(!x->p) return;
		x->p->push();
		x->push();
		node *p = x->p;
		bool is_left = (p->l == x);
		node *b = (is_left ? x->r : x->l);
		x->p = p->p;
		if(x->p && x->p->l == p) x->p->l = x;
		if(x->p && x->p->r == p) x->p->r = x;
		if(is_left){
			if(b) b->p = p;
			p->l = b;
			p->p = x;
			x->r = p;
		}
		else{
			if(b) b->p = p;
			p->r = b;
			p->p = x;
			x->l = p;
		}
		p->pull();
		x->pull();
		if(p->pp){ // IF YOU ARE LINK CUT TREE
			x->pp = p->pp;
			p->pp = NULL;
		}
	}
	void splay(){
		node *x = this;
		while(x->p){
			node *p = x->p;
			node *g = p->p;
			if(g){
				if((p->l == x) ^ (g->l == p)) x->rotate();
				else p->rotate();
			}
			x->rotate();
		}
	}
	node* prev(){
		splay();
		if(!l) return NULL;
		auto prv = l;
		prv->push();
		while(prv->r){
			prv = prv->r;
			prv->push();
		}
		prv->splay();
		return prv;
	}
	node* next(){
		splay();
		if(!r) return NULL;
		auto nxt = r;
		nxt->push();
		while(nxt->l){
			nxt = nxt->l;
			nxt->push();
		}
		nxt->splay();
		return nxt;
	}
	void access(){
		splay();
		push();
		if(r){
			r->pp = this;
			r->p = NULL;
			r = NULL;
		}
		pull();
		while(pp){
			node *nxt = pp;
			nxt->splay();
			nxt->push();
			if(nxt->r){
				nxt->r->pp = nxt;
				nxt->r->p = NULL;
				nxt->r = NULL;
			}
			pp = NULL;
			nxt->setRight(this);
			splay();
		}
	}
	node* root(){
		access();
		node *x = this;
		while(x->l){
			x->push();
			x = x->l;
		}
		x->access();
		return x;
	}
	node* par(){
		access();
		return prev();
	}
	void make_root(){
		access();
		rev ^= 1;
		push();
	}
};

node *lca(node *s, node *t){
	s->access(); t->access();
	s->splay();
	if(s->pp == NULL) return s;
	return s->pp;
}

void link(node *par, node *son){
	par->access();
	son->access();
	son->rev ^= 1;  // remove if needed
	son->setLeft(par);
}

void cut(node *p){
	p->access();
	p->push();
	if(p->l){
		p->l->p = NULL;
		p->l = NULL;
	}
	p->pull();
}

void cut(node *p, node *q){
	if(q->par() == p) swap(p, q);
	cut(p);
}

node* lct[MAXN];

int n;

pi merge(pi a, pi b){
	if(a > b) swap(a, b);
	if(a.first == b.first) a.second += b.second;
	return a;
}

struct seg{
	pi tree[MAXT];
	int lazy[MAXT];
	void lazydown(int p){
		for(int i=2*p; i<2*p+2; i++){
			tree[i].first += lazy[p];
			lazy[i] += lazy[p];
		}
		lazy[p] = 0;
	}
	void init(int s = 1, int e = n, int p = 1){
		if(s == e){
			tree[p] = pi(0, 1);
			return;
		}
		int m = (s+e)/2;
		init(s, m, 2*p);
		init(m + 1, e, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
	pi query(int s, int e, int ps = 1, int pe = n, int p = 1){
		if(e < ps || pe < s) return pi(1e9, 0);
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p);
		int pm = (ps + pe) / 2;
		return merge(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}
	void add(int s, int e, int x, int ps = 1, int pe = n, int p = 1){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p].first += x;
			lazy[p] += x;
			return;
		}
		lazydown(p);
		int pm = (ps + pe) / 2;
		add(s, e, x, ps, pm, 2*p);
		add(s, e, x, pm+1, pe, 2*p+1);
		tree[p] = merge(tree[2*p], tree[2*p+1]);
	}
}seg;

vector<int> gph[MAXN], rev[MAXN];
int low[MAXN];

int a[1005][1005];

int main(){
	int m;
	scanf("%d %d",&n,&m);
	if(n + m == 2){
		puts("1");
		return 0;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			a[i][j] = i * m + j + 1;
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m-1; j++){
			int l = a[i][j], r = a[i][j+1];
			gph[l].push_back(r);
			gph[r].push_back(l);
		}
	}
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m; j++){
			int l = a[i][j], r = a[i+1][j];
			gph[l].push_back(r);
			gph[r].push_back(l);
		}
	}
	n = n * m;
	low[0] = 1;
	for(int i=1; i<=n; i++){
		sort(all(gph[i]));
	}
	for(int i=1; i<=n; i++) lct[i] = new node();
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(j > i) break;
			pq.emplace(j, i);
			bool good = 1;
			while(lct[i]->root() == lct[j]->root()){
				auto qfr = pq.top(); pq.pop();
				low[i] = max(low[i], qfr.first + 1);
				if(qfr == pi(j, i)){
					good = 0;
					break;
				}
				cut(lct[qfr.first], lct[qfr.second]);
			}
			if(good) link(lct[i], lct[j]);
		}
	}
	for(int i=1; i<=n; i++) low[i] = max(low[i], low[i - 1]);
	seg.init();
	lint ret = 0;
	for(int i=1; i<=n; i++){
		seg.add(1, i, 1);
		for(auto &j : gph[i]){
			if(j > i) break;
			seg.add(1, j, -1);
		}
		auto qr = seg.query(low[i], i);
		if(qr.first == 1) ret += qr.second;
	}
	cout << ret << endl;
}