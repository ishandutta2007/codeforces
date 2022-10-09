#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stvar {
	int pos;
	int a[26];
	int redosled;

	stvar() : pos(0), redosled(1) {
		fill(a, a+26, 0);
	}

	stvar(int x) : pos(x) {}

	bool operator< (const stvar& b) const {
		return pos < b.pos;
	}

	int len() {
		return accumulate(a, a+26, 0);
	}
};

void vsum(int* a, int* b, int* c) {
	for (int i=0; i<26; i++) {
		c[i] = a[i] + b[i];
	}
}

set<stvar> q;
int n, up;
string s;

void split(int x) {
	if (x == n+1)
		return;

	auto it = --q.upper_bound(x);
	if (it->pos == x)
		return;

	stvar left, right;
	int preko = x - it->pos;
	left.pos = it->pos;
	right.pos = it->pos + preko;
	for (int i=0; i<26; i++) {
		int j = it->redosled ? i : 25-i;
		int w = min(preko, it->a[j]);
		left.a[j] = w;
		preko -= w;
		right.a[j] = it->a[j] - w;
	}

	left.redosled = it->redosled;
	right.redosled = it->redosled;

	q.erase(it);
	q.insert(left);
	q.insert(right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> up >> s;
	s = string(" ") + s;
	for (int i=1; i<=n; i++) {
		stvar tmp;
		tmp.a[s[i] - 'a']++;
		tmp.pos = i;
		tmp.redosled = 1;
		q.insert(tmp);
	}

	while (up--) {
		int l, r, k;
		cin >> l >> r >> k;
		r++;
		split(l);
		split(r);
		while (1) {
			auto it = --q.upper_bound(l);
			if (next(it) == q.end() || next(it)->pos == r) {
				auto tmp = *it;
				tmp.redosled = k;
				q.erase(it);
				q.insert(tmp);
				break;
			}
			auto left = *it;
			auto right = *next(it);
			q.erase(left);
			q.erase(right);

			stvar sum;
			vsum(left.a, right.a, sum.a);
			sum.pos = left.pos;
			sum.redosled = k;
			q.insert(sum);
		}
	}

	for (auto w : q) {
		for (int i=0; i<26; i++) {
			int j = w.redosled ? i : 25-i;
			for (int z=0; z<w.a[j]; z++)
				cout << (char)(j + 'a');
		}
	}
	cout << '\n';
}