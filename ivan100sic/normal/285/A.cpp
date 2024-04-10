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
	iota(a, a+n, 1);
	reverse(a+n-k-1, a+n);
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}