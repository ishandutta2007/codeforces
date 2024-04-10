#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[105];

void report(basic_string<int> sol) {
	cout << "Yes\n";
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
	exit(0);
}

void no() {
	cout << "No\n";
	exit(0);
}

basic_string<int> solve_kec(basic_string<int> a, int j, int k) {
	basic_string<int> sol;

	while (k > 1) {
		int x = a.back();
		a.pop_back();
		sol += {x, x};
		k--;
	}

	sol += j;
	for (int x : a)
		sol += {x, x};
	return sol + j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	int zb = 0, kec = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		zb += a[i];
		if (a[i] == 1)
			kec = i;
	}

	if (k <= 0)
		no();

	if (n == 1) {
		if (k != a[1]) 
			no();
		report(basic_string<int>(2*a[1], 1));
	}

	basic_string<int> sol;

	int lb = kec ? 1 : 2;
	if (k < lb || k > zb)
		no();

	if (kec) {
		// ako je kec samo cepaj
		basic_string<int> b;
		for (int i=1; i<=n; i++) {
			if (i != kec)
				b += basic_string<int>(a[i], i);
		}
		report(solve_kec(b, kec, k));
	} else {
		// podeli pametno na dva niza sa kecevima, resi posebno
		basic_string<int> b, c;
		for (int i=3; i<=n; i++) {
			b += basic_string<int>(a[i], i);
		}
		b += basic_string<int>(a[2]-1, 2);
		c += basic_string<int>(a[1]-1, 1);

		int kb = min(k-1, (int)b.size() + 1);
		int kc = k - kb;
		report(solve_kec(b, 1, kb) + solve_kec(c, 2, kc));
	}

	report(sol);
}