#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int suma = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		suma += x;
	}

	cout << max(0, 2*n*k-n-2*suma);

}