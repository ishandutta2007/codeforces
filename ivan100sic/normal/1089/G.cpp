#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[7];

int probaj(int i, int k) {
	int br = accumulate(a, a+7, 0) * (k / 7);
	for (int j=i; j<i+k%7; j++)
		br += a[j % 7];
	return br;
}

int probaj(int k) {
	int z = 0;
	for (int i=0; i<7; i++)
		z = max(z, probaj(i, k));
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		for (int i=0; i<7; i++)
			cin >> a[i];

		int l = 0, r = 987987987, o = 0;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (probaj(m) >= k) {
				o = m;
				r = m-1;
			} else {
				l = m+1;
			}
		}
		cout << o << '\n';
	}	
}