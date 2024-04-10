// Retired?
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, q;
int a[50005], lh[50005];
basic_string<int> e[50005];
int dl[50005], dr[50005], dt, da[50005];
int dub[50005], ddub[50005];

void dfs(int x) {
	dl[x] = dt++;
	for (int y : e[x]) {
		dub[y] = dub[x] + 1;
		dfs(y);
	}
	dr[x] = dt;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		e[p] += i;
	}

	dfs(1);
	for (int i=1; i<=n; i++) {
		da[dl[i]] = a[i];
		ddub[dl[i]] = dub[i];
		lh[i-1] = -1000000;
	}

	for (int i=1; i<=q; i++) {
		int x, h=0, ud=0;
		cin >> x;
		for (int j=dl[x]; j<dr[x]; j++) {
			// no branching
			int branch = i - lh[j] >= da[j];
			h += branch;
			ud += ddub[j] * branch;
			lh[j] += branch * (i - lh[j]);
		}
		cout << ud - h*dub[x] << ' ' << h << '\n';
	}
}