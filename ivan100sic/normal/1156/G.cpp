#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

struct node {
	node* left;
	node* right;
	unsigned h;
	char op;
};

map<string, node*> val;
map<unsigned, node*> unhasher;
map<unsigned, string> unval;

node* get_val(string var) {
	auto it = val.find(var);
	if (it == val.end()) {
		node* t = new node;
		t->left = t->right = nullptr;
		t->h = uniform_int_distribution<unsigned>(0, -1)(eng);
		t->op = 0;
		unval[t->h] = var;
		unhasher[t->h] = t;
		return val[var] = t;
	} else {
		return it->second;
	}
}

int used_var_names = 0;

string new_var_name() {
	int x = used_var_names++;
	return string("x") + to_string(x);
}

map<unsigned, string> var_allocator;
vector<string> sol;

void dfs(node* v, bool isRoot = false) {
	// cerr << "dfs info\n";
	// cerr << v << '\n';
	// if (v) {
	// 	cerr << v->left << '\n';
	// 	cerr << v->right << '\n';
	// 	cerr << v->h << '\n';
	// 	cerr << v->op << '\n';
	// 	cerr << "~~~~~~~~\n";
	// } else {
	// 	cerr << "~~~~\n";
	// }

	if (!v)
		return;
	if (var_allocator.count(v->h)) {
		// nothing to do
		return;
	}

	if (v->op == 0) {
		if (isRoot) {
			if (unval[v->h] != "res")
				sol.push_back("res=" + unval[v->h]);
		}
		var_allocator[v->h] = unval[v->h];
		return;
	}

	dfs(v->left);
	dfs(v->right);

	string lhs;
	if (isRoot) {
		lhs = "res";
	} else {
		lhs = new_var_name();
	}

	var_allocator[v->h] = lhs;

	sol.push_back(lhs + '=' + var_allocator[v->left->h]
		+ v->op + var_allocator[v->right->h]);
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
		int eq = s.find('=');
		string lhs = s.substr(0, eq);
		string rhs = s.substr(eq+1);

		string op1, op2;
		char op = 0;
		for (int i=0; i<(int)rhs.size(); i++) {
			if (!isalnum(rhs[i])) {
				op = rhs[i];
				op1 = rhs.substr(0, i);
				op2 = rhs.substr(i+1);
				break;
			}
		}

		if (op == 0) {
			if (lhs == rhs)
				continue;
			val[lhs] = get_val(rhs);
		} else {
			auto v1 = get_val(op1);
			auto v2 = get_val(op2);
			auto nn = new node;
			nn->left = v1;
			nn->right = v2;
			nn->h = hash<string>()(string("I'm a SaLtY!") +
				to_string(v1->h) + op + to_string(v2->h) + "~boY!!!");
			nn->op = op;
			unhasher[nn->h] = nn;
			val[lhs] = nn;
		}
	}

	if (val.count("res")) {
		dfs(val["res"], true);
		cout << sol.size() << '\n';
		for (string s : sol)
			cout << s << '\n';
	} else {
		cout << "0\n";
	}
}