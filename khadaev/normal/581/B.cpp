#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, h[110000], m[110000];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> h[i];
	int M = 0;
	for (int i = n - 1; i >= 0; --i) {
		M = max(M, h[i]);
		m[i] = M;
		};
	for (int i = 0; i < n - 1; ++i)
		if (h[i] > m[i+1]) cout << 0 << " ";
		else cout << (m[i+1] + 1 - h[i]) << " ";
	cout << 0 << endl;
}