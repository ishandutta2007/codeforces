#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, l;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> l;
	for (int i=0; i<n*k; i++)
		cin >> a[i];
	sort(a, a+n*k);

	ll sol = 0;

	int bure = n-1;

	for (int i=n*k-1; i>=0; i--) {
		if (a[i] <= a[0] + l && i <= bure*k) // burek hehe
		{
			// cerr << "~ " << i << '\n';
			sol += a[i];
			bure--;
		}
	}

	if (bure != -1)
		sol = 0;

	cout << sol << '\n';
}