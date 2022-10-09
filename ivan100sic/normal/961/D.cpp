#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

bool kolin(pt a, pt b, pt c) {
	return det(a, b, c) == 0;
}

pt a[100005];
int n;

bool moze(pt b, pt c) {
	basic_string<pt> o;
	for (int i=0; i<n; i++) {
		if (!kolin(b, c, a[i]))
			o += a[i];
	}
	for (int i=2; i<(int)o.size(); i++)
		if (!kolin(o[0], o[1], o[i]))
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;

	// nadji neku koja nije kolin sa 0,1
	int j = -1;
	for (int i=2; i<n; i++)
		if (!kolin(a[0], a[1], a[i])) {
			j = i;
			break;
		}

	if (j == -1) {
		cout << "YES\n";
		return 0;
	}

	// probaj pravu kroz neke dve tacke
	bool ok = false;
	ok |= moze(a[0], a[1]);
	ok |= moze(a[0], a[j]);
	ok |= moze(a[1], a[j]);

	cout << (ok ? "YES\n" : "NO\n");
}