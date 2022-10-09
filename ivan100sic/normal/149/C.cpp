#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	iota(b, b+n, 1);
	sort(b, b+n, cmp);
	cout << n/2 << '\n';
	for (int i=1; i<n; i+=2)
		cout << b[i] << ' ';
	cout << '\n' << (n+1)/2 << '\n';
	for (int i=0; i<n; i+=2)
		cout << b[i] << ' ';
	cout << '\n';
}