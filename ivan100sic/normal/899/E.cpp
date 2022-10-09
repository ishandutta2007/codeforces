#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

struct segment {
	int idx, val, len;

	bool operator< (const segment& b) const {
		if (len != b.len)
			return len > b.len;
		return idx < b.idx;
	}
};

bool cmp_seq(segment a, segment b) {
	return a.idx < b.idx;
}

template<class T>
void print_set(T s) {
	for (auto p : s)
		cerr << p.idx << ' ' << p.val << ' ' << p.len << '\n';
	cerr << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	basic_string<segment> b;

	b.push_back({0, a[0], 1});
	for (int i=1; i<n; i++) {
		if (a[i] == a[i-1]) {
			b.back().len++;
		} else {
			b.push_back({i, a[i], 1});
		}
	}

	set<segment> ord;
	set<segment, decltype(&cmp_seq)> niz(cmp_seq);

	for (auto seg : b) {
		niz.insert(seg);
		ord.insert(seg);
	}

	// print_set(niz);
	// print_set(ord);

	int steps = 0;
	while (ord.size()) {
		auto seg = *ord.begin();
		ord.erase(seg);
		steps++;
		auto it = niz.find(seg);
		it = niz.erase(it);
		if (it != niz.end() && it != niz.begin()) {
			if (prev(it)->val == it->val) {
				segment tmp = {prev(it)->idx, it->val, prev(it)->len + it->len};
				ord.erase(*it);
				ord.erase(*prev(it));
				niz.erase(prev(it));
				niz.erase(it);
				ord.insert(tmp);
				niz.insert(tmp);
			}
		}

		// print_set(niz);
		// print_set(ord);
	}

	cout << steps << '\n';
}