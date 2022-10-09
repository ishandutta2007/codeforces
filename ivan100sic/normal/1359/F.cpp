// Retired?
#include <bits/stdc++.h>
using namespace std;

int n;
double x[25005], y[25005], dx[25005], dy[25005];

struct dir {
	int x, y;

	dir(int x, int y) : x(x), y(y) {
		if (y < 0)
			x = -x, y = -y;
	}

	bool operator< (const dir& b) const {
		return x*b.y < y*b.x;
	}
};

struct car {
	int x, y, dx, dy;
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		double s;
		cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s;
		double sc = sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
		s /= sc;
		dx[i] *= s;
		dy[i] *= s;
	}

	double sol = 1e18;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			double u = dx[j]*dy[i] - dx[i]*dy[j];
			double o = dy[j] * (x[i] - x[j]) - dx[j]*(y[i] - y[j]);

			if (abs(u) > 1e-9) {
				double ti = o / u;
				double tj = (dx[i] * ti + x[i] - x[j]) / dx[j];
				if (ti >= 0 && tj >= 0) {
					sol = min(sol, max(ti, tj));
				}
			} else if (abs(o) < 1e-9) {
				double t = 1e18;
				if ((dx[i] < 0) == (dx[j] < 0)) {
					if (dx[i] > 0) {
						t = abs(x[i] - x[j]) / (x[i] < x[j] ? dx[i] : dx[j]);
					} else {
						t = - abs(x[i] - x[j]) / (x[i] < x[j] ? dx[j] : dx[i]);
					}
				} else if ((dx[i] > 0) == (x[i] < x[j])) {
					t = abs(x[i] - x[j]) / (abs(dx[i]) + abs(dx[j]));
				}
				sol = min(sol, t);
			}
		}
	}

	if (sol > 1e17) {
		cout << "No show :(\n";
	} else {
		cout << setprecision(20) << fixed << sol << '\n';
	}
}