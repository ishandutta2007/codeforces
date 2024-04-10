#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

#define forn(i) for (int (i) = 0; (i) <= n; ++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int kmax = 55;
const int nmax = 36000;
const int inf = 1e9;

struct node {
	int maxx;
	int promise;
	node() : maxx(-inf), promise(0) {}
};

node t[kmax][4 * nmax];

void push(int id, int v) {
	int val = t[id][v].promise;
	t[id][v].promise = 0;
	t[id][v * 2].maxx += val;
	t[id][v * 2].promise += val;
	t[id][v * 2 + 1].maxx += val;
	t[id][v * 2 + 1].promise += val;
}

int get(int id, int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[id][v].maxx;
	}
	push(id, v);
	int tm = (tl + tr) >> 1;
	int ans = -inf;
	if (l <= tm) {
		ans = max(ans, get(id, v * 2, tl, tm, l, min(r, tm)));
	}
	if (r > tm) {
		ans = max(ans, get(id, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
	return ans;
}

void update(int id, int v, int tl, int tr, int l, int r, int val) {
	if (tl == l && tr == r) {
		t[id][v].promise += val;
		t[id][v].maxx += val;
		return;
	}
	push(id, v);
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		update(id, v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		update(id, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	t[id][v].maxx = max(t[id][v * 2].maxx, t[id][v * 2 + 1].maxx);
}

int lst[nmax];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n, k;
	cin >> n >> k;

	memset(lst, 0, sizeof(lst));

	update(0, 1, 0, n, 0, 0, inf);

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		int pr = lst[x];
		for (int j = 0; j < k; ++j) {
			update(j, 1, 0, n, pr, i - 1, 1);
		}
		for (int j = 1; j <= k && j <= i; ++j) {
			int g = get(j - 1, 1, 0, n, 0, i - 1);
			//cout << "dp[" << i << "][" << j << "] = " << g << "\n";
			update(j, 1, 0, n, i, i, inf + g);
		}
		lst[x] = i;
	}

	cout << get(k, 1, 0, n, n, n) << "\n";

}