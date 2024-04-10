#include <bits/stdc++.h>
using namespace std;

int n, w, used;
int a[105], b[105];

int a_order[105];

bool cmp(int x, int y) {
	return a[x] > a[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a_order[i] = i;
	}

	sort(a_order+1, a_order+n+1, cmp);

	for (int i=1; i<=n; i++) {
		b[i] = (a[i]+1) / 2;
		used += b[i];
	}

	if (used > w) {
		cout << -1;
		return 0;
	}

	for (int i=1; i<=n; i++) {
		int x = a_order[i];
		int m = min(w - used, a[x] - b[x]);
		used += m;
		b[x] += m;
	}

	for (int i=1; i<=n; i++) {
		cout << b[i] << ' ';
	}


}