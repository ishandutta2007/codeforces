#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int z = 0, t = 0;
	while (t < n) {
		z++;
		t++;
		int h = a[t];
		while (h > t) {
			t++;
			h = max(h, a[t]);
		}
	}
	cout << z << '\n';
}