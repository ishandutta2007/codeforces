#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y, id;
	bool operator< (const pt& b) const {
		int xblok = x / 1000;
		int bxblok = b.x / 1000;
		if (xblok != bxblok)
			return xblok < bxblok;
		if (xblok & 1)
			return y < b.y;
		else
			return y > b.y;
	}
} a[1000005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i+1;
	}
	sort(a, a+n);
	for (int i=0; i<n; i++)
		cout << a[i].id << ' ';
	cout << '\n';
}