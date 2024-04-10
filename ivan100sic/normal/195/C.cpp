// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct ast {
	int tip;
};

struct trycatch : ast {
	vector<ast*> ch;
	string t, msg;
};

struct throwst : ast {
	string t;
};

ast* parse(string& s, size_t& p) {
	while (p < s.size() && s[p] == ' ') p++;
	if (p == s.size() || s[p] == 'c') {
		return nullptr;
	}

	if (s[p+1] == 'r') {
		// try
		p += 3;
		trycatch* z = new trycatch;
		z->tip = 0;
		while (1) {
			ast* y = parse(s, p);
			if (y) {
				z->ch.emplace_back(y);
			} else {
				break;
			}
		}

		// sada catch
		while (s[p] != '(') p++;
		p++;
		while (s[p] == ' ') p++;
		while (isalpha(s[p])) {
			z->t += s[p++];
		}
		while (s[p] != ',') p++;
		while (s[p] != '"') p++;
		p++;
		while (s[p] != '"') {
			z->msg += s[p++];
		}
		while (s[p] != ')') p++;
		p++;
		return z;
	} else {
		throwst* z = new throwst;
		z->tip = 1;
		while (s[p] != '(') p++;
		p++;
		while (s[p] == ' ') p++;
		while (isalpha(s[p])) {
			z->t += s[p++];
		}
		while (s[p] != ')') p++;
		p++;
		return z;
	}
}

string dfs(ast* r) {
	if (r->tip == 0) {
		auto q = static_cast<trycatch*>(r);
		for (auto c : q->ch) {
			auto th = dfs(c);
			if (th.size()) {
				if (th == q->t) {
					cout << q->msg << '\n';
					exit(0);
				} else {
					return th;
				}
			}
		}
	} else {
		auto q = static_cast<throwst*>(r);
		return q->t;
	}

	return {};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	string s;
	getline(cin, s);
	string prog;
	for (int i=0; i<n; i++) {
		getline(cin, s);
		prog += s;
	}

	size_t pos = 0;
	while (1) {
		ast* p = parse(prog, pos);
		if (!p) break;
		dfs(p);
	}

	cout << "Unhandled Exception\n";
}