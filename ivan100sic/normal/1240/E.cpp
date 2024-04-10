#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 500000;

int n;
ll sol = 4;
int a[500005], c[500005], z[500005];

// dva najbliza ostatka
int d1[500005], d2[500005];
ll sumkol;

struct stvar {
	int x, x1, x2;
};

vector<stvar> prostaci;

void zapocni(int y) {
	sumkol = 0;
	for (int i=1;; i++) {
		int r = y*i+y-1, l = r-y;
		r = min(r, H);
		sumkol += 1ll*i*(z[r]-z[l]);
		if (r == H)
			break;
	}

	vector<int> ostaci;
	for (int i=y-1; i/y<H/y; i+=y) {
		if (d1[i] >= i-y+1)
			ostaci.push_back(d1[i]);
		if (d2[i] >= i-y+1)
			ostaci.push_back(d2[i]);
	}

	if (d1[H] >= H/y*y)
		ostaci.push_back(d1[H]);

	if (d2[H] >= H/y*y)
		ostaci.push_back(d2[H]);

	sort(ostaci.begin(), ostaci.end(), greater<int>());
	int k = ostaci.size();
	prostaci.resize(k);
	for (int i=0; i<k; i++) {
		int x = ostaci[i];
		prostaci[i].x = x;
		if (i > 0) {
			prostaci[i].x1 = prostaci[i-1].x1;
			prostaci[i].x2 = prostaci[i-1].x2;
		} else {
			prostaci[i].x1 = -1;
			prostaci[i].x2 = -1;
		}

		if (x % y > prostaci[i].x1 % y) {
			prostaci[i].x2 = prostaci[i].x1;
			prostaci[i].x1 = x;
		} else if (x % y > prostaci[i].x2 % y) {
			prostaci[i].x2 = prostaci[i].x;
		}
	}
}

bool moze(int x, int y) {
	if (prostaci.size() == 0)
		return false;
	int l = 0, r = prostaci.size()-1, o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (prostaci[m].x >= x) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	if (o == -1)
		return false;

	ll rafts = sumkol;
	int x1 = prostaci[o].x1, x2 = prostaci[o].x2;

	rafts -= x1/y - (x1-x)/y;
	x1 -= x;
	if (x1 < x) {
		x1 = x2;
	} else if (x2 >= x && x2 % y > x1 % y) {
		x1 = x2;
	}

	if (x1 < x)
		return false;
	rafts -= x1/y - (x1-x)/y;
	return rafts >= x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	d1[0] = d2[0] = -1;
	for (int j=1; j<=H; j++) {
		z[j] = z[j-1] + c[j];
		d1[j] = d1[j-1];
		d2[j] = d2[j-1];
		
		if (c[j] >= 1) {
			d2[j] = d1[j];
			d1[j] = j;
		}

		if (c[j] >= 2) {
			d2[j] = d1[j];
			d1[j] = j;
		}
	}


	int x = 2;
	for (int y=H; y>=2; y--) {
		zapocni(y);
		if (moze(x, y)) {
			while (moze(x+1, y))
				x++;
			// cerr << "moze " << x << ' ' << y << " (" << sumkol << ")\n";
			sol = max(sol, x*1ll*y);
		}
	}

	cout << sol << '\n';
}