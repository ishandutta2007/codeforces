#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int h = *max_element(a, a+n);
	int w=0, z=0;
	for (int i=0; i<n; i++) {
		if (a[i] == h) {
			w++;
		} else {
			w = 0;
		}
		z = max(z, w);
	}
	cout << z << '\n';
}