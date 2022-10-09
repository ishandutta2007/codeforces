#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	vector<node*> ch;
	char tip;
	int id;
	ll f_val;
};

int global_id;
string::iterator it;

node* parse() {
	if (*it == '*') {
		++it;
		return new node { {}, 'R', global_id++ };
 	} else if (*it == '(') {
 		++it;
 		vector<node*> ch;
 		char tip = 0;
 		while (1) {
 			ch.emplace_back(parse());
 			if (*it == 'S') {
 				++it;
 				tip = 'S';
 			} else if (*it == 'P') {
 				++it;
 				tip = 'P';
 			} else if (*it == ')') {
 				++it;
 				break;
 			}
 		}
 		return new node { ch, tip, -1 };
 	} else {
 		return nullptr;
 	}
}

vector<ll> v;

void dfs1(node* root) {
	if (root->tip == 'R') {
		root->f_val = 1;
	} else if (root->tip == 'S') {
		root->f_val = 2e18;
		for (auto u : root->ch) {
			dfs1(u);
			root->f_val = min(root->f_val, u->f_val);
		}
	} else {
		root->f_val = 0;
		for (auto u : root->ch) {
			dfs1(u);
			root->f_val += u->f_val;
		}
	}
}

void dfs2(node* root, ll xd) {
	if (root->tip == 'R') {
		v[root->id] = xd;
	} else if (root->tip == 'S') {
		// uzmi najmanji i idi u njega samo
		node* v = nullptr;
		ll val = 2e18;
		for (auto u : root->ch) {
			if (u->f_val < val) {
				val = u->f_val;
				v = u;
			}
		}
		dfs2(v, xd);
	} else {
		for (auto u : root->ch)
			dfs2(u, xd);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		global_id = 0;

		int x;
		cin >> x;
		string s;
		getline(cin, s);
		string t;
		for (char x : s)
			if (x != ' ')
				t += x;

		it = t.begin();
		auto root = parse();
		v.assign(global_id, 0);
		dfs1(root);
		dfs2(root, root->f_val * 1ll * x);


		cout << "REVOLTING";
		for (ll x : v)
			cout << ' ' << x;
		cout << '\n';
	}
}