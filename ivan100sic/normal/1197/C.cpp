#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[300005], b[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n-1; i++)
		b[i] = a[i+1] - a[i];
	sort(b, b+n-1, greater<int>());
	cout << a[n-1]-a[0]-accumulate(b, b+k-1, 0) << '\n';
}