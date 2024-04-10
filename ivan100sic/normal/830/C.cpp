#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll k;
int a[105], rems[105], rises[105], snaga[105], d;
ll best;

int rm(int x, int d) {
	x %= d;
	if (x == 0)
		return 0;
	return d-x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);

	d = 1;
	best = 1;
	while (1) {
		// cerr << "d: " << d << '\n';
		if (d <= 100000) {
			// brute force it
			ll z = 0;
			for (int i=0; i<n; i++) {
				z += rm(a[i], d);
			}
			if (z <= k) {
				best = d;
			}
			d++;
		} else if (d <= a[n-1]) {
			int min_snaga = numeric_limits<int>::max();
			ll zbir_rems = 0, zbir_rises = 0;
			for (int i=0; i<n; i++) {
				rems[i] = rm(a[i], d);
				rises[i] = a[i] / d + 1;
				if (rises[i] == 1)
					snaga[i] = 123123123;
				else
					snaga[i] = (d - rems[i]) / rises[i] - 1;

				zbir_rises += rises[i];
				zbir_rems += rems[i];
				min_snaga = min(min_snaga, snaga[i]);
			}

			ll z = 0;
			for (int i=0; i<n; i++) {
				z += rems[i];
			}
			if (z <= k) {
				best = d;
			}

			ll q1 = (k - zbir_rems) / zbir_rises;

			// cerr << q1 << " " << min_snaga << '\n';
			// for (int i=0; i<n; i++)
			// 	cerr << snaga[i] << ' ';
			// cerr << "\n\n\n";

			if (q1 <= 1) {
				d += max(min_snaga, 1);
			} else {
				d += q1;
			}
		} else {
			break;
		}
	}

	// mozda neko resenje gde je d > a[n-1]?
	{
		ll zbir = accumulate(a, a+n, 0ll);
		ll baza = a[n-1]*1ll*n - zbir;
		if (baza <= k) {
			best = max<ll>(best, a[n-1] + (k-baza)/n);
		}
	}

	cout << best << '\n';
}

/*
100 1215752192
1 10000001 20000001 30000001 40000001 
50000001 60000001 70000001 80000001 90000001 
100000001 110000001 120000001 130000001 140000001 
150000001 160000001 170000001 180000001 190000001 
200000001 210000001 220000001 230000001 240000001 
250000001 260000001 270000001 280000001 290000001 
300000001 310000001 320000001 330000001 340000001 
350000001 360000001 370000001 380000001 390000001 
400000001 410000001 420000001 430000001 440000001 
450000001 460000001 470000001 480000001 490000001 
500000001 510000001 520000001 530000001 540000001 
550000001 560000001 570000001 580000001 590000001 
600000001 610000001 620000001 630000001 640000001 
650000001 660000001 670000001 680000001 690000001 
700000001 710000001 720000001 730000001 740000001 
750000001 760000001 770000001 780000001 790000001 
800000001 810000001 820000001 830000001 840000001 
850000001 860000001 870000001 880000001 890000001 
900000001 910000001 920000001 930000001 940000001 
950000001 960000001 970000001 980000001 990000001 

*/