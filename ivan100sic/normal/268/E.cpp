#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
struct song {
	ld l, p;

	bool operator< (song b) const {
		return l*p*(b.p-1) > b.l*b.p*(p-1);
	}
} a[50005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].l >> a[i].p;
		a[i].p /= 100;
	}

	sort(a, a+n);
	
	ld z = 0, y = 0;
	for (int i=0; i<n; i++) {
		z += a[i].l + y*a[i].p*a[i].l;
		y += 1 - a[i].p;
	}
	cout << setprecision(20) << fixed << z << '\n';
		
}