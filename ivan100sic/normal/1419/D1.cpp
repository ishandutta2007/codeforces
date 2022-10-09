// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, j;
int a[100005], b[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);

	for (int i=1; i<n; i+=2) {
		b[i] = a[j++];
	}

	cout << (n-1)/2 << '\n';

	for (int i=0; i<n; i+=2) {
		b[i] = a[j++];
	}

	for (int i=0; i<n; i++) {
		cout << b[i] << " \n"[i == n-1];
	}
}