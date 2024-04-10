#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(x) (cerr << "ln " << __LINE__ << ": " << #x << " = " << (x) << '\n')
#else
#define dbg(x) {}
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int x[300005], y[300005];

int resi(int k) {
	basic_string<pair<int, int>> iznad, ispod;
	int q = 0;
	for (int i=0; i<n; i++) {
		if (i != k) {
			if (y[i] > y[k]) {
				iznad += {x[i] - x[k], y[i] - y[k]};
			} else {
				ispod += {x[i] - x[k], y[k] - y[i]};
			}
		}
	}
	// iznad samo?
	{
		int r1 = 0, r2 = 0;
		for (auto p : iznad) {
			r1 = max(r1, p.first);
			r2 = max(r2, p.second);
		}
		q = max(q, r1 + r2);
	}

	dbg(q);

	{
		int r1 = 0, r2 = 0;
		for (auto p : ispod) {
			r1 = max(r1, p.first);
			r2 = max(r2, p.second);
		}
		q = max(q, r1 + r2);
	}

	dbg(q);

	sort(iznad.begin(), iznad.end());
	sort(ispod.begin(), ispod.end());
	// cross 1
	{
		int j = -1;
		int r2 = 0;
		for (int i=0; i<(int)iznad.size(); i++) {
			while (j+1 < (int)ispod.size() && ispod[j+1].first <= iznad[i].first) {
				r2 = max(r2, ispod[j+1].second);
				j++;
			}
			q = max(q, iznad[i].second + r2 + iznad[i].first);
		}
	}

	dbg(q);

	// cross 2
	swap(iznad, ispod);
	{
		int j = -1;
		int r2 = 0;
		for (int i=0; i<(int)iznad.size(); i++) {
			while (j+1 < (int)ispod.size() && ispod[j+1].first <= iznad[i].first) {
				r2 = max(r2, ispod[j+1].second);
				j++;
			}
			q = max(q, iznad[i].second + r2 + iznad[i].first);
		}
	}

	dbg(q);

	return q;
}

int resi() {
	int me = *min_element(x, x+n), q = 0;
	for (int i=0; i<n; i++) {
		if (x[i] == me) {
			q = max(q, resi(i));
		}
	}
	return q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> x[i] >> y[i];
	int p = *max_element(x, x+n) - *min_element(x, x+n);
	p += *max_element(y, y+n) - *min_element(y, y+n);
	int q = 0;
	for (int i=0; i<4; i++) {
		for (int j=0; j<n; j++) {
			int t = x[j];
			x[j] = -y[j];
			y[j] = t;
		}
		q = max(q, resi());
	}

	cout << 2*q << ' ';
	for (int i=4; i<=n; i++)
		cout << 2*p << ' ';
	cout << '\n';
}