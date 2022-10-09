#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
int a[100005];

struct tree {
	double b[100005];

	double get(int n) {
		double z = 0;
		while (n > 0) {
			z += b[n];
			n -= n & -n;
		}
		return z;
	}

	void add(int n, double x) {
		while (n < 100005) {
			b[n] += x;
			n += n & -n;
		}
	}
};

tree cnt, add;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] = n + 1 - a[i];
	}

	double total = 0.0;
	double inv = 0.0;

	for (int j=1; j<=n; j++) {
		total += add.get(a[j] - 1) * (n-j+1);
		inv += cnt.get(a[j] - 1);
		
		add.add(a[j], j);
		cnt.add(a[j], 1);
	}

	total /= n*(n+1.0) / 2;
	double dodati = (n-1.0) * (n+2.0) / 24.0;

	cout.precision(26);
	cout << fixed << (inv - total + dodati);

}