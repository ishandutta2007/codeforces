#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	if (n == k)
		return cout << -1, 0;

	iota(a, a+n, 1);
	rotate(a, a+1, a+(n-k));
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
}