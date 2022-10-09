#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll _b[100005], z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k;
	cin >> n >> k;

	// ako moze 0, gledamo koji negativni mogu
	ll* b = _b + 50003;

	for (int i=0; i<60; i++) {
		if (n & (1ll << i)) {
			b[i] = 1;
			z++;
		}
	}

	if (z > k) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";

	ll h = 50000;
	while (!b[h]) h--;

	while (z < k) {
		while (!b[h]) h--;

		b[h]--;
		b[h-1] += 2;
		z++;
	}

	while (!b[h]) h--;

	// ok sad imamo reprezentaciju gde je prvi broj najmanji moguc
	// sad nabudzi
	list<int> f;
	for (int i=50000; i>=-50000; i--)
		while (b[i]--)
			f.push_back(i);

	cerr << "h: " << h << '\n';

	auto it = f.begin();
	while (it != f.end()) {
		if (next(it) != f.end() && next(next(it)) != f.end()) {
			if (*next(it) == *it && *it < h) {
				f.insert(it, *it+1);
				it = f.erase(it);
				it = f.erase(it);
				if (next(it) == f.end()) {
					f.push_back(*it - 1);
					f.push_back(*it - 1);
					f.erase(it);
					break;
				} else {
					int q = f.back();
					f.pop_back();
					f.push_back(q - 1);
					f.push_back(q - 1);
				}
			} else {
				++it;
			}
		} else {
			++it;
		}
	}

	for (int x : f)
		cout << x << ' ';

}