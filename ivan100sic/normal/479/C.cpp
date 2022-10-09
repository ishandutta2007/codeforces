#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dan {
	int x, y;
	bool operator< (const dan& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
} a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
	sort(a, a+n);
	int z = 0;
	for (int i=0; i<n; i++) {
		if (z <= a[i].y)
			z = a[i].y;
		else
			z = a[i].x;
	}
	cout << z << '\n';
}