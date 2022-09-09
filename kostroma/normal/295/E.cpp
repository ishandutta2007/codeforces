#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();
#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

#define int li

struct treap {
	typedef struct _node {
		int key, prior;
		int cnt;
		int sumX;
		int sumEvery;
		_node* l;
		_node* r;
		_node(int key):key(key), prior( (rand() << 16) | rand() ), l(NULL), r(NULL), cnt(1), sumX(key), sumEvery(0) {}
		static int Cnt (_node* v) {
			if (!v)
				return 0;
			return v->cnt;
		}
		static int getSumX (_node* v) {
			if (!v)
				return 0;
			return v->sumX;
		}
		static int getSumEvery (_node* v) {
			if (!v)
				return 0;
			return v->sumEvery;
		}
		void recalc() {
			cnt = 1 + Cnt(l) + Cnt(r);
			sumX = key + getSumX(l) + getSumX(r);

			sumEvery = getSumEvery(l) + getSumEvery(r) + Cnt(l) * getSumX(r) - Cnt(r) * getSumX(l);
			sumEvery += Cnt(l) * key - getSumX(l) + getSumX(r) - Cnt(r) * key;

		}

	}*node;

	node root;
	treap():root(NULL) {}

	node merge (node l, node r) {
		if (!l)
			return r;
		if (!r)
			return l;
		if (l->prior < r->prior) {
			l->r = merge(l->r, r);
			l->recalc();
			return l;
		}
		else {
			r->l = merge(l, r->l);
			r->recalc();
			return r;
		}
	}

	void split (node v, int key, node& l, node& r) {
		l = r = 0;
		if (!v)
			return;
		if (v->key < key) {
			l = v;
			split(l->r, key, l->r, r);
			l->recalc();
		}
		else {
			r = v;
			split(r->l, key, l, r->l);
			r->recalc();
		}
	}

	void add (int key) {
		node l, r;
		split(root, key, l, r);
		root = merge(merge(l, new _node(key)), r);
	}

	void erase (int key) {
		node l, m, r;
		split(root, key, l, m);
		split(m, key + 1, m, r);
		root = merge(l, r);
	}

	int query (int L, int R) {
		node l, m, r;
		split(root, L, l, m);
		split(m, R + 1, m, r);
		int ans;
		if (!m)
			ans = 0;
		else
			ans = m->sumEvery;
		root = merge(merge(l, m), r);
		return ans;
	}

};

int n;
int x[100500];

void solve () {
	treap tree;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		tree.add(x[i]);
	}

	int m;
	cin >> m;
	for (int w = 0; w < m; ++w) {
		int t;
		cin >> t;
		if (t == 1) {
			int p, d;
			cin >> p >> d;
			--p;
			tree.erase(x[p]);
			x[p] += d;
			tree.add(x[p]);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << tree.query(l, r) << "\n";
		}
	}

}