#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

mt19937 rnd(22341);
uniform_int_distribution<int> rng(0, 1000000000);

int get_random() {
	return rng(rnd);
}

struct Node {
	Node* l = nullptr;
	Node* r = nullptr;
	int y;
	int cnt = 1;
	bool isleft = false;
	Node* p = nullptr;
	int id;
	Node() {
		y = get_random();
	}
};

int cnt(Node* root) {
	if(root == nullptr) return 0;
	return root->cnt;
}

void update(Node* root) {
	if(root == nullptr) return;
	root->cnt = cnt(root->l) + cnt(root->r) + 1;
}

void update_p(Node* root, Node* p, bool isleft) {
	if(root == nullptr) return;
	root->p = p;
	root->isleft = isleft;
}

pair<Node*, Node*> split(Node* root, int amleft) {
	if(root == nullptr) {
		return {nullptr, nullptr};
	}
	int id1 = cnt(root->l);
	if(id1 < amleft) {
		auto p = split(root->r, amleft - id1 - 1);
		root->r = p.first;
		update_p(root->r, root, false);
		update(root);
		root->p = nullptr;
		return {root, p.second};
	} else {
		auto p = split(root->l, amleft);
		root->l = p.second;
		update_p(root->l, root, true);
		update(root);
		root->p = nullptr;
		return {p.first, root};
	}
}

Node* merge(Node* l, Node* r) {
	if(l == nullptr) {
		if(r != nullptr) {
			r->p = nullptr;
		}
		return r;
	}
	if(r == nullptr) {
		if(l != nullptr) {
			l->p = nullptr;
		}
		return l;
	}
	if(l->y > r->y) {
		l->r = merge(l->r, r);
		update_p(l->r, l, false);
		update(l);
		l->p = nullptr;
		return l;
	} else {
		r->l = merge(l, r->l);
		update_p(r->l, r, true);
		update(r);
		r->p = nullptr;
		return r;
	}
}


Node* swap_parts(Node* root, int amleft) {
	auto p = split(root, amleft);
	return merge(p.second, p.first);
}

Node* get_p(Node* root) {
	if(root->p == nullptr) {
		return root;
	}
	return get_p(root->p);
}

int get_ind(Node* root) {
	if(root->p == nullptr) {
		return cnt(root->l);
	}
	if(root->isleft) {
		return get_ind(root->p) - cnt(root->r) - 1;
	}
	return get_ind(root->p) + cnt(root->l) + 1;
}

int get_id(Node* root, int id1) {
	auto p = split(root, id1);
	auto p1 = split(p.second, 1);
	int ans = p1.first->id;
	merge(p.first, merge(p1.first, p1.second));
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, q;
    cin >> n >> q;
    vi p(n);
    for(int i = 0; i < n; i++) {
    	cin >> p[i];
    	--p[i];
    }
    vector<Node*> mass(n, nullptr);
    for(int i = 0; i < n; i++) {
    	Node* now = nullptr;
    	int now1 = i;
    	//cout << 1 << endl;
    	while(mass[now1] == nullptr) {
    		//cout << now1 << ' ';
    		mass[now1] = new Node();
    		mass[now1]->id = now1;
    		now = merge(now, mass[now1]);
    		//cout << cnt(now) << ' ' << now1 << endl;
    		now1 = p[now1];
    	}
    	//cout << 2 << endl;
    	//cout << cnt(now) << endl;
    }
    for(int o = 0; o < q; o++) {
    	int t;
    	cin >> t;
    	if(t == 1) {
    		int x, y;
    		cin >> x >> y;
    		--x;
    		--y;
    		Node* p1 = get_p(mass[x]);
    		Node* p2 = get_p(mass[y]);
    		if(p1 != p2) {
    			int id1 = get_ind(mass[x]);
    			Node* here1 = swap_parts(p1, id1 + 1);
    			id1 = get_ind(mass[y]);
    			Node* here2 = swap_parts(p2, id1 + 1);
    			merge(here1, here2);
    		} else {
    			int id1 = get_ind(mass[x]);
    			Node* here1 = swap_parts(p1, id1 + 1);
    			id1 = get_ind(mass[y]);
    			split(here1, id1 + 1);
    		}
    	} else {
    		int i, k;
    		cin >> i >> k;
    		--i;
    		Node* p = get_p(mass[i]);
    		int id1 = get_ind(mass[i]);
    		int need = id1 + k;
    		//cout << mass[i]->id << ' ' << id1 << ' ' << need << endl;
    		need %= p->cnt;
    		//cout << p->l->id << endl;
    		//cout << cnt(p) << endl;
    		cout << get_id(p, need) + 1 << '\n';
    		//cout << 2 << endl;
    	}
    }

}