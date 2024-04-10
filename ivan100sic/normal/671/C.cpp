#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int l, h, lz, w;
	ll s;
};

const int maxn = 262144;
node b[2*maxn];

int n;
int a[200005], p[200005];
ll z[200005];

void pull(int x) {
	b[x].l = min(b[2*x].l, b[2*x+1].l);
	b[x].h = max(b[2*x].h, b[2*x+1].h);
	b[x].s = b[2*x].s + b[2*x+1].s;
	b[x].lz = 0;
}

void push(int x) {
	if (b[x].lz <= b[x].l)
		return;
	if (b[x].lz >= b[x].h) {
		b[x].h = b[x].l = b[x].lz;
		b[x].s = b[x].w * 1ll * b[x].lz;
		if (x < maxn) {
			b[2*x].lz = max(b[2*x].lz, b[x].lz);
			b[2*x+1].lz = max(b[2*x+1].lz, b[x].lz);
		}
		b[x].lz = 0;
	} else {
		b[2*x].lz = max(b[2*x].lz, b[x].lz);
		b[2*x+1].lz = max(b[2*x+1].lz, b[x].lz);
		push(2*x);
		push(2*x+1);
		pull(x);
	}
}

void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l) {
		push(x);
		return;
	}
	if (l <= xl && xr <= r) {
		b[x].lz = max(b[x].lz, v);
		push(x);
		return;
	}

	push(x);
	int xm = (xl+xr) >> 1;
	update(l, r, v, 2*x, xl, xm);
	update(l, r, v, 2*x+1, xm+1, xr);
	pull(x);
}

void add(int x, int y) {
	update(x, y, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<maxn; i++)
		b[i+maxn].w = 1;
	for (int i=maxn-1; i>0; i--)
		b[i].w = b[2*i].w * 2;

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}

	for (int i=1; i<=n; i++)
		update(i, i, i-1);

	ll sol = 0, last = b[1].s;
	for (int i=200000; i>=1; i--) {
		vector<int> v;
		for (int j=i; j<=200000; j+=i) {
			if (p[j]) {
				v.push_back(p[j]);
			}
		}
		if (v.size() >= 2) {
			sort(v.begin(), v.end());
			add(v[1]+1, n);
			add(1, v[v.size()-2]-1);
			add(v[0]+1, v.back()-1);
		}
		sol += (b[1].s - last) * i;
		last = b[1].s;
	}

	cout << sol << '\n';
}