#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

struct pokemon {
	double p, q, r;
} a[2005]; int n, x, y;

int xlo[2005], xhi[2005], ylo[2005], yhi[2005];
const int W = 32;

inline void mx(double& x, double y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x >> y;
	for (int i=0; i<n; i++)
		cin >> a[i].p;
	for (int i=0; i<n; i++) {
		cin >> a[i].q;
		a[i].r = a[i].p + a[i].q - a[i].p * a[i].q;
	}

	shuffle(a, a+n, eng);

	xlo[0] = ylo[0] = 0;
	xhi[0] = yhi[0] = 1;
	for (int i=1; i<=n; i++) {
		xlo[i] = max(0  , i*x/n - W);
		xhi[i] = min(x+1, i*x/n + W);

		ylo[i] = max(0  , i*y/n - W);
		yhi[i] = min(y+1, i*y/n + W);
	}

	vector<vector<double>> ol = {{0.0}};
	for (int i=0; i<n; i++) {
		vector<vector<double>> nu(xhi[i+1] - xlo[i+1],
			vector<double>(yhi[i+1] - ylo[i+1], 0.0));

		auto pisi = [&](double z, int u, int v) {
			if (u < xlo[i+1] || u >= xhi[i+1])
				return;
			if (v < ylo[i+1] || v >= yhi[i+1])
				return;
			mx(nu[u - xlo[i+1]][v - ylo[i+1]], z);
		};

		for (int j=xlo[i]; j<xhi[i]; j++) {
			for (int k=ylo[i]; k<yhi[i]; k++) {
				pisi(ol[j-xlo[i]][k-ylo[i]], j, k);
				pisi(ol[j-xlo[i]][k-ylo[i]] + a[i].p, j+1, k);
				pisi(ol[j-xlo[i]][k-ylo[i]] + a[i].q, j, k+1);
				pisi(ol[j-xlo[i]][k-ylo[i]] + a[i].r, j+1, k+1);
			}
		}

		swap(nu, ol);
	}

	cout << setprecision(20) << fixed << ol[x - xlo[n]][y - ylo[n]] << '\n';
}