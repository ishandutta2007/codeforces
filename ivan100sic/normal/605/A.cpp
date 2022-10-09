#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	int y = 0, z = 0;
	for (int i=1; i<=n; i++) {
		if (b[i] > b[i-1]) {
			y++;
		} else {
			y = 1;
		}
		z = max(z, y);
	}
	cout << n - z << '\n';
}