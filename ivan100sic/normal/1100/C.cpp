#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	double n, r;
	cin >> n >> r;

	double c = sin(3.14159265358979 / n);
	double rr = c / (1 - c);
	cout.precision(20);
	cout << fixed << r*rr << '\n';
}