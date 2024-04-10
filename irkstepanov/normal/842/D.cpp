#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct node {
	int left;
	int right;
	int size;
	node() : left(-1), right(-1), size(0) {}
};

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

vector<node> t;
const int rmax = 20;

void add(int val) {
	int curr = 0;
	for (int r = rmax - 1; r >= 0; --r) {
		if (bit(val, r)) {
			if (t[curr].right == -1) {
				t[curr].right = sz(t);
				t.pb(node());
			}
			curr = t[curr].right;
		} else {
			if (t[curr].left == -1) {
				t[curr].left = sz(t);
				t.pb(node());
			}
			curr = t[curr].left;
		}
	}
}

void dfs(int v, int h) {
	//cout << "!" << v << " " << h << "\n";
	if (h == 0) {
		t[v].size = 1;
	}
	if (t[v].left != -1) {
		dfs(t[v].left, h - 1);
		t[v].size += t[t[v].left].size;
	}
	if (t[v].right != -1) {
		dfs(t[v].right, h - 1);
		t[v].size += t[t[v].right].size;
	}
}

int mask = 0;

void change(int x) {
	mask ^= x;
}

int getMin() {
	int curr = 0;
	int ans = 0;
	for (int r = rmax - 1; r >= 0; --r) {
		if (curr == -1) {
			return ans;
		}
		if (bit(mask, r)) {
			if (t[curr].right == -1) {
				return ans;
			}
			if (t[t[curr].right].size == (1 << r)) {
				ans |= (1 << r);
				curr = t[curr].left;
			} else {
				curr = t[curr].right;
			}
		} else {
			if (t[curr].left == -1) {
				return ans;
			}
			if (t[t[curr].left].size == (1 << r)) {
				ans |= (1 << r);
				curr = t[curr].right;
			} else {
				curr = t[curr].left;
			}
		}
	}
	return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n, q;
	cin >> n >> q;
	t.pb(node());

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		add(x);
	}

	dfs(0, rmax);

	while (q--) {
		int x;
		cin >> x;
		change(x);
		cout << getMin() << "\n";
	}

}