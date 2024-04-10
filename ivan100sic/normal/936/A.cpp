#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) (cerr << "ln " << __LINE__ << ": " << #x << " = " << (x) << '\n')
#else
#define dbg(x) {}
#endif

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll k, d, t;
	cin >> k >> d >> t;

	cout.precision(20);

	t *= 2;

	// umnozak broja d koji je veci ili jednak k
	{
		ll z = k / d * d;
		if (z < k) {
			z += d;
		}
		d = z;
	}

	ll jedan = 2*k + (d-k);

	double sol = 0.0;
	ll punkrug = t / jedan;

	t -= punkrug * jedan;
	sol += punkrug * d;

	if (t <= 2*k) {
		sol += (double)t / 2;
	} else {
		sol += k;
		t -= 2*k;
		sol += t;
	}

	cout << fixed << sol << '\n';


}