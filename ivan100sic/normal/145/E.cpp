#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s;

struct node {
	int a44, a77, a47, a74;

	node() {
		a44 = a47 = a77 = a74 = 0;
	}

	node(char c) {
		a44 = a47 = a77 = a74 = 1;
		if (c == '4')
			a77 = 0;
		else
			a44 = 0;
	}

	node operator+ (const node& b) const {
		node t;
		t.a44 = a44 + b.a44;
		t.a47 = max(a47 + b.a77, a44 + b.a47);
		t.a74 = max(a74 + b.a44, a77 + b.a74);
		t.a77 = a77 + b.a77;
		return t;
	}

	void flip() {
		swap(a44, a77);
		swap(a47, a74);
	}
};

const int maxn = 1 << 20;
node b[2*maxn];
int lz[2*maxn];

void push(int x) {
	if (!lz[x]) return;
	if (x < maxn) {
		lz[2*x] ^= 1;
		lz[2*x+1] ^= 1;
	}
	b[x].flip();
	lz[x] = 0;
}

void pull(int x) {
	b[x] = b[2*x] + b[2*x+1];
}

void update(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		lz[x] ^= 1;
		push(x);
		return;
	}
	push(x);
	int xm = (xl+xr) >> 1;
	update(l, r, 2*x, xl, xm);
	update(l, r, 2*x+1, xm+1, xr);
	pull(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s;
	for (int i=1; i<=n; i++)
		b[i + maxn] = s[i-1];
	for (int i=maxn-1; i; i--)
		pull(i);
	while (m--) {
		string s;
		cin >> s;
		if (s[0] == 'c')
			cout << b[1].a47 << '\n';
		else {
			int l, r;
			cin >> l >> r;
			update(l, r);
		}
	}

}