#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

struct node{
	node *l, *r, *p, *pp;
	int rev;
	bool isEdge;
	bool sub;
	bool lazy;
	int idx, propme;
	int edge;
	node(bool ie){
		l = r = p = pp = NULL;
		rev = 0;
		sub = 0;
		lazy = 0;
		isEdge = ie;
		edge = ie;
		idx = propme = -1;
	}
	void push(){
		if(rev){
			if(l) l->rev ^= 1;
			if(r) r->rev ^= 1;
			rev = 0;
			swap(l, r);
		}
		if(lazy){
			if(l){
				l->lazy = 1;
				l->propme = propme;
				if(l->isEdge) l->idx = propme;
				if(l->edge) l->sub = (propme == -1 ? 0 : 1);
			}
			if(r){
				r->lazy = 1;
				r->propme = propme;
				if(r->isEdge) r->idx = propme;
				if(r->edge) r->sub = (propme == -1 ? 0 : 1);
			}
			lazy = 0;
		}
	}
	void pull(){
		sub = (idx != -1);
		if(l) sub |= l->sub;
		if(r) sub |= r->sub;
		edge = isEdge;
		if(l) edge += l->edge;
		if(r) edge += r->edge;
	}
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
		pull();
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

struct edge{
	int s, e;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	vector<edge> a(m);
	for(int i = 0; i < m; i++){
		cin >> a[i].s >> a[i].e;
		a[i].s--;
		a[i].e--;
	}
	vector<node*> lct(n), enode(m);
	set<int> backEdge;
	for(int i = 0; i < n; i++) lct[i] = new node(false);
	int j = 0;
	lint ret = 0;
	for(int i = 0; i < m; i++){
		auto canAdd = [&](int u, int v){
			if(lct[u]->root() != lct[v]->root()) return true;
			lct[u]->make_root();
			lct[v]->access();
			if(lct[v]->sub) return false;
			return true;
		};
		auto removeBack = [&](int j){
			lct[a[j].s]->make_root();
			lct[a[j].e]->access();
			lct[a[j].e]->push();
			lct[a[j].e]->lazy = true;
			lct[a[j].e]->propme = -1;
			lct[a[j].e]->sub = 0;
			lct[a[j].e]->push();
			lct[a[j].e]->pull();
			backEdge.erase(j);
		};
		auto tryAdd = [&](int j){
			int u = a[j].s;
			int v = a[j].e;
			if(lct[u]->root() != lct[v]->root()){
				enode[j] = new node(true);
				link(enode[j], lct[a[j].e]);
				link(lct[a[j].s], enode[j]);
			}
			else{
				lct[u]->make_root();
				lct[v]->access();
				lct[v]->push();
				lct[v]->lazy = true;
				lct[v]->propme = j;
				lct[v]->push();
				lct[v]->pull();
				backEdge.insert(j);
			}
		};
		while(!canAdd(a[i].s, a[i].e)){
			if(backEdge.count(j)){
				removeBack(j);
			}
			else{
				enode[j]->access();
				if(enode[j]->idx != -1){
					int be = enode[j]->idx;
					removeBack(be);
					enode[j]->access();
					if(enode[j]->par() == lct[a[j].e]) swap(a[j].s, a[j].e);
					cut(enode[j]); cut(lct[a[j].e]);
					tryAdd(be);
				}
				else{
					enode[j]->access();
					if(enode[j]->par() == lct[a[j].e]) swap(a[j].s, a[j].e);
					cut(enode[j]); cut(lct[a[j].e]);
				}
			}
			j++;
		}
		tryAdd(i);
		ret += i + 1 - j;
	}
	cout << ret << "\n";
}