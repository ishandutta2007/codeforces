#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n-1; i++)
		b[i] = a[i+1] - a[i] - 1;
	sort(b, b+n-1);
	cout << a[n-1] - a[0] + 1 - accumulate(b+n-k, b+n-1, 0) << '\n';
}