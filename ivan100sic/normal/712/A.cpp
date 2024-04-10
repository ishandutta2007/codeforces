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
	for (int i=1; i<=n; i++)
		cin >> a[i];
	b[n] = a[n];
	for (int i=n-1; i>=1; i--)
		b[i] = a[i] + a[i+1];
	for (int i=1; i<=n; i++)
		cout << b[i] << ' ';
}