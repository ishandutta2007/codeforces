#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

struct pica {
	ll s, a, b;
};

pica a[100005];
pica aa[100005];

ll pre, best;

ll total, pizzas;

void probaj(ll b_slices, ll a_slices) {

	if (b_slices < 0 || a_slices < 0) {
		return;
	}

	cerr << "b_slices: " << b_slices << '\n';
	cerr << "a_slices: " << a_slices << '\n';

	ll happy = 0;
	copy(a+1, a+n+1, aa+1);

	for (int i=1; i<=n; i++) {
		if (aa[i].b > aa[i].a) {
			ll amt = min(b_slices, aa[i].s);
			b_slices -= amt;
			aa[i].s -= amt;
			happy += amt * aa[i].b;
		}
	}

	cerr << "h1: " << happy << '\n';

	for (int i=n; i>=1; i--) {
		if (aa[i].b <= aa[i].a) {
			ll amt = min(a_slices, aa[i].s);
			a_slices -= amt;
			aa[i].s -= amt;
			happy += amt * aa[i].a;
		}
	}

	cerr << "h2: " << happy << '\n';

	// nazad

	for (int i=n; i>=1; i--) {
		if (aa[i].b > aa[i].a) {
			ll amt = min(a_slices, aa[i].s);
			a_slices -= amt;
			aa[i].s -= amt;
			happy += amt * aa[i].a;
		}
	}

	cerr << "h3: " << happy << '\n';

	for (int i=1; i<=n; i++) {
		if (aa[i].b <= aa[i].a) {
			ll amt = min(b_slices, aa[i].s);
			b_slices -= amt;
			aa[i].s -= amt;
			happy += amt * aa[i].b;
		}
	}

	cerr << "h4: " << happy << '\n';

	best = max(best, happy);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i].s >> a[i].a >> a[i].b;
		total += a[i].s;
	}

	pizzas = (total + k - 1) / k;

	sort(a+1, a+n+1, [](auto x, auto y){ return x.a-x.b < y.a-y.b; });

	ll prefer_b_total = 0;
	for (int i=1; i<=n; i++) {
		if (a[i].b > a[i].a) {
			prefer_b_total += a[i].s;
		}
	}

	ll base = prefer_b_total/k*k;

	probaj(base, k*pizzas - base);
	probaj(base + k, k*pizzas - base - k);

	cout << best;

}