// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, h;
int a[200005];
ll z[400005], s;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	h = n/2+1;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<2*n; i++) {
		int x = a[(2*i)%n];
		z[i+1] = z[i] + x;
	}
	for (int i=0; i<n; i++) {
		s = max(s, z[i+h] - z[i]);
	}

	cout << s << '\n';
}