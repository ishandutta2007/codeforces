#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct stvar {
	int a11, a12, a22;

	stvar(int x = 0) {
		if (x == 0)
			a11 = a12 = a22 = 0;
		else if (x == 1)
			a11 = a12 = 1, a22 = 0;
		else
			a11 = 0, a12 = a22 = 1;
	}

	stvar(int x, int y, int z) : a11(x), a12(y), a22(z) {}

	stvar operator+ (const stvar& b) const {
		return {a11 + b.a11, max(a12 + b.a22, a11 + b.a12), a22 + b.a22};
	}
};

int n, sol;
int a[2005];
stvar b[2005], c[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b[i+1] = b[i] + a[i];
	}
	for (int i=0; i<n; i++)
		c[i+1] = stvar(a[n-i-1]) + c[i];
	int sol = 0;
	for (int i=0; i<n; i++) {
		stvar medju;
		for (int j=i+1; j<=n; j++) {
			medju = stvar(a[j-1]) + medju;
			sol = max(sol, (b[i] + medju + c[n-j]).a12);
		}
	}
	cout << sol << '\n';
}