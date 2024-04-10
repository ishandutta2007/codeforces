#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
	broj parova i < j tako da je:
		a[i] >= j && a[j] >= i

	neka je j fiksno
	a[i] >= j (sve brojeve na pozicijama i E I koji su >= j)
	i <= a[j], tacnije i <= min(a[j], j-1)
*/

int n;
int a[200005];
int f[200005];
basic_string<int> e[200005];

void add(int x, int v) {
	for (int y = x; y < 200005; y += y&-y)
		f[y] += v;
}

int get(int x) {
	int v = 0;
	for (int y = x; y; y -= y&-y)
		v += f[y];
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] < 200005)
			e[a[i]] += i;
		add(i, 1);
	}

	ll sol = 0;

	for (int i=1; i<=n; i++) {
		for (int x : e[i-1])
			add(x, -1);
		sol += get(min(a[i], i-1));
	}

	cout << sol << '\n';
}