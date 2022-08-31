#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int getRand(int x, int y){
	return uniform_int_distribution<int>(x, y)(rng);
}

struct treap{
	struct Node{
		int k, size, a, id;
		Node* lft, *rgt;
		ll lazy, v;
		Node(){}
		Node(int key, int i, int p) : k(key), id(i), a(p){
			lft = rgt = NULL;
			size = 1;
			v = 0LL;
			lazy = 0;
		}
		void push(){
			if(lazy == 0) return;
			v += lazy;
			if(lft) lft->lazy += lazy;
			if(rgt) rgt->lazy += lazy;
			lazy = 0;
		}
		void fix(){
			assert(lazy == 0);
			if(lft) lft->push();
			if(rgt) rgt->push();
			size = 1 + (lft ? lft->size : 0) + (rgt ? rgt->size : 0);
		}
	};
	Node * root;
	treap(){
		root = NULL;
	}
	Node* merge(Node* x, Node* y){
		if(x) x->push();
		if(y) y->push();
		if(!x) return y;
		if(!y) return x;
		if(x->k > y->k){
			x->rgt = merge(x->rgt, y);
			x->fix();
			return x;
		} else{
			y->lft = merge(x, y->lft);
			y->fix();
			return y;
		}
	}
	void print(){
		function<void(Node*)> dfs = [&](Node* nd){
			if(!nd) return;
			nd->push();
			// trace(nd->id, nd->a, nd->v);
		};
		dfs(root);
	}
	pair<Node*, Node*> split(Node* x, int val){
		if(!x) return {NULL, NULL};
		x->push();
		if(x->a < val){
			pair<Node*, Node*> P = split(x->rgt, val);
			x->rgt = P.first;
			x->fix();
			return {x, P.second};
		} else{
			pair<Node*, Node*> P= split(x->lft, val);
			x->lft = P.second;
			x->fix();
			return {P.first, x};
		}
	}
	void insert(int i, int a){
		int k = getRand(0, 1 << 29);
		if(!root){
			root = new Node(k, i, a);
			return;
		}
		pair<Node*, Node*> P = split(root, a);
		Node * nd = new Node(k, i, a);
		root = merge(P.first, merge(nd, P.second));
	}
	// add t to all a >= val
	void add(int t, int val){
		// trace(t,val);
		pair<Node*, Node*> P = split(root, t);
		if(P.second){
			// trace(P.second->size);
			P.second->lazy += val;
		}
		root = merge(P.first, P.second);
	}
	int getGEQ(int t){
		pair<Node*, Node*> P = split(root, t);
		int ans = P.second ? P.second->size : 0;
		root = merge(P.first, P.second);
		return ans;
	}

	void getALL(vector<ll> & vec){
		function<void(Node*)> dfs = [&](Node* nd){
			if(!nd) return;
			nd->push();
			vec[nd->id] += nd->v;
			dfs(nd->lft);
			dfs(nd->rgt);
		};
		dfs(root);
	}
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	vector<int> a(n);
	vector<ll> ans(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll sum = 0, val = 0;
	for(int k = 0; k < n; k++){
		val += a[k] * 1LL * (k + 1);
		val += sum;
		sum += a[k];
		ans[k] = val;
	}
	// trace(ans);
	treap T, T2;
	int mx = *max_element(all(a));
	for(int i = n - 1; i >= 0; i--){
		// trace(i);
		T.insert(i, a[i]);
		int x = a[i];
		for(int r = 1; x * r <= mx; r++){
			// all >= x * r -> add -x
			T.add(x * r, x);
			// T.print();
		}
	}

	vector<ll> sub(n);
	T.getALL(sub);
	// trace(sub);
	for(int i = 0; i < n; i++){
		int x = a[i];
		for(int r = 1; x * r <= mx; r++){
			sub[i] += T2.getGEQ(x * r) * 1LL * x;
		}
		T2.insert(i, a[i]);
		// trace(i, sub);
	}
	// trace(sub);
	sum = 0;
	for(int k = 0; k < n; k++){
		sum += sub[k];
		cout << ans[k] - sum << " ";
	}
	cout << endl;
}