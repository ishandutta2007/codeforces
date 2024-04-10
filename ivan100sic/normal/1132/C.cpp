#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int l[5005], r[5005];
int z[5005];
int z1[5005], z2[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<q; i++) {
		cin >> l[i] >> r[i];
		z[l[i]]++;
		z[r[i]+1]--;
	}
	int p = 0;
	for (int i=1; i<=n; i++) {
		z[i] += z[i-1];
		if (z[i])
			p++;
		z1[i] = z1[i-1];
		z2[i] = z2[i-1];
		if (z[i] == 1)
			z1[i]++;
		else if (z[i] == 2)
			z2[i]++;
	}
	int sol = 0;
	for (int i=0; i<q; i++) {
		for (int j=i+1; j<q; j++) {
			int a = l[i];
			int b = r[i];
			int u = l[j];
			int v = r[j];

			int w1 = (z1[b] - z1[a-1]) + (z1[v] - z1[u-1]);
			int w2 = 0;
			int c = max(a, u);
			int d = min(b, v);
			if (c <= d) {
				// ima presek
				w1 -= z1[d] - z1[c-1];
				w2 += z2[d] - z2[c-1];
			}
			sol = max(sol, p - w1 - w2);
		}
	}
	cout << sol << '\n';
}