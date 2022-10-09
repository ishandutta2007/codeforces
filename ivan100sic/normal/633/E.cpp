#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int v[1000005];
int c[1000005];
ll b[1000005];

struct stvar {
	int val, lo, hi;
};

struct cuvar {
	vector<stvar> levi, desni;

	void dodaj(vector<stvar>& v, int x) {
		int l = v.size() ? min(v.back().lo, x) : x;
		int h = v.size() ? max(v.back().hi, x) : x;
		v.push_back({ x, l, h });
	}

	void push(int x) {
		dodaj(desni, x);
	}

	void reverse() {
		while (desni.size()) {
			dodaj(levi, desni.back().val);
			desni.pop_back();
		}
	}

	void pop() {
		if (!levi.size()) {
			reverse();
		}
		if (levi.size()) {
			levi.pop_back();
		}
	}

	stvar get() {
		int l = +1123123123;
		int h = -1123123123;
		if (levi.size()) {
			l = min(l, levi.back().lo);
			h = max(h, levi.back().hi);
		}
		if (desni.size()) {
			l = min(l, desni.back().lo);
			h = max(h, desni.back().hi);
		}
		return { 0, l, h };
	}
};

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	cuvar ev, ec;
	int r = 0;
	for (int l = 1; l <= n; l++) {
		ll sol = 0;
		{
			auto xv = ev.get();
			auto xc = ec.get();
			sol = max(sol, min(xv.hi * 100ll, xc.lo * 1ll));
		}

		if (r < l - 1) {
			r = l - 1;
		}

		while (r < n) {
			// dodaj
			ll xv = max(ev.get().hi, v[r + 1]);
			ll xc = min(ec.get().lo, c[r + 1]);
			sol = max(sol, min(xv * 100ll, xc * 1ll));
			if (xv * 100ll > xc) {
				// uzmi i prekini
				break;
			}
			else {
				r++;
				ev.push(v[r]);
				ec.push(c[r]);
			}
		}

		b[l] = sol;
		ev.pop();
		ec.pop();
	}

	double prob = k * 1.0 / n;
	double sol = 0;
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		// cerr << b[i] << ' ';
		if (i > 1) {
			prob *= n - k - i + 2;
			prob /= n - i + 1;
		}
		// cerr << prob << '\n';
		sol += prob * b[i];
	}
	cout.precision(20);
	cout << fixed << sol << '\n';

}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}