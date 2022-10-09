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

	vector<bool> b(64000005);

	while (t--) {
		int n = in;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			a[i] = in;
		for (int i=0; i<n; i++) {
			int z = a[i];
			for (int j=i+1; j<n; j++) {
				z += a[j];
				b[z] = 1;
			}
		}

		int u = 0;
		for (int x : a)
			u += b[x];
		cout << u << '\n';

		for (int i=0; i<n; i++) {
			int z = a[i];
			for (int j=i+1; j<n; j++) {
				z += a[j];
				b[z] = 0;
			}
		}
	}
}