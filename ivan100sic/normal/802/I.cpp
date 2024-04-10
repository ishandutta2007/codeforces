#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int len, sz;
	node* link;
	map<char, node*> next;
	ll dp;
};

vector<node*> automat(const string& s) {
	node* root, *last;
	root = last = new node {0, 0, nullptr, {}, 0};
	vector<node*> v = {root};
	for (char c : s) {
		node* curr = new node {last->len+1, 1, nullptr, {}, 0};
		v.push_back(curr);
		node* p = last;
		for (; p && !p->next.count(c); p = p->link)
			p->next[c] = curr;
		if (!p) {
			curr->link = root;
		} else {
			node* q = p->next[c];
			if (p->len + 1 == q->len) {
				curr->link = q;
			} else {
				node* clone = new node(*q);
				clone->len = p->len + 1;
				clone->sz = 0;
				v.push_back(clone);
				for (; p && p->next[c] == q; p = p->link)
					p->next[c] = clone;
				q->link = curr->link = clone;
			}
		}
		last = curr;
	}

	sort(v.begin(), v.end(), [&](node* a, node* b) {
		return a->len < b->len;
	});
	
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		auto v = automat(s);
		ll z = 0;
		for (int i=v.size()-1; i>0; i--) {
			v[i]->link->sz += v[i]->sz;
		}
		v[0]->dp = 1;
		for (auto vi : v) {
			for (auto [c, q] : vi->next) {
				q->dp += vi->dp;
			}
			if (vi->len)
				z += vi->dp * vi->sz * vi->sz;
		}
		cout << z << '\n';
	}
}