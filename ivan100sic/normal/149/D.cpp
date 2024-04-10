#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int M = 1'000'000'007;

void ad(int& x, int y) {
	x += y;
	if (x >= M)
		x -= M;
}

struct stanje {
	int a[3][3];
	int* operator[] (int x) {
		return a[x];
	}
	stanje() {
		memset(a, 0, sizeof(a));
	}
	stanje operator* (stanje b) {
		stanje tmp;
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				for (int k=0; k<3; k++) {
					if (k > 0 && j > 0 && k == j)
						continue;
					for (int l=0; l<3; l++) {
						ad(tmp[i][l], 1ll * a[i][j] * b[k][l] % M);
					}
				}
			}
		}
		return tmp;
	}
};

struct node {
	basic_string<int> children;
} b[7777]; int sz;
basic_string<int> st;
stanje dp[7777];

stanje zagradi(stanje a) {
	stanje c;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			for (int k=0; k<3; k++) {
				for (int l=0; l<3; l++) {
					if ((i > 0) == (l > 0))
						continue;
					if (i == j && j > 0)
						continue;
					if (k == l && l > 0)
						continue;
					ad(c[i][l], a[j][k]);
				}
			}
		}
	}
	return c;
}

void dfs(int x) {
	for (int y : b[x].children)
		dfs(y);
	if (b[x].children.size() == 0) {
		stanje& st = dp[x];
		st[0][1] = st[0][2] = st[1][0] = st[2][0] = 1;
		return;
	}
	stanje z = dp[b[x].children[0]];
	for (int i=1; i<(int)b[x].children.size(); i++) {
		int y = b[x].children[i];
		z = z * dp[y];
	}
	if (x > 1)
		z = zagradi(z);
	dp[x] = z;
}

int zbir(stanje st) {
	int z = 0;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			ad(z, st[i][j]);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int root = ++sz;
	int curr = root;
	st = {root};
	for (char x : s) {
		if (x == '(') {
			int t = ++sz;
			b[curr].children += t;
			st += t;
			curr = t;
		} else {
			st.pop_back();
			curr = st.back();
		}
	}
	dfs(root);
	cout << zbir(dp[root]) << '\n';
}