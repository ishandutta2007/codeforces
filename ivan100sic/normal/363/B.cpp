#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[200005];
int z[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z[i+1] = z[i] + a[i];
	}
	int j = 0;
	int b = z[k];
	for (int i=0; i<n-k+1; i++) {
		if (z[i+k] - z[i] < b) {
			j = i;
			b = z[i+k] - z[i];
		}
	}
	cout << j+1 << '\n';
}