#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string op[100005];
int a[100005];
int u[100005], k;

struct node {
	ll z[5];
	int cnt;

	node(int x=0, int c=0) { 
		fill(z, z+5, 0);
		cnt = 0;
		if (c) {
			cnt = 1;
			z[0] = x;
		}
	}

	node operator+ (node b) const {
		node tmp;
		// mozda je kontra?
		rotate(b.z, b.z+(5-cnt), b.z+5);
		for (int i=0; i<5; i++)
			tmp.z[i] = z[i] + b.z[i];
		tmp.cnt = (cnt + b.cnt) % 5;
		return tmp;
	}
};

const int MAXN = 131072;
node b[2*MAXN];

void update(int x, int y, int c) {
	x += MAXN;
	b[x] = node(y, c);
	while (x > 1) {
		x >>= 1;
		b[x] = b[2*x] + b[2*x+1];
	}
}

/*
node query(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l)
		return node(0, 0);
	if (l <= xl && xr <= r)
		return b[x];
	int xm = (xl+xr) >> 1;
	return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
}
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> op[i];
		if (op[i] != "sum")
			cin >> a[i];
		u[i] = a[i];
	}
	sort(u+1, u+n+1);
	k = unique(u+1, u+n+1) - (u+1);

	for (int i=1; i<=n; i++) {
		if (op[i] == "sum") {
			cout << b[1].z[2] << '\n';
		} else if (op[i] == "add") {
			int p = lower_bound(u, u+k, a[i]) - u;
			update(p, a[i], 1);
		} else {
			int p = lower_bound(u, u+k, a[i]) - u;
			update(p, 0, 0);
		}
	}

}