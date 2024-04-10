#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1111115];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}

	int z = 0;
	for (int i=0; i<=1111111; i++) {
		a[i+1] += a[i] >> 1;
		z += a[i] & 1;
	}
	cout << z << '\n';
}