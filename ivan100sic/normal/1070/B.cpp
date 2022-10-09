#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct adresa {
	int tip;
	unsigned x;
	int len;
};

vector<int> split(string s) {
	for (char& x : s) {
		if (!isdigit(x))
			x = ' ';
	}

	istringstream iss(s);

	vector<int> v;
	int _x;
	while (iss >> _x) {
		v.push_back(_x);
	}

	return v;
}

adresa parse(string s) {
	adresa tmp;
	tmp.tip = s[0] == '+' ? 1 : -1;

	vector<int> v = split(s);
	if (v.size() == 4) {
		tmp.len = 32;
	} else {
		tmp.len = v.back();
	}

	tmp.x = 0;
	for (int i=0; i<4; i++) {
		tmp.x = (tmp.x << 8) + v[i];
	}

	return tmp;
}

struct node {
	int color, has_plus;
	node* next[2];
};

node pool[10'000'000];
int pool_cnt;

node* new_node() {
	return pool + (pool_cnt++);
}

void no() {
	cout << "-1\n";
	exit(0);
}

node* insert(node* root, adresa addr, int depth) {
	if (!root)
		root = new_node();

	if (addr.len > depth) {
		node*& nx = root->next[(addr.x >> (31 - depth)) & 1];
		nx = insert(nx, addr, depth+1);
	} else {
		if (root->color && root->color != addr.tip)
			no();
		root->color = addr.tip;
	}
	return root;
}

vector<adresa> sol;

void validate(node* root, int upcolor) {
	if (!root)
		return;

	if (upcolor && root->color && root->color != upcolor)
		no();

	if (root->color)
		upcolor = root->color;

	validate(root->next[0], upcolor);
	validate(root->next[1], upcolor);

	if (root->next[0])
		root->has_plus |= root->next[0]->has_plus;
	if (root->next[1])
		root->has_plus |= root->next[1]->has_plus;
	root->has_plus |= root->color == 1;
}

void collect(node* root, unsigned path, int depth) {
	if (!root)
		return;
	if (root->has_plus == 0) {
		sol.push_back({0, path, depth});
		return;
	}

	collect(root->next[0], path, depth + 1);
	collect(root->next[1], path | (1u << (31 - depth)), depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	node* root = nullptr;

	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		root = insert(root, parse(s), 0);
	}
	validate(root, 0);
	collect(root, 0, 0);
	cout << sol.size() << '\n';
	for (auto x : sol) {
		cout << ((x.x >> 24) & 0xffu) << '.';
		cout << ((x.x >> 16) & 0xffu) << '.';
		cout << ((x.x >> 8) & 0xffu) << '.';
		cout << ((x.x >> 0) & 0xffu) << '/';
		cout << x.len << '\n';
	}
}