#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ld dp[2][130000];

/*
9 .. 249 - toliko nula na kraju ima
inace, smanji 250

x & 511 su zadnjih 9 cifara
x >> 9 je broj uzastopnih pojavljivanja prve cifre iz maske
*/

int decode(int x) {
	int tz = __builtin_ctz(x);
	if (tz >= 9)
		return tz;

	int mask = x & 511;
	int r = x >> 8;
	int z = 1;
	while (z < 25 && (r&1) == ((r>>1)&1)) {
		r >>= 1;
		z++;
	}
	return 250 + z*512 + mask;
}

int advance0(int x) {
	if (x < 250)
		return x + 1;

	x -= 250;
	int mask = x & 511;
	int z = x >> 9;

	if (mask == 256)
		return 9;

	if (((mask >> 8) & 1) == ((mask >> 7) & 1))
		return 250 + (z+1)*512 + ((mask << 1) & 511);
	
	return 250 + 512 + ((mask << 1) & 511);
}

int advance1(int x) {
	if (x < 250) {
		return 250 + 512*(x-8) + 1;
	}

	x -= 250;
	int mask = x & 511;
	int z = x >> 9;

	if (mask == 255) {
		// mogu da se pravim da su iza nule, koga briga
		return 250 + 512 + mask+1;
	} else if (mask == 511) {
		return z + 8;
	} else {
		return 250 + z*512 + mask+1;
	}
}

int ctz(int x) {
	if (x < 250) {
		return x;
	}

	return __builtin_ctz((x-250) & 511);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x, k, perc;
	cin >> x >> k >> perc;

	dp[0][decode(x)] = 1;
	ld p = perc / 100.0, q = 1-p;

	cerr << advance0(decode(x)) << '\n';
	cerr << advance1(decode(x)) << '\n';

	for (int i=0; i<k; i++) {
		auto ol = dp[i%2];
		auto nu = dp[1-i%2];
		memset(nu, 0, sizeof(dp[0]));

		for (int a=0; a<130000; a++) {
			if (ol[a] == 0)
				continue;
			nu[advance0(a)] += ol[a] * p;
			nu[advance1(a)] += ol[a] * q;
		}
	}

	ld ex = 0;

	for (int a=0; a<130000; a++) {
		ld u = dp[k&1][a];
		if (u == 0)
			continue;
		// cerr << a << ' ' << u << ' ' << ctz(a) << '\n';
		ex += u * ctz(a);
	}

	cout << setprecision(20) << fixed << ex << '\n';
}