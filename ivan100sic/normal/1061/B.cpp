#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);

	ll zbir = accumulate(a, a+n, 0ll);

	int w = 1;
	int h = 1;

	for (int i=1; i<n; i++) {
		if (a[i] == a[i-1]) {
			w++;
			if (h < a[i])
				h++;
		} else { 
			w++;
			h++;
		}
	}
	w += a[n-1] - h;
	cout << zbir - w << '\n';
}