#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[300005], n, m;

bool moze(int w) {
	int last = 0;
	for (int i=0; i<n; i++) {
		// napravi najmanji broj koji je >= last
		if (a[i] < last) {
			if (a[i] + w < last) {
				return false;
			} // inace last ostaje isti
		} else {
			// ako mozes da dobacis do last, do it, inace nista
			if (a[i] + w >= last + m) {
				// super
			} else {
				last = a[i];
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	int l = 0, r = m, o = -1;
	while (l <= r) {
		int x = (l+r) >> 1;
		if (moze(x)) {
			o = x;
			r = x - 1;
		} else {
			l = x + 1;
		}
	}
	cout << o << '\n';
}