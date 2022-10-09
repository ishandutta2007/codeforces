// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct _in {
	template<class T>
	operator T() {
		T x;
		cin >> x;
		return x;
	}
} in;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t = in;
	while (t--) {
		int n = in;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			a[i] = in;
		int l = 0, r = n-1, p = 0, u = 0, v = 0;
		int last = 0;
		while (l <= r) {
			if (p % 2 == 0) {
				int e = 0;
				while (l <= r && e <= last) {
					e += a[l++];
				}
				u += e;
				last = e;
			} else {
				int e = 0;
				while (l <= r && e <= last) {
					e += a[r--];
				}
				v += e;
				last = e;
			}
			p += 1;
		}
		cout << p << ' ' << u << ' ' << v << '\n';
	}
}