#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int l[305], c[305];

void mn(int& x, int y) {
	if (!x)
		x = y;
	else
		x = min(x, y);
}

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<int, int> ol = {{0, 0}};
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> l[i];
	for (int i=0; i<n; i++)
		cin >> c[i];

	for (int i=0; i<n; i++) {
		map<int, int> nu = ol;
		for (auto p : ol) {
			mn(nu[gcd(p.first, l[i])], p.second + c[i]);
		}
		swap(ol, nu);
	}
	int x = ol[1];
	cout << x-!x << '\n';
}