#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, z;
int a[22][22], b[22][22];
int c[22][22];

void madjar(int i, int tip, int ca, int cb, vector<int> u,
	vector<int> v, vector<int> p, vector<int> way)
{
	if (tip == 0) {
		copy(a[i], a[i]+n+1, c[i]);
	} else {
		copy(b[i], b[i]+n+1, c[i]);
	}

	{
		// stolen from
		// https://e-maxx.ru/algo/assignment_hungary
		p[0] = i;
			int j0 = 0;
			vector<int> minv (n+1, 123123123);
			vector<char> used (n+1, false);
			do {
				used[j0] = true;
				int i0 = p[j0],  delta = 123123123,  j1;
				for (int j=1; j<=n; ++j)
					if (!used[j]) {
						int cur = c[i0][j]-u[i0]-v[j];
						if (cur < minv[j])
							minv[j] = cur,  way[j] = j0;
						if (minv[j] < delta)
							delta = minv[j],  j1 = j;
					}
				for (int j=0; j<=n; ++j)
					if (used[j])
						u[p[j]] += delta,  v[j] -= delta;
					else
						minv[j] -= delta;
				j0 = j1;
			} while (p[j0] != 0);
			do {
				int j1 = way[j0];
				p[j0] = p[j1];
				j0 = j1;
			} while (j0);
	}

	if (i == n) {
		// cerr << -v[0] << ' ' << ca << ' ' << cb << '\n';
		z = min(z, -v[0]);
		return;
	}

	if (ca < n / 2) {
		madjar(i+1, 0, ca+1, cb, u, v, p, way);
	}

	if (cb < n / 2) {
		madjar(i+1, 1, ca, cb+1, u, v, p, way);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> a[i][j];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			cin >> b[i][j];
			a[i][j] *= -1;
			b[i][j] *= -1;
		}

	vector<int> nule(n+1);
	madjar(1, 0, 1, 0, nule, nule, nule, nule);
	madjar(1, 1, 0, 1, nule, nule, nule, nule);
	cout << -z << '\n';
}