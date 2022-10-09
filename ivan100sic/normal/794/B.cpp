#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	double h;

	cin >> n >> h;

	cout.precision(20);

	for (int i=1; i<n; i++) {
		double x = sqrt(i / (double)n) * h;
		cout << x << ' ';
	}
}