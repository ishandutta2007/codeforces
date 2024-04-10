#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
unordered_set<int> e[100005];
int w[100005], winv[200005];
int p[100005], q[100005];
ll sol;

void adjust(int y, int ol) {
	if (ol > w[y])
		return;
	sol += p[y] - q[y] - 1;
	p[y]--;
	q[y]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].insert(y);
		e[y].insert(x);
	}

	for (int i=1; i<=n; i++) {
		w[i] = winv[i] = i;
		for (int j : e[i])
			(j < i ? p : q)[i]++;
		sol += p[i] * 1ll * q[i];
	}

	int upit;
	cin >> upit;
	for (int i=0; i<upit; i++) {
		cout << sol << '\n';
		int x;
		cin >> x;

		int ol = w[x], nu = n + i + 1;

		if (nu - ol - 1 < (int)e[x].size()) {
			for (int j=ol+1; j<nu; j++) {
				int y = winv[j];
				if (y == 0)
					continue;
				if (e[x].count(y))
					adjust(y, ol);
			}
		} else {
			for (int y : e[x])
				adjust(y, ol);
		}

		sol -= p[x] * 1ll * q[x];
		p[x] = e[x].size();
		q[x] = 0;

		winv[ol] = 0;
		winv[nu] = x;
		w[x] = nu;
	}

	cout << sol << '\n';
}