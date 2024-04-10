#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	bool operator< (const pt& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
} a[100005], b[100005];
int n, k;

// da li ab sadrzi c (a.x != b.x)
bool tri(pt a, pt b, pt c) {
	if (a.x < b.x)
		swap(a, b);
	return c.y*(a.x-b.x) >= a.x*a.x*(b.x-c.x) + a.y*(c.x-b.x) -
		c.x*(b.y+b.x*c.x-b.x*b.x) + a.x*(b.y+c.x*c.x-b.x*b.x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a, a+n);

	for (int i=0; i<n; i++) {
		auto p = a[i];

		if (k > 0 && b[k-1].x == p.x)
			k--; // moze jedna samo
		while (k >= 2 && tri(b[k-2], b[k-1], p))
			k--;

		b[k++] = p;
	}
	cout << k-1 << '\n';
}