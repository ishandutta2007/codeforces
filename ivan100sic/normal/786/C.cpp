#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

struct kontejner {
	set<pair<int, int>> a;
	int delta;

	void insert(int k, int val) {
		a.insert({val - delta, k});
	}

	int val() {
		if (a.empty()) {
			return 1'000'000'000;
		}
		return a.begin()->first + delta;
	}

	int pop() {
		int r = a.begin()->second;
		a.erase(a.begin());
		return r;
	}
};

const int MAXN = 131072;

kontejner a[MAXN];

int lazy[2*MAXN];
int mval[2*MAXN];

void push(int x) {
	if (!lazy[x]) return;
	mval[x] += lazy[x];
	if (x < MAXN) {
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
	} else {
		a[x - MAXN + 1].delta += lazy[x];
	}

	lazy[x] = 0;
}

void insert(int pos, int val, int k, int node=1, int nl=1, int nr=MAXN) {
	push(node);

	if (pos < nl || pos > nr) {
		return;
	}

	if (nl == nr && nl == pos) {
		a[pos].insert(k, val);
		mval[node] = a[pos].val();
		return;
	}

	int nm = (nl + nr) >> 1;

	insert(pos, val, k, 2*node, nl, nm);
	insert(pos, val, k, 2*node+1, nm+1, nr);

	mval[node] = min(mval[2*node], mval[2*node+1]);
}

void add(int l, int r, int amt, int node=1, int nl=1, int nr=MAXN) {
	push(node);

	if (r < nl || nr < l) {
		return;
	}

	if (l <= nl && nr <= r) {
		lazy[node] += amt;
		push(node);
		return;
	}

	int nm = (nl + nr) >> 1;

	add(l, r, amt, 2*node, nl, nm);
	add(l, r, amt, 2*node+1, nm+1, nr);

	mval[node] = min(mval[2*node], mval[2*node+1]);
}

void erase_all(vector<int>& a, int node=1, int nl=1, int nr=MAXN) {
	push(node);

	if (mval[node] > -1) {
		return;
	}

	if (nl == nr) {
		while (::a[nl].val() == -1) {
			a.push_back(::a[nl].pop());
		}
		mval[node] = ::a[nl].val();
		return;
	}

	int nm = (nl + nr) >> 1;

	erase_all(a, 2*node, nl, nm);
	erase_all(a, 2*node+1, nm+1, nr);

	mval[node] = min(mval[2*node], mval[2*node+1]);
}

int b[MAXN];
int last[MAXN];
int sol[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}

	for (int i=1; i<=MAXN; i++) {
		mval[i+MAXN-1] = a[i].val();
	}

	for (int i=MAXN-1; i>=1; i--) {
		mval[i] = min(mval[2*i], mval[2*i+1]);
	}

	for (int k=1; k<=n; k++) {
		insert(1, k-1, k);
		sol[k]++;
	}

	for (int i=1; i<=n; i++) {
		// decrementuj sve sto je strogo vece od last[b[i]]
		add(last[b[i]]+1, i-1, -1);

		vector<int> ispali;
		erase_all(ispali);

		for (int k : ispali) {
			insert(i, k-1, k);
			sol[k]++;
		}

		last[b[i]] = i;
	}

	for (int i=1; i<=n; i++) {
		cout << sol[i] << ' ';
	}
	cout << '\n';
}