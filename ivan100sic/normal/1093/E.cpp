#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> drvo;

drvo d[200005];

void dodaj(int x, int y) {
	for (int i=x; i<200005; i+=i&-i)
		d[i].insert(y);
}

void brisi(int x, int y) {
	for (int i=x; i<200005; i+=i&-i)
		d[i].erase(y);
}

int broji(int x, int yl, int yr) {
	int z = 0;
	for (int i=x; i>0; i-=i&-i)
		z += d[i].order_of_key(yr+1) - d[i].order_of_key(yl);
	return z;
}

int broji(int xl, int xr, int yl, int yr) {
	return broji(xr, yl, yr) - broji(xl-1, yl, yr);
}

int n, q;
int a[200005], ainv[200005];
int b[200005], binv[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		ainv[a[i]] = i;
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
		binv[b[i]] = i;
	}

	for (int i=1; i<=n; i++)
		dodaj(ainv[i], binv[i]);

	while (q--) {
		int t;
		cin >> t;
		if (t == 2) {
			int x, y;
			cin >> x >> y;
			int p = b[x];
			int q = b[y];
			brisi(ainv[p], binv[p]);
			brisi(ainv[q], binv[q]);
			b[x] = q;
			b[y] = p;
			binv[q] = x;
			binv[p] = y;
			dodaj(ainv[p], binv[p]);
			dodaj(ainv[q], binv[q]);
		} else {
			int lx, rx, ly, ry;
			cin >> lx >> rx >> ly >> ry;
			cout << broji(lx, rx, ly, ry) << '\n';
		}
	}
}