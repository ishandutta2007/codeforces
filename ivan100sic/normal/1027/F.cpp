#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> uqv;
int n, mpc;
int u[1000005], v[1000005];
vector<int> e[2000005];
bool w[2000005];

int cvorova, grana, limiter;

void dfs(int x) {
	cvorova++;
	w[x] = 1;
	for (int y : e[x]) {
		if (y > x)
			grana++;
		if (y <= limiter) {
			if (!w[y])
				dfs(y);
		}
	}
}

int main() {
	scanf("%d", &n);
	uqv.reserve(2*n);
	for (int i=0; i<n; i++) {
		scanf("%d%d", u+i, v+i);
		uqv.push_back(u[i]);
		uqv.push_back(v[i]);
	}

	sort(uqv.begin(), uqv.end());
	int rs = unique(uqv.begin(), uqv.end()) - uqv.begin();
	uqv.resize(rs);

	for (int i=0; i<n; i++) {
		u[i] = lower_bound(uqv.begin(), uqv.end(), u[i]) - uqv.begin();
		v[i] = lower_bound(uqv.begin(), uqv.end(), v[i]) - uqv.begin();
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}

	int l = n-1, r = rs-1, o = -1;
	while (l <= r) {
		int m = (l+r) / 2;
		limiter = m;
		fill(w, w+rs, false);
		int mecovano = 0;

		for (int i=0; i<=limiter; i++)
			if (!w[i]) {
				cvorova = grana = 0;
				dfs(i);
				if (cvorova - 1 == grana) {
					mecovano += cvorova - 1;
				} else {
					mecovano += cvorova;
				}
			}

		// cerr << m << ' ' << mecovano << '\n';

		if (mecovano == n) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}

	if (o == -1)
		return cout << -1, 0;

	cout << uqv[o] << '\n';
}