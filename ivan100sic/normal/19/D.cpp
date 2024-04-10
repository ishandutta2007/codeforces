#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int BRANCH = 20;

struct myset : private multiset<int> {
	int najveci;

	myset() : multiset<int>(), najveci(-1) {}

	void dodaj(int x) {
		insert(x);
		najveci = max(najveci, x);
	}
	void brisi(int x) {
		erase(find(x));
		if (size())
			najveci = *rbegin();
		else
			najveci = -1;
	}

	template<class T>
	auto ub(T x) {
		return upper_bound(x);
	}
};

struct node {
	int next[BRANCH], b, l, r;
	myset y;

	int contains(int x) {
		return l <= x && x < r;
	}

	int w() {
		return r-l;
	}

} b[600005]; int sz;

int napravi(int l, int r) {
	int x = ++sz;
	b[x].l = l;
	b[x].r = r;
	if (r-l == 1) {
		b[x].b = 0;
	} else {
		int B = min(r-l, BRANCH);
		b[x].b = B;
		for (int i=0; i<B; i++) {
			int L = l + (r-l)*i / B;
			int R = l + (r-l)*(i+1) / B;
			b[x].next[i] = napravi(L, R);
		}
	}
	return x;
}

void dodaj(int root, int x, int y) {
	b[root].y.dodaj(y);
	for (int i=0; i<b[root].b; i++) {
		int child = b[root].next[i];
		if (b[child].contains(x)) {
			dodaj(child, x, y);
			return;
		}
	}
}

void brisi(int root, int x, int y) {
	b[root].y.brisi(y);
	for (int i=0; i<b[root].b; i++) {
		int child = b[root].next[i];
		if (b[child].contains(x)) {
			brisi(child, x, y);
			return;
		}
	}
}

int ux[200005], uy[200005], kx, ky;

bool trazi(int root, int x, int y) {

	if (b[root].y.najveci <= y || b[root].r <= x+1)
		return false;
	
	if (b[root].w() == 1) {
		if (b[root].y.najveci > y) {
			cout << ux[b[root].l] << ' ' << uy[*b[root].y.ub(y)] << '\n';
			return true;
		} else {
			return false;
		}
	}

	for (int i=0; i<b[root].b; i++) {
		int child = b[root].next[i];
		if (trazi(child, x, y))
			return true;
	}
	return false;
}

struct upit {
	string tip;
	int x, y;
} up[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	int root = napravi(0, n+2);
	for (int i=0; i<n; i++) {
		cin >> up[i].tip >> up[i].x >> up[i].y;
		ux[i] = up[i].x;
		uy[i] = up[i].y;
	}
	sort(ux, ux+n);
	sort(uy, uy+n);
	kx = unique(ux, ux+n) - ux;
	ky = unique(uy, uy+n) - uy;

	for (int i=0; i<n; i++) {
		int x = lower_bound(ux, ux+kx, up[i].x) - ux;
		int y = lower_bound(uy, uy+ky, up[i].y) - uy;

		if (up[i].tip == "add") {
			dodaj(root, x, y);
		} else if (up[i].tip == "remove") {
			brisi(root, x, y);
		} else {
			if (!trazi(root, x, y))
				cout << "-1\n";
		}
	}
}