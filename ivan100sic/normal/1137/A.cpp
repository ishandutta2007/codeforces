#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, a[1005][1005];
ordered_set rs[1005], cs[1005];

int manje(ordered_set& t, int x) {
	return t.order_of_key(x);
}

int vece(ordered_set& t, int x) {
	return t.size() - t.order_of_key(x) - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
			rs[i].insert(a[i][j]);
			cs[j].insert(a[i][j]);
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int vr = vece(rs[i], a[i][j]);
			int mr = manje(rs[i], a[i][j]);
			int vc = vece(cs[j], a[i][j]);
			int mc = manje(cs[j], a[i][j]);
			cout << 1 + max(vc, vr) + max(mc, mr) << " \n"[j == m-1];
		}
	}
}