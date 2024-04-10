#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

typedef long long ll;

int n;
ll a[1005];
bool used[1005];

ll det(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
	return ax*by + bx*cy + cx*ay - ay*bx - by*cx - cy*ax;
}

long long ux, uy, vx, vy;

void probaj_ostalo() {
	int p = 0, q = 0;

	for (int i=1; i<=n; i++) {
		if (!used[i]) {
			q = i;
			if (p == 0) {
				p = i;
			}
		}
	}

	cerr << "Ostali su: " << p << ' ' << q << '\n';

	if (!q) {
		return;
	}

	for (int i=1; i<=n; i++) {
		if (!used[i] && det(i, a[i], p, a[p], q, a[q]) != 0) {
			return;
		}
	}

	// da li su paralelne?
	// (vy - uy) / (vx - ux) == (a[q] - a[p]) / (q - p)

	if ((vy - uy) * (q - p) == (a[q] - a[p]) * (vx - ux)) {

		cerr << ux << ' ' << vx << ' ' << p << ' ' << q << '\n';

		cout << "Yes\n";
		exit(0);
	}
}

void probaj(int i, int j) {
	ux = i;
	uy = a[i];
	vx = j;
	vy = a[j];
	// markiraj sve sto je kolinearno sa ove dve
	for (int k=1; k<=n; k++) {
		used[k] = det(i, a[i], j, a[j], k, a[k]) == 0;
	}

	probaj_ostalo();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] *= 2;
	}

	probaj(1, 2);
	probaj(2, 3);
	probaj(1, 3);

	cout << "No\n";
}